# Monarch2090 mit Erweiterungskasten 2075 (Digital-Technik)

In dieser Variante wird der Monarch durch den Zählerbaustein des 2075 mit den nötigen Zufallszahlen versorgt.

## Geschwindigkeit ist (k)eine Hexerei

Ein einzelnes 7400-Gatter hat eine Schaltzeit von 20 ns, kann also 50 MHz vertragen. Da aber für den Oszillator drei Gatter nacheinander durchlaufen werden, erreichen wir eine maximale Frequenz von etwa 16 Mhz. Der SN74143N auf dem Zählerbaustein schafft laut Datenblatt typischerweise 18 MHz.

Dazu wird die bekannte Oszillator-Schaltung aus dem 2075-Baukasten ("Elektronisches Roulette") verwendet und deren Frequenz durch einen hinreichend kleinen Kondensator vergrößert. Zugegeben, ein 47 pF-Kondensator gehört nicht zum Lieferumfang des 2075. Zur Not aus einem anderen Kasten nehmen - oder selbst bauen aus Alufolie und Schaumstoff.

Die Überlegung: Wenn der Zählerbaustein deutlich schneller getaktet wird als der Microtronic, dann dürften bereits kleinste Schwankungen im Taktsignal ausreichen, um an den Ausgängen A-D eine mehr oder weniger zufällige Ziffer von 0-9 zu präsentieren, sobald der Oszillator gestoppt wird. Denn diese _kleinsten Schwankungen_ treten im Mhz-Bereich einer Oszillator-Schaltung ohne Quarz praktisch immer auf - durch thermisches Rauschen, elektromagnetische Einstrahlung oder womöglich auch göttliche Fügung.

## HoleZahl

Um eine neue Zufallszahl einzulesen, ruft der Monarch das Unterprogramm _HoleZahl_ auf. Darin wird ein High auf Ausgang 4 gelegt und dadurch der Oszillator gestoppt. Nach einer Schamfrist von einem Microtronic-Befehl (damit die Ausgänge des Zählerbausteins sicher stabil sind), wird die Zahl über die Eingänge 1-4 eingelesen. Gleich danach wird der Oszillator wieder gestartet durch Low an Ausgang 4.

## Nachstarten

Die erste Walze soll - einmalig pro Spiel - bei Nichtgefallen erneut gestartet werden können. Weil alle Eingänge des 2090 bereits von den Ausgängen A-D des Zählerbausteins belegt sind, bleibt allerdings kein Platz, um einen roten Taster direkt anzuschließen. 

Also habe ich die Nachstart-Logik in die Oszillator-Schaltung eingebaut. Während der Möglichkeit zum Nachstart wird...

- ein High auf Ausgang 3 gelegt
- dadurch der Transistor angesteuert
- und der Oszillator gestoppt
- der RESET-Eingang erhält über den 100 nF-Kondensator einen kurzen Impuls und "nullt" den Zähler
- wenn der Taster in dieser Zeit gedrückt wird, wird ein Taktimpuls an den Zähler gegeben (oder mehrere, da nicht entprellt)
- zum Ende der Nachstart-Periode liest der 2090 wieder seine Eingänge ein

Falls eine Null anliegt, wurde die Taste nicht gedrückt, also kein Nachstart der Walze gewünscht. Alles andere als Null -> Nachstarten.

## Red noise generator

Wenn ich mal richtig viel Zeit (und genug Verständnis) habe, dann soll der Zählerbaustein nicht vom Gatterbaustein getaktet werden, sondern durch einen Rauschgenerator, der dann wirklich zufällige Taktsignale liefern würde... Dazu käme dann noch zusätzlich der Baukasten 2070 zum Einsatz, mit dem ein "Red-noise-generator" realisiert werden soll.

Bisherige Versuche scheiterten jedoch. Hauptsächlich an meinem Verständnis. Ich bin sehr offen für Ideen... ;-)
