# Monarch2090

Eine Simulation des legendären Spielautomaten Rotomat Monarch (1972) auf dem Microtronic 2090 (1981)

## Was soll das Ganze?

I.

In den 70er-Jahren waren sog. elektromechanische Spielautomaten in Kneipen und Restaurants weit verbreitet. Spielhallen gab es damals - zum Glück - noch nicht. Die Ablaufsteuerung dieser Automaten erfolgte über eine motorgetriebene, langsam rotierende Nockenwelle, an der Kontaktfedern zum jeweils richtigen Zeitpunkt Strompfade öffneten und schlossen - ganz ohne Computer konnten so komplexe Spielsysteme realisiert werden. Und anders als bei den kurz darauf aufkommenden computergesteuerten Spielautomaten war das Ergebnis tatsächlich noch "zufällig", da der Lauf der drehenden Walzen nicht deterministisch vorherbestimmt war. Im Vertrauen auf das Gesetz der großen Zahl haben die Automatenaufsteller dennoch gut verdient, nur 75% der Einsätze mussten (wahrscheinlichkeitstheoretisch) als Gewinne mindestens wieder ausgeworfen werden. 

Der erfolgreichste Vertreter dieser Generation von Spielautomaten war der **Rotomat Monarch** von der Firma Günter Wulff Apparatebau in Berlin, der 1972 auf den Markt kam - mit der sagenhaften Stückzahl von über 30.000 Geräten. Wegen der restriktiven Glücksspiel-Gesetzgebung musste ein Spiel mindestens 15 Sekunden dauern, der Höchsteinsatz pro Spiel lag bei 20 Pf und der Höchstgewinn betrug 2 DM. Um diese gesetzlichen Vorgaben formal einzuhalten und doch zu umgehen, haben die Automatenbauer sich etwas geradezu geniales einfallen lassen: **Sonderspiele**. Auch in diesen Spielen konnte man maximal 2 DM gewinnen, aber die Wahrscheinlichkeit für diesen Spielgewinn lag während der Sonderspiel-Dauer bedeutend höher (mehr als 50%). Wenn man den _höchst seltenen Fall_ erlebte, dass der Automat den Höchstgewinn von 50 Sonderspielen gab, konnten - unter völliger Einhaltung der gesetzlichen Bestimmungen - so aus 20 Pf mehr als 50 DM werden (50 mal Erwartungswert von ca. 1 DM). Eine Menge Geld im Jahr 1972, inflationsbereinigt über 100 Euro heute.

Neben dem Reiz, den die Aussicht auf Spielgewinne auf die meisten Menschen schon immer ausgeübt hat, war die Geräuschkulisse solcher Automaten wirklich faszinierend. Ein ständiges Rattern und Klingeln. Auch die Optik der Geräte ist ein schöner Spiegel der Zeit. Allerdings durften diese Geräte nur 3 Jahre lang im Einsatz sein, danach mussten sie aus dem Verkehr gezogen werden und waren eigentlich Elektroschrott. Sie wurden dann bestenfalls an Privatpersonen verkauft und hingen oft als bessere Spardose in Partykellern. Mit der Euro-Einführung waren diese Geräte dann wirklich nutzlos geworden und wurden an Selbstabholer (Gewicht über 40 Kilo!) über eBay vertickt. Auch heute noch sind solche Automaten mühelos zu bekommen und mit etwas technischem Geschick lassen sie sich sogar auf die Annahme von Euro und Cent umrüsten. Aber Vorsicht, im Inneren sind praktisch überall 230 Volt. Das kann lebensgefährlich tödlich sein!

II.

Wie gerne hätte ich damals auch so einen Automaten in meinem Zimmer gehabt! Aber eBay gab´s damals nicht und offenbar kannte ich nicht die richtigen Leute. Matthias hatte einen "Rotomat Trianon" und Jürgen hatte einen "Rotomat Exquisit Gold". Aber ich hatte... zuerst ein Yps-Radio für 6,50 DM, dann zu Weihnachten einen Philips EE2050 Elektronik-Baukasten, danach schrittweise die ganze Serie Baukästen von Busch und schließlich - den **Microtronic 2090**. Ein Lerncomputer, mit dem man selbst programmieren (lernen) konnte. Irgendwann reifte der kühne Plan: 

### Ich programmiere mir meinen Automaten selbst!



Der Kreis derjenigen, die ebenfalls einen 2090 hatten (und womöglich noch haben), dürfte ohnehin überschaubar sein. Wenn man dann noch die Schnittmenge bildet mit denjenigen, die bei elektromechanischen Geldspielgeräten ins Schwärmen geraten, wäre eine Abschätzung der verbleibenden Interessengruppe inetwa mit der Größe 1 zu beziffern - also bin ich wohl alleine :-) Aber egal, andere lösen Kreuzworträtsel. Oder Sudoku. Also hier nun mein Programm...





## Zufallszahlen im 2090

