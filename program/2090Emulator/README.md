# Monarch2090 mit Emulator [Microtronic NextGen](https://github.com/lambdamikel/Busch-2090/tree/master/microtronic-nextgen-sh1106-spi)

Du schließt einen roten Taster zwischen Eingang 1 und +3V an, das ist deine Taste zum Neustarten der linken Walze.

![Schaltplan](/pics/MonarchEmulator.jpg)

## Besonderheiten

- Der Zufallsgenerator RND "zerstört" die drei Register D-F, daher müssen wir den Inhalt dieser Register (also den Münzspeicher) vorher retten und nach Ermittlung aller drei Walzen wieder zurückschieben - das kostet leider 2 x 3 = 6 Programmschritte. Passt aber noch gerade so rein... :-)

- Bei den Varianten 2075/Arduino "merkt" sich die Peripherie, ob der rote Taster zum Nachstarten während der Anzeigezeit der ersten Walze gedrückt wurde. Der Emulator hat jedoch keine solche "Gedächtnis-Peripherie", daher wird nicht das normale Unterprogramm _Warteschleife_, sondern eine eigene Warteschleife für die Anzeige verwendet.
```
L_fertig	SUBI #F,rC		(rC enthält zu Beginn 0)
		BRZ stopR		Wenn Wartezeit vorbei, dann rechte Walze      
		DIN TASTE
		BRZ L_fertig		Wenn keine Taste, dann Schleifenanfang
		ADDI #8,GEWINNSYMBOL	Wurde Taste zum 2. Mal gedrückt?
		BRC stopR		Dann Taste ignorieren und rechte Walze 
		GOTO stopL		Sonst linke Walze erneut starten
```
