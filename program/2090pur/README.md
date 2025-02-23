# Monarch2090 pur

Hier werden nur der Piezo-Summer an Ausgang 1 und die beiden roten Taster mit Vorwiderständen (4,7 kOhm) an die Eingänge 1 und 2 angeschlossen. Da die Schaltung keinen Strom verbraucht, solange kein Taster gedrückt wird, kann problemlos eine 9V-Batterie verwendet werden. 

![Schaltplan](/pics/SchaltungPur.png)

## Taster zum Walzenstopp

Damit der 2090-eigene Zufallsgenerator auch zufällige Zahlen ausspuckt, muss vor jedem Walzenstopp (links, rechts und in der Mitte) jeweils eine Taste gedrückt werden.

Zu Beginn eines Spiels zeigt der Monarch - nach kurzem Einblenden des Münzspeichers - **00000** auf dem Display und wartet auf einen Tastendruck, damit die erste (also linke) Walze ausgewürfelt wird. Nur diese Walze kann dann - einmalig pro Spiel - erneut gestartet werden, wenn man den roten Taster H drückt. Der rote Taster G hingegen lässt den Monarchen immer gleich die nächstfolgende Walze ermitteln. 

Alternativ kannst du die roten Taster übrigens auch weglassen und stattdessen die Tastatur des Microtronic verwenden. Dazu musst du eine kleine Programmänderung an den Adressen F5 und F6 vornehmen. Statt
```
F5 FD9     
F6 EF5      
```
lauten die entsprechenden Befehle dann
```
F5 FF9     
F6 F01      
```

Nach Ermittlung aller drei Walzen wird die normale Gewinnabfrage, -anzeige und -verbuchung durchgeführt und anschließend wieder ein neues Spiel gestartet (sofern man noch Geld auf dem Münzspeicher hat).

## Zufall

Ganz zufällig ist auch diese Variante nicht, denn...
```
HoleZahl    DIN TASTE
            BRZ HoleZahl
Würfel      RND
            CMPI #9,rD
            BRC Würfel
            RET
```

- Der RND-Befehl sorgt für eine hexadezimale Ziffer im Register D.
- Bei den Ziffern A-F soll laut Programm einfach eine neue Ziffer ermittelt werden.
- Intern läuft der Zähler für die Tastaturabfrage weiter.
- Vergleich und Sprung zur Neuermittlung dauern immer gleich lang, daher ist das Intervall für den Zähler immer gleich lang.
- Die sechs Ziffern A-F lassen den 2090 also ~~immer~~ erwartbar die gleichen neuen dezimalen Ziffern ermitteln.
- Also sind (mind.) 4 dezimale Ziffern mit verminderter Wahrscheinlichkeit anzunehmen.

Das Handbuch weist auf diese Eigenart auch hin. Bei "Unser erstes Programm: Ein elektronischer Würfel" heißt es: "Eine gewisse Häufigkeit einzelner Zufallszahlen wird bei später folgenden Experimenten durch ein etwas aufwendigeres Programm beseitigt." (Bd. 1, Seite 11). In späteren Programmen werden daher für die "Verbesserung" des Zufalls auch noch das E und F-Register herangezogen.
