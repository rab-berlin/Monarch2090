# Monarch2090 mit Erweiterungskasten 2075 (Digital-Technik)

In dieser Variante wird der Monarch durch den Zählerbaustein des 2075 mit den nötigen Zufallszahlen versorgt.

![Schaltplan](/pics/Schaltung2075.png)

Dazu wird die bekannte Oszillator-Schaltung aus dem 2075-Baukasten ("Elektronisches Roulette") verwendet und deren Frequenz durch einen hinreichend kleinen Kondensator vergrößert. Zugegeben, ein 22 pF-Kondensator gehört nicht zum Lieferumfang des 2075. Zur Not aus einem anderen Kasten nehmen (z.B. 2x 10 pF aus den "neueren" 2070, in denen der MW-Radio-IC schon beigelegt war), aus dem China-Beutel rausfischen - oder selbst bauen aus Alufolie und Schaumstoff.

## Geschwindigkeit ist (k)eine Hexerei

Die Überlegung: Wenn der Zählerbaustein deutlich schneller getaktet wird als der Microtronic, dann dürften bereits kleinste Unregelmäßigkeiten im Taktsignal ausreichen, um an den Ausgängen A-D eine mehr oder weniger zufällige Ziffer von 0-9 zu präsentieren, sobald der Oszillator anhält. Denn diese _kleinsten Unregelmäßigkeiten_ treten im MHz-Bereich einer Oszillator-Schaltung ohne Quarz praktisch immer auf - durch thermisches Rauschen, elektromagnetische Einstrahlung oder göttliche Fügung.

Ein einzelnes 7400-Gatter hat eine Schaltzeit von 20 ns, kann also 50 MHz vertragen. Da aber für den Oszillator drei Gatter nacheinander durchlaufen und rückgekoppelt werden, erreichen wir eine maximale Frequenz von etwa 16 MHz. Der SN74143N auf dem Zählerbaustein schafft laut Datenblatt typischerweise 18 MHz. Etwas unterhalb dieses Bereiches wollen wir also unseren Oszillator schwingen lassen, damit "Zufall durch Gleichlaufschwankung" zwischen 2075 und 2090 bestmöglich generiert werden kann.

![Oszillatorfrequenz](/pics/Oszillator.png)

Mit einem 22 pF-Kondensator erreichen wir laut CH1 eine Frequenz von etwa 10,25 MHz. Passt. 

Man sieht auf CH2, dass der Ausgang D nur mit 1,025 MHz schwingt. Dadurch können wir bestätigen, dass die Schaltung funktioniert, denn Bit 4 wird immer nur ab Ziffer 8 zwei Impulse lang high. Passt auch.

## HoleZahl

Um eine neue Zufallszahl einzulesen, ruft der Monarch das Unterprogramm _HoleZahl_ auf. 

```
MOVI #8,DELTA_D             Zufallsgenerator stoppen
DOT DELTA_D			
MOVI #0,GEWINNSYMBOL        Verzögerung, damit Aus-/Eingänge stabil
DIN ZAHL09	
DOT STATUS                  Zufallsgenerator starten
RET	
```

Darin wird ein High auf Ausgang 4 gelegt und dadurch der Oszillator gestoppt. Nach einer Schamfrist von einem Microtronic-Befehl (damit die Ausgänge des Zählerbausteins sicher stabil sind), wird die Zahl über die Eingänge 1-4 eingelesen. Gleich danach wird der Oszillator wieder gestartet durch Low an Ausgang 4.

## Nachstarten

Die erste Walze soll - einmalig pro Spiel - bei Nichtgefallen erneut gestartet werden können. Weil alle Eingänge des 2090 bereits von den Ausgängen A-D des Zählerbausteins belegt sind, bleibt allerdings kein Platz, um einen roten Taster direkt anzuschließen. 

Also habe ich die Nachstart-Logik in die Oszillator-Schaltung eingebaut. Während der Möglichkeit zum Nachstart wird...

- zuerst ein High auf Ausgang 3 gelegt,
- dadurch der Transistor angesteuert
- und der Oszillator gestoppt.
- Der RESET-Eingang erhält dann über den 100 nF-Kondensator einen kurzen Impuls und "nullt" den Zähler.
- Wenn der Taster betätigt wird, wird ein Taktimpuls an den Zähler gegeben (oder mehrere, da nicht entprellt).
- Vor Ende der Nachstart-Periode liest der 2090 wieder seine Eingänge ein.

Falls eine Null anliegt, wurde die Taste nicht gedrückt, also kein Nachstart der Walze gewünscht. Alles andere als Null -> Nachstarten.

```
MOVI #4,DELTA_D             Zufallsgenerator stoppen 
DOT DELTA_D	
CALL Warteschleife          Zeit geben zur Entscheidung
DIN TASTE                  
DOT STATUS                  Zufallsgenerator wieder starten
SUBI #F,DELTA_E             (nur einmal Nachstart ermöglichen)
BRC stopR	
CMPI #0,TASTE               Taste gedrückt?
BRC stopL                   Dann linke Walze nochmal starten
```

## Wie zufällig ist der Zufall?

Überraschend gut. Ich hatte mit verschiedenen Kondensatoren experimentiert, also mit verschiedenen Oszillator-Frequenzen. Alles im nF-Bereich kann man vergessen, dadurch wird nicht ausreichend Asynchronität zwischen Oszillator und Programmlauf hergestellt. Ab pF wurde es interessant, bei 22 pF erziele ich die besten Ergebnisse

![Oszillatorfrequenz](/pics/Statistik2075.jpg)

Die Kombinationen A4 und C4 werden jeweils durch zwei dezimale Zufallszahlen getroffen, müssten also doppelt so häufig auftreten wie andere Kombinationen. Passt. Gut genug jedenfalls.

## Brown noise generator

Wenn ich mal richtig viel Zeit (und genug Verständnis) habe, dann soll der Zählerbaustein nicht vom Gatterbaustein getaktet werden, sondern durch einen Rauschgenerator, der dann wirklich zufällige Taktsignale liefern würde... Dazu käme dann noch zusätzlich der [Baukasten 2070](/program/2090und2075und2070) zum Einsatz, mit dem ein ["Brown-noise-generator"](https://de.wikipedia.org/wiki/Rauschgenerator) realisiert werden soll.

Bisherige Versuche scheiterten jedoch. Hauptsächlich an meinem Verständnis. Ich bin sehr offen für Ideen... ;-)
