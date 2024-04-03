# Monarch2090

Eine Simulation des legendären Spielautomaten Rotomat Monarch (1972) auf dem [Microtronic 2090](https://www.busch-modell.de/information/Microtronic-Computer.aspx) (1981)

## Was soll das Ganze?

I.

In den 70er-Jahren waren sog. elektromechanische Spielautomaten in Kneipen und Restaurants weit verbreitet. Spielhallen gab es damals - zum Glück - noch nicht. Die Ablaufsteuerung dieser Automaten erfolgte über eine motorgetriebene, langsam rotierende Nockenwelle, an der Kontaktfedern zum jeweils richtigen Zeitpunkt Strompfade öffneten und schlossen - ganz ohne Computer konnten so komplexe Spielsysteme realisiert werden. Und anders als bei den kurz darauf aufkommenden computergesteuerten Spielautomaten war das Ergebnis tatsächlich noch "zufällig", da der Lauf der drehenden Walzen nicht deterministisch vorherbestimmt war. Im Vertrauen auf das Gesetz der großen Zahl haben die Automatenaufsteller dennoch gut verdient, nur 75% der Einsätze mussten (wahrscheinlichkeitstheoretisch) als Gewinne mindestens wieder ausgeworfen werden. 

Der erfolgreichste Vertreter dieser Generation von Spielautomaten war der [**Rotomat Monarch**](http://www.rd-b.de/html/wulff_rotomat_monarch.html) von der Firma Günter Wulff Apparatebau in Berlin, der 1972 auf den Markt kam - mit der sagenhaften Stückzahl von über 30.000 Geräten. Wegen der restriktiven Glücksspiel-Gesetzgebung musste ein Spiel mindestens 15 Sekunden dauern, der Höchsteinsatz pro Spiel lag bei 20 Pf und der Höchstgewinn betrug 2 DM. Um diese gesetzlichen Vorgaben formal einzuhalten und doch tricky-tricky zu umgehen, haben die Automatenbauer sich etwas geradezu Geniales einfallen lassen: **Sonderspiele**. Auch in diesen Spielen konnte man maximal 2 DM gewinnen, aber die Wahrscheinlichkeit für diesen Spielgewinn lag während der Sonderspiel-Dauer bedeutend höher (mehr als 50%). Wenn man den _höchst seltenen Fall_ erlebte, dass der Automat den Höchstgewinn von 50 Sonderspielen gab, konnten - unter völliger Einhaltung der gesetzlichen Bestimmungen - so aus 20 Pf mehr als 50 DM werden (50 mal Erwartungswert von ca. 1 DM). Eine Menge Geld im Jahr 1972, inflationsbereinigt über 100 Euro heute.

Neben dem Reiz, den die Aussicht auf Geldgewinne für viele Menschen darstellt, war die [Geräuschkulisse solcher Automaten](https://www.youtube.com/watch?v=yDXITgWsWbw) wirklich faszinierend. Ein ständiges Rattern und Klingeln. Auch die Optik der Geräte ist ein schöner Spiegel der Zeit. Allerdings durften diese Maschinen nur 3 Jahre lang gewerblich im Einsatz sein, danach mussten sie aus dem Verkehr gezogen werden und waren eigentlich Elektroschrott. Sie wurden dann bestenfalls an Privatpersonen verkauft und hingen oft als bessere Spardose in Partykellern. Mit der Euro-Einführung waren diese Geräte dann wirklich nutzlos geworden und wurden an Selbstabholer (Gewicht über 40 Kilo!) über eBay vertickt. Auch heute noch sind solche Automaten mühelos zu bekommen und mit etwas technischem Geschick lassen sie sich sogar auf die Annahme von Euro und Cent umrüsten. Aber Vorsicht, im Inneren sind praktisch überall 230 Volt. Das kann lebensgefährlich tödlich sein!

II.

Wie gerne hätte ich damals (80er) auch so einen Automaten in meinem Zimmer gehabt! Aber eBay gab´s damals nicht und offenbar kannte ich nicht die richtigen Leute. Matthias hatte einen "Rotomat Trianon" und Jürgen hatte einen "Rotomat Exquisit Gold". Aber ich hatte... zuerst ein Yps-Radio für 6,50 DM, dann zu Weihnachten einen Philips EE2050 Elektronik-Baukasten, danach schrittweise die ganze Serie Baukästen von Busch und schließlich - den [**Microtronic 2090**](https://www.busch-modell.de/information/Microtronic-Computer.aspx). Ein Lerncomputer, mit dem man selbst programmieren (lernen) konnte. Und das konnte man wirklich, weil auch die [Handbücher zu diesem Lerncomputer](https://github.com/lambdamikel/Busch-2090/blob/master/manuals/anl2090-1.pdf) wirklich gut gemacht waren.

Irgendwann reifte der kühne Plan: 

### Ich programmiere mir meinen Automaten selbst!



Programmieren ist ein mühsames Geschäft

Indirekte Adressierung, Felder, symbolische Links, Assembler für  

Der Kreis derjenigen, die ebenfalls einen 2090 hatten (und womöglich noch haben), dürfte ohnehin überschaubar sein. Wenn man dann noch die Schnittmenge bildet mit denjenigen, die bei elektromechanischen Geldspielgeräten ins Schwärmen geraten, wäre eine Abschätzung der verbleibenden Interessengruppe inetwa mit der Größe 1 zu beziffern - also bin ich wohl alleine :-) Aber egal, andere lösen Kreuzworträtsel. Oder Sudoku. Also hier nun mein Programm...





## Zufallszahlen im 2090

Der Microtronic 2090 hat einen Befehl zur Ermittlung einer 3-stelligen hexadezimalen Zufallszahl - RND (F05). Faktisch wird dabei der Zählerstand eines internen Zählers zur Tastaturabfrage ausgelesen und in die Arbeitsregister D, E und F übertragen. Solange im Programm immer mal wieder auf eine Benutzereingabe mit KIN (FFd) gewartet wird, ist das auch kein Problem, da das nötige zufällige Element in der Dauer der Wartezeit auf den Benutzerfinger begründet liegt, mithin ist der Zufallswert hinreichend zufällig. Wenn aber das Programm automatisiert und ohne Benutzereingaben abläuft (und das soll der Spielautomat ja), dann ergibt sich das Problem, dass der interne Zähler und das Programm synchron laufen - wodurch sich immer wieder feste Folgen in der Abarbeitung des Programms ergeben. Als kleiner Junge war mir dieser Zusammenhang nicht klar, und ich wunderte mich damals nur darüber, dass mein "Krieg der Sterne"-Programm mich deutlich öfter als theoretisch erwartet gewinnen ließ. 

Kurz: der Zufall ist nicht zufällig. 

Michael Wessel hat mich darauf aufmerksam gemacht, dass ein anderer zu dieser Zeit ebenfalls erhältlicher Lerncomputer seine "Zufallszahlen" einfach durch obskure Verdrahtung seiner Aus- und Eingänge generiert. Worauf ich versprach, dass ich mich nie wieder über den RND-Befehl des 2090 beschweren wolle. Gleichwohl brauchte ich für mein Programm einen *zufälligeren Zufall*, sonst isses halt einfach zu langweilig. 

Eine Möglichkeit wäre natürlich, nach jeder zufälligen Aktion auf eine Benutzerreaktion zu warten (s.o.) - aber das würde den Charme der Simulation zerstören. Opa Erwin musste 1972 in der Gaststätte "Zu den drei Hasen" auch nicht nach jedem Walzenstopp irgendwas drücken, damit es weiterging. Er warf einfach einen Heiermann ein (5-Mark-Stück für die jüngeren unter uns, der Monarch war der erste Automat, der auch diese Münzen begierig schluckte) und setzte sich wieder an seinen Tisch, während die Kiste von alleine weiterlief und gelegentlich durch einen charakteristischen Türgong auf einen Gewinn aufmerksam machte.

## Peripherie muss her

Der erste Gedanke war, den Baukasten 2075 zu nutzen. Damit wäre ich auch schön im Busch-Universum geblieben. Theoretisch ein Rauschen auf den Takteingang des Zählerbausteins und seine Ausgänge A-D dann auf die Eingänge des 2090 legen. Aber... ich konnte ihn im Keller nicht mehr finden. Irgendwie hat meine Busch-Kiste einen der letzten Umzüge nicht überlebt oder wurde aus dem Keller geklaut. Falls letzteres, wer tut sowas? Möge der Blitz dich bei was-auch-immer treffen. Das ist ein echter Verlust für mich :-(((

Was gibt die Schublade her? Da fanden sich doch tatsächlich noch ein paar Arduino Nanos (Arduini Nani?) 128p, die ich eigentlich schon abgeschrieben hatte, da ein arglistiger Händler aus Fernost mir jene statt der gewünschten und bestellten 328p geliefert hatte. Aber um mal eben schnell ne Zufallszahl zu erzeugen, müssten die doch...

```
unsigned int z;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  randomSeed(analogRead(A0));
}
 
void loop() {
  
  z = random(10);
  // Serial.print ("Nächste Zufallszahl zwischen 0 und 9: ");
  // Serial.println (z); 

  // an Ausgänge binär legen
  digitalWrite(5,z&1);
  z = z >> 1;
  digitalWrite(4,z&1);
  z = z >> 1;
  digitalWrite(3,z&1);
  z = z >> 1;
  digitalWrite(2,z&1);

  delay(100);
}
```

Funktioniert. Damit die Zahlen auch schön zufällig sind, wird der Zufallsgenerator anfangs mit dem offenen analogen Eingang A0 _geseeded_. Das Gequassel auf der seriellen Schnittstelle ist für´s Debugging nützlich, wird aber für den produktiven Einsatz abgeschaltet. Und das Gute bei allem: der Arduino arbeitet mit 5 Volt auf Ein- und Ausgängen, genauso wie der 2090. Kein Level-Shifting nötig, kann direkt verbunden werden.

## Assembler

Der Befehlssatz des 2090 ist nach allem, was ich bescheiden dazu sagen kann, wirklich durchdacht. Kudos an Jörg Vallen, den Schöpfer des Microtronic, der das System im Rahmen seiner Diplomarbeit entwickelt hatte. Man kann damit tatsächlich Programme schreiben, auch wenn man echt viel knobeln muss - und praktisch ständig mit den ganzen Sprungbefehlen GOTO, BRZ, BRC und CALL durcheinander kommt. Es ist zwar nicht _Programmieren auf dem blanken Metall_, aber es kommt dem schon recht nahe. Besonders mühsam war es, Änderungen am Code vorzunehmen, weil alle danach erfolgenden Sprünge im Programm neue Zieladressen erhalten mussten. Eine Arbeit für jemanden, der Vater und Mutter erschlug. Also war es gute Praxis, eine Menge von NOPs in den Code einzufügen, damit man später noch genug Platz für seine brillanten Ideen hatte. Reichlich Karopapier, Bleistift, Radiergummi und Schokolade waren unerlässlich für eine funktionierende _Toolchain_ :-P

Es gab sogar einen Programmierwettbewerb, und später wurde auch ein kleines Büchlein "Computerspiele" veröffentlicht, in dem die jeweils mit 100 DM prämierten Programme zum Abtippen standen. Ich wollte auch teilnehmen, und ich schwör - ich hätte so abgeräumt und euch alle zerstört. Aber irgendwie hatte ich wohl vergessen, mein fantastisches Hammer-Programm abzuschicken. Keinen passenden Umschlag? Keine Briefmarke? Hier trübt sich meine Erinnerung...

Inzwischen sind wir etwas weiter. Dennoch stellte ich fest, dass mein Programm zunehmend unübersichtlich wurde, insbesondere wegen des notwendigen Gebotes zur Sparsamkeit im Programmspeicher. Register mussten mehrfach belegt werden, Subroutinen wurden recycelt für verschiedene Zwecke usw. Für den ZX81 (1 KB RAM!) schrieb nach meiner Erinnerung seinerzeit jemand mal ein Schachprogramm. Gerüchtehalber lief es wohl, aber war natürlich vollkommen unlesbar. Naja, und auch nicht sehr stark... 

Zudem vergisst der 2090 leider alle seine mühevoll von Menschenhirn ersonnenen und Menschenfinger eingegebenen Programmschritte, sobald (versehentlich natürlich) die Steckdose dem Staubsauger weichen musste. Es wurde Zeit, die Programmentwicklung zu professionalisieren. Ein Simulator und/oder eine Speichermöglichkeit und/oder ein Assembler wären doch wirklich nützlich. Zum Glück hat Martin Sauter das Protokoll für das optional erhältliche [Kassetten-Interface 2095](https://blog.wirelessmoves.com/2017/06/emulating-a-busch-2090-tape-interface-part-1.html) _reverse-engineered_ und als Python-Programm für den Raspberry Pi zur Verfügung gestellt. Und auch einen [Assembler für den 2090](https://blog.wirelessmoves.com/2017/07/an-assembler-for-the-busch-2090.html) geschrieben, der auf Calc ([LibreOffice](https://de.libreoffice.org/)) läuft. 

Fortan konnte ich also am PC entwickeln, über Calc mit aktivierten Makros assemblieren (assembeln?), über WLAN an den Raspi Pico W senden, von dort an den Microtronic übertragen und dort dann alle meine Fehler bestaunen. Schokolade!


## Timing des Arduino/Raspi

Der 2090 ist nicht schnell. Michael hat ein paar [Performance-Tests](https://www.youtube.com/watch?v=e8KJ-cnX9bU) durchgeführt und als Ergebnis maximal 114 Operationen pro Sekunde (1,14 HIPS) ermittelt. Da in meinem Programm das Display meistens aktiv ist, dürfte eher ein Wert von 40 _Instructions per second_ (0,4 HIPS) zu erwarten sein. Welche Dauer der Befehl KIN (FDd) zum Einlesen der 4 Bits an den Eingängen beansprucht und wie er ausgeführt wird (sequentiell, parallel, quantenmechanisch o.ä.), ist im Detail nicht bekannt, aber es ist klar, dass Timing ein Faktor sein kann. Wenn die Peripherie die Zufallszahlen zu langsam liefert, wird der gleiche Wert mehrfach im Programm eingelesen, wenn die Zufallszahlen hingegen zu schnell geliefert werden, wird der Wert während des Einlesens möglicherweise "verschmiert", da sich die Bits durch eine in der Zwischenzeit neu erzeugte Zufallszahl verändern können. Dieser zweite Fall wird noch ein richtiges Problem, dazu später...

Eine saubere Lösung, um Timing-Probleme zu vermeiden, wäre: Immer wenn ein Zufallszahl benötigt wird, geben wir dem Zahlen-Lieferanten ein Signal. Der Raspuino erzeugt die Zahl, liefert sie über seine GPIO an die Eingänge des 2090, hält sie da ausreichend lange stabil und wartet dann einfach auf die nächste Zahlen-Bestellung. Das erforderte aber zusätzliche Befehle im Programmcode des 2090 (Wert in Register speichern, Register auf Ausgang legen, ggf. warten auf die Lieferung usw.) Und ein extra Kabel. Und ein wertvolles Register - wir haben nur 16 Stück brauchbare. Nope, scheidet (erstmal) aus.

## Testen ist am besten

Zur Überprüfung meiner Überlegungen und zur Ermittlung des richtigen/besten Lieferintervalls für Zufallszahlen habe ich ein bisschen mit ChatGPT geplaudert und wir haben uns auf folgendes Python-Programm (für den Raspi) geeinigt. Meine programmiertechnische Eigenleistung bestand darin, die richtigen GPIOs einzutragen. 


### Annahmen

What if? Zahlen von 0-9 werden geliefert. Aber werden sie auch eingelesen? ASSERT gibt es im Microtronic Befehlssatz nicht. Im Programmcode wird auf das letzte CMPI verzichtet, weil andernfalls "es ja eine Null/Neun sein muss". Aber was wenn nicht? 

## Addition und Subtraktion

Im Programm müssen 

- der Spieleinsatz von 20 Pf abgezogen,
- eventuell Gewinne im Bereich von 20 Pf bis 2 DM dazugezählt,
- eventuell jeweils ein Sonderspiel (sofern vorhanden) abgezogen und
- eventuell gewonnene Sonderspiele (2, 5, 10, 20 oder 50) dazugezählt werden.

Zunächst hatte ich für Addition und Subtraktion - schön ordentlich und strukturiert - jeweils separate Unterprogramme geschrieben. Der 2090 rechnet Plus und Minus registerweise hexadezimal, also mussten für eine dezimale Darstellung jeweils Dezimalkorrektur und Carry-Flag-Übertrag berücksichtigt werden. Kurzum komplex, die Routinen für eine bis zu 3-stellige dezimale Plus- oder Minus-Operation waren lang und belegten deutlich zu viel Platz im Programmspeicher. So wird das nix.

Die erste Entscheidung war: Ich halte alles hexadezimal in den Registern und wandele es nur bei Bedarf, also für die Anzeige, in Dezimalwerte um. Dazu stehen im Befehlssatz glücklicherweise zwei formschöne Instruktionen zur Verfügung: HXDZ und DZHX, die den Inhalt der Register D bis F jeweils umrechnen. Damit war auch klar, dass der _Münzspeicher_ in den Registern D bis F residieren wird, denn dadurch konnte ich die vielen MOV-Befehle sparen, mit denen ich sonst Werte in den Registern hätte hin- und herschieben müssen. 

Aber ich habe ja nicht nur den 3-stelligen Münzspeicher, sondern auch den _Sonderspiele-Zähler_... Wohin damit? Ich müsste den ja temporär in die Register D-F schieben, damit Umrechnung und Anzeige erfolgen können. Schon wieder jede Menge MOVes :-( Halt, es gibt ja EXRA, den Befehl, mit dem in einem Rutsch alle Speicherregister von 0-7 mit denen von 8-F getauscht werden. Spart viel "Schiebung", dann müsste der Sonderspiele-Zähler also notwendigerweise in die Register 5 bis 7... Hmmm... Check.

Mir war noch vage von der Uni in Erinnerung, dass binäre Subtraktion ja auch nichts anderes als Addition mit der Inversen des Subtrahenden plus 1 ist. Wer´s nicht glaubt, prüft es nach. Also konnte ich die Routinen zu einer einzigen zusammenfassen; es wird nur addiert. Da nur zwei feste Werte (20 Pf, 1 Spiel) ggf. zu subtrahieren sind, konnte ich diese im Programm "fest verdrahten" (die Werte FFE und FFF werden _subtraddiert_<sup>TM</sup>). Insgesamt wurde dadurch das _Rechenwerk_ des Monarchen angenehm schlank und viele Programmschritte wurden eingespart. Ob das Programm dadurch auch übersichtlicher wurde, darf allerdings bezweifelt werden.

```
DeltaSub	MOVI #F,DELTA_E	              Einsprungadresse für Subtraktion (Addition mit invertiertem HEX-Wert + 1)
	        MOVI #F,DELTA_F	
DeltaAdd	ADD DELTA_D,rD	
	        ADC rE	
	        ADC rF	
	        ADD DELTA_E,rE	
	        ADC rF	
	        ADD DELTA_F,rF	              wegen mögl. Subtraktion auch letzte Stelle “addieren”
	        RET
```

test



