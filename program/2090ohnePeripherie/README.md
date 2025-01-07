Hier wird nur der Piezo-Summer an Ausgang 1 angeschlossen.

Damit der 2090-eigene Zufallsgenerator auch zufällige Zahlen ausspuckt, muss vor jedem Walzenstopp (links, rechts und in der Mitte) jeweils eine Taste gedrückt werden.

Nach Anzeige des Münzspeichers zeigt der Monarch 00000 und wartet auf eine Taste, damit die erste Walze ermittelt wird. Die linke Walze kann dann - einmalig pro Spiel - erneut gestartet werden, wenn man die Taste F drückt. Jede andere Taste lässt den Monarchen die rechte Walze ermitteln. 

Rechte und mittlere Walze können nicht erneut gestartet werden. 

Nach Ermittlung aller Walzen wird die normale Gewinnabfrage und -anzeige durchgeführt und anschließend wieder zur Anzeige des Münzspeichers zurückgekehrt.

Übrigens: Ganz zufällig ist auch diese Variante nicht, denn...

```
KIN TASTE
RND
CMPI #9,rD
BRC Würfel
RET
```

- Der RND-Befehl sorgt für eine hexadezimale Ziffer im Register D.
- Bei den Ziffern A-F soll laut Programm einfach eine neue Ziffer ermittelt werden.
- Intern läuft der Zähler für die Tastaturabfrage weiter.
- Vergleich und Sprung zur Neuermittlung dauern immer gleich lang, daher ist das Intervall für den Zähler immer gleich lang.
- Die sechs Ziffern A-F lassen den 2090 also immer die gleichen neuen dezimalen Ziffern ermitteln.
- Also sind (mind.) 4 dezimale Ziffern mit verminderter Wahrscheinlichkeit zu erwarten.

Das Handbuch weist auf diese Eigenart auch hin. Bei "Unser erstes Programm: Ein elektronischer Würfel" heißt es: "Eine gewisse Häufigkeit einzelner Zufallszahlen wird bei später folgenden Experimenten durch ein etwas aufwendigeres Programm beseitigt." (Bd. 1, Seite 11). In späteren Programmen werden daher für die "Verbesserung" des Zufalls auch noch das E und F-Register herangezogen.
