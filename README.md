# Monarch2090

Eine Simulation des legendären Spielautomaten Rotomat Monarch (1972) auf dem Microtronic 2090 (1981)

Wozu dieses Projekt?

I.

In den 70er-Jahren waren sog. elektromechanische Spielautomaten in Kneipen und Restaurants weit verbreitet. Spielhallen gab es damals - zum Glück - noch nicht. Die Ablaufsteuerung dieser Automaten erfolgte über eine motorgetriebene, langsam rotierende Nockenwelle, an der Kontaktfedern zum jeweils richtigen Zeitpunkt Kontakte öffneten und schlossen - ganz ohne Computer konnten so komplexe Spielsysteme realisiert werden. Und anders als bei den kurz darauf aufkommenden computergesteuerten Spielautomaten war das Ergebnis tatsächlich noch "zufällig", da der Lauf der drehenden Walzen nicht deterministisch bestimmt war. Im Vertrauen auf das Gesetz der großen Zahl haben die Automatenaufsteller dennoch gut verdient, nur mindestens 75% der Einsätze mussten (wahrscheinlichkeitstheoretisch) als Gewinne wieder ausgeworfen werden. 

Der erfolgreichste Vertreter dieser Generation von Spielautomaten war der "Rotomat Monarch" von der Firma Günter Wulff Apparatebau in Berlin, der 1972 auf den Markt kam - mit der sagenhaften Stückzahl von über 30.000 Geräten. Wegen der restriktiven Glücksspiel-Gesetzgebung musste ein Spiel mindestens 15 Sekunden dauern, der Höchsteinsatz pro Spiel lag bei 20 Pf und der Höchstgewinn betrug 2 DM. Um diese Einschränkung formal einzuhalten und doch zu umgehen, haben die Automatenbauer sich etwas geradezu geniales einfallen lassen: Sonderspiele. Auch in diesen Spielen konnte man maximal 2 DM gewinnen, aber die Wahrscheinlichkeit für diesen Höchstgewinn lag während dieser Sonderspiele bedeutend höher (mehr als 50%). 



II.



Der Kreis derjenigen, die ebenfalls vom 2090 fasziniert waren (und womöglich noch sind), dürfte ohnehin überschaubar sein. Wenn man dann noch die Schnittmenge bildet mit denjenigen, die bei elektromechanischen Spielautomaten ins Schwärmen geraten, wäre eine Abschätzung der verbleibenden Interessengruppe inetwa mit der Größe 1 zu beziffern - also bin ich wohl alleine :-) Aber egal, andere lösen Kreuzworträtsel. 



Zufallszahlen im 2090

Der Microtronic 2090 hat einen Befehl zur Ermittlung einer 3-stelligen hexadezimalen Zufallszahl - RND (F05). Faktisch wird dabei der Zählerstand eines internen Zählers zur Tastaturabfrage ausgelesen und in die Arbeitsregister D, E und F übertragen. Solange im Programm immer mal wieder auf eine Benutzereingabe mit KIN (FFd) gewartet wird, ist das auch kein Problem, da das nötige zufällige Element in der Dauer der Wartezeit auf den Benutzerfinger begründet liegt, mithin ist der Zufallswert hinreichend zufällig. Wenn aber das Programm automatisiert und ohne Benutzereingaben abläuft (und das soll der Spielautomat ja), dann ergibt sich das Problem, dass der interne Zähler und das Programm synchron laufen - wodurch sich immer wieder feste Folgen in der Abarbeitung des Programms ergeben. Als kleiner Junge war mir dieser Zusammenhang nicht klar, ich wunderte mich nur darüber, dass mein "Krieg der Sterne"-Programm mich deutlich öfter als theoretisch erwartet gewinnen ließ. 

Kurz: der Zufall ist nicht zufällig. 



Timing des Arduino/Raspi

Der 2090 ist nicht schnell. Michael Wessel hat ein paar Performance-Tests durchgeführt und als Ergebnis maximal 114 Operationen pro Sekunde (1,14 HIPS) ermittelt. Da in meinem Programm das Display meistens aktiv ist, dürfte eher ein Wert von 40 Instructions per second (0,4 HIPS) zu erwarten sein. Welche Dauer der Befehl zum Einlesen der 4 Bits an den Eingängen KIN (FDd) beansprucht und wie er ausgeführt wird (sequentiell, parallel, quantenmechanisch o.ä.), ist im Detail nicht bekannt, aber es ist klar, dass Timing ein Faktor sein kann. Wenn die Peripherie die Zufallszahlen zu langsam liefert, wird der gleiche Wert mehrfach im Programm eingelesen, wenn die Zufallszahlen hingegen zu schnell geliefert werden, wird der Wert während des Einlesens möglicherweise "verschmiert", da sich die Bits während des Einlesevorgangs durch eine in der Zwischenzeit neu erzeugte Zufallszahl verändern.

Eine Lösung, um Timing-Probleme zu vermeiden, wäre: Immer wenn ein Zufallszahl benötigt wird, geben wir dem Zahlen-Lieferanten ein Signal. Der Raspudino erzeugt die Zahl dann, liefert sie über GPIO an die Eingänge des 2090, hält sie da ausreichend lange stabil und wartet dann einfach auf die nächste Zahlen-Bestellung. Das erforderte aber zusätzliche Befehle im Programmcode (Wert in Register speichern, Register auf Ausgang legen, ggf. warten auf die Verarbeitung). Und ein extra Kabel. Und ein wertvolles Register - wir haben nur 16 Stück brauchbare. Nope, scheidet (erstmal) aus.

Testen ist am besten.

Zur Überprüfung meiner Überlegungen und zur Ermittlung des richtigen/besten Lieferintervalls für Zufallszahlen habe ich ein bisschen mit ChatGPT geplaudert und wir haben uns auf folgendes Python-Programm (für den Raspi) geeinigt. Meine prgrammtechnische Eigenleistung bestand darin, die richtigen GPIOs einzutragen. 


Annahmen

What if? Zahlen von 0-9 werden geliefert. Aber werden sie auch eingelesen? ASSERT gibt es im Microtronic Befehlssatz nicht. Im Programmcode wird auf das letzte CMPI verzichtet, weil andernfalls "es ja eine Null/Neun sein muss". Aber was wenn nicht? 