Der Microtronic 2090 hat einen Befehl zur Ermittlung einer 3-stelligen hexadezimalen Zufallszahl - RND (F05). Faktisch wird dabei der Zählerstand eines internen Zählers zur Tastaturabfrage ausgelesen und in die Arbeitsregister D, E und F übertragen. Solange im Programm immer mal wieder auf eine Benutzereingabe mit KIN (FFd) gewartet wird, ist das auch kein Problem, da das nötige zufällige Element in der Dauer der Wartezeit auf den Benutzerfinger begründet liegt, mithin ist der Zufallswert hinreichend zufällig. Wenn aber das Programm automatisiert und ohne Benutzereingaben abläuft (und das soll der Spielautomat ja), dann ergibt sich das Problem, dass der interne Zähler und das Programm synchron laufen - wodurch sich immer wieder feste Folgen in der Abarbeitung des Programms ergeben. Als kleiner Junge war mir dieser Zusammenhang nicht klar, und ich wunderte mich damals nur darüber, dass mein "Krieg der Sterne"-Programm mich deutlich öfter als theoretisch erwartet gewinnen ließ. 

Kurz: der Zufall ist nicht zufällig. 

Michael Wessel hat mich darauf aufmerksam gemacht, dass ein anderer zu dieser Zeit ebenfalls erhältlicher Lerncomputer seine "Zufallszahlen" einfach durch obskure Verdrahtung seiner Aus- und Eingänge generiert. Worauf ich versprach, dass ich mich nie wieder über den RND-Befehl des 2090 beschweren wolle. Gleichwohl brauchte ich für mein Programm einen *zufälligeren Zufall*, sonst isses halt einfach zu langweilig. 

Eine Möglichkeit wäre natürlich, nach jeder zufälligen Aktion auf eine Benutzerreaktion zu warten (s.o.) - aber das würde den Charme der Simulation zerstören. Opa Erwin musste 1972 in der Gaststätte "Zu den drei Hasen" auch nicht nach jedem Walzenstopp irgendwas drücken, damit es weiterging. Er warf einfach einen Heiermann ein (5-Mark-Stück für die jüngeren unter uns, der Monarch war der erste Automat, der auch diese Münzen begierig schluckte) und setzte sich wieder an seinen Tisch, während die Kiste von alleine weiterlief und gelegentlich durch einen charakteristischen Türgong auf einen Gewinn aufmerksam machte.

## Peripherie muss her

Der erste Gedanke war, den Baukasten 2075 zu nutzen. Damit wäre ich auch schön im Busch-Universum geblieben. Theoretisch ein Rauschen auf den Takteingang des Zählerbausteins und seine Ausgänge A-D dann auf die Eingänge des 2090 legen. Aber... ich konnte ihn im Keller nicht mehr finden. Irgendwie hat meine Busch-Kiste einen der letzten Umzüge nicht überlebt oder wurde aus dem Keller geklaut. Falls letzteres, wer tut sowas? Möge der Blitz dich bei was-auch-immer treffen. Das ist ein echter Verlust für mich :-(((



## Timing des Arduino/Raspi

Der 2090 ist nicht schnell. Michael hat ein paar [Performance-Tests](https://www.youtube.com/watch?v=e8KJ-cnX9bU) durchgeführt und als Ergebnis maximal 114 Operationen pro Sekunde (1,14 HIPS) ermittelt. Da in meinem Programm das Display meistens aktiv ist, dürfte eher ein Wert von 40 Instructions per second (0,4 HIPS) zu erwarten sein. Welche Dauer der Befehl KIN (FDd) zum Einlesen der 4 Bits an den Eingängen beansprucht und wie er ausgeführt wird (sequentiell, parallel, quantenmechanisch o.ä.), ist im Detail nicht bekannt, aber es ist klar, dass Timing ein Faktor sein kann. Wenn die Peripherie die Zufallszahlen zu langsam liefert, wird der gleiche Wert mehrfach im Programm eingelesen, wenn die Zufallszahlen hingegen zu schnell geliefert werden, wird der Wert während des Einlesens möglicherweise "verschmiert", da sich die Bits durch eine in der Zwischenzeit neu erzeugte Zufallszahl verändern können. Dieser zweite Fall wird noch ein richtiges Problem, dazu später...

Eine saubere Lösung, um Timing-Probleme zu vermeiden, wäre: Immer wenn ein Zufallszahl benötigt wird, geben wir dem Zahlen-Lieferanten ein Signal. Der Raspuino erzeugt die Zahl, liefert sie über seine GPIO an die Eingänge des 2090, hält sie da ausreichend lange stabil und wartet dann einfach auf die nächste Zahlen-Bestellung. Das erforderte aber zusätzliche Befehle im Programmcode des 2090 (Wert in Register speichern, Register auf Ausgang legen, ggf. warten auf die Verarbeitung). Und ein extra Kabel. Und ein wertvolles Register - wir haben nur 16 Stück brauchbare. Nope, scheidet (erstmal) aus.

## Testen ist am besten

Zur Überprüfung meiner Überlegungen und zur Ermittlung des richtigen/besten Lieferintervalls für Zufallszahlen habe ich ein bisschen mit ChatGPT geplaudert und wir haben uns auf folgendes Python-Programm (für den Raspi) geeinigt. Meine programmiertechnische Eigenleistung bestand darin, die richtigen GPIOs einzutragen. 


### Annahmen

What if? Zahlen von 0-9 werden geliefert. Aber werden sie auch eingelesen? ASSERT gibt es im Microtronic Befehlssatz nicht. Im Programmcode wird auf das letzte CMPI verzichtet, weil andernfalls "es ja eine Null/Neun sein muss". Aber was wenn nicht? 
