Dann schließt du einen roten Taster an Eingang 1 ein, das ist deine Taste zum Neustarten der linken Walze. (noch in der Entwicklung)

![Schaltplan](/pics/MonarchEmulator.jpg)


## Besonderheiten

- Der Zufallsgenerator RND "zerstört" die drei Register D-F, daher müssen wir den Inhalt dieser Register (also den Münzspeicher) vorher retten und nach Ermittlung aller drei Walzen wieder zurückschieben - das kostet leider 6 Programmschritte. Geht aber, passt noch gerade so rein. 

- Bei den Varianten 2075/Arduino "merkt" sich die Peripherie, ob der rote Taster zum Nachstarten während der Anzeigezeit der ersten Walze gedrückt wurde. Der Emulator hat jedoch keine solche "Gedächtnis-Peripherie", daher wird eine eigene Warteschleife für die Anzeige verwendet.
```
L_fertig      SUBI #F,rC	                (rC enthält zu Beginn 0)
	            BRZ stopR	                  
	            DIN TASTE	
	            BRZ L_fertig	
	            ADDI #8,GEWINNSYMBOL	      Taste wurde 2. Mal gedrückt?
	            BRC stopR	                  Dann Taste ignorieren und rechte Walze ermittlen
	            GOTO stopL	                Sonst linke Walze nochmal starten
```
die sofort verlassen wird, wenn
  - wenn die Wartezeit abgelaufen ist oder
  - wenn der Taster gedrückt wurde.

