# Monarch2090

Eine Simulation des legendären Spielautomaten [Rotomat Monarch](http://www.rd-b.de/html/wulff_rotomat_monarch.html) (1972) auf dem [Microtronic 2090](https://www.busch-modell.de/information/Microtronic-Computer.aspx) (1981)

## Was soll das Ganze?

I.

In den 70er-Jahren waren sog. elektro-mechanische Spielautomaten in Kneipen und Restaurants weit verbreitet. Spielhallen gab es damals - zum Glück - noch nicht. Die Ablaufsteuerung dieser Automaten erfolgte über eine motorgetriebene, langsam rotierende Nockenwelle, an der Kontaktfedern zum jeweils richtigen Zeitpunkt Strompfade öffneten und schlossen - ganz ohne Computer konnten so komplexe Spielsysteme realisiert werden. Und anders als bei den kurz darauf aufkommenden computergesteuerten Spielautomaten war das Ergebnis tatsächlich noch "zufällig", da der Lauf der sich drehenden Walzen nicht determiniert war und insofern der Spielausgang rein (elektro-)mechanisch beeinflusst wurde. Im Vertrauen auf das Gesetz der großen Zahl haben die Automatenaufsteller dennoch gut verdient, nur 60% der Einsätze mussten (wahrscheinlichkeitstheoretisch) als Gewinne mindestens wieder ausgeworfen werden. 

Der erfolgreichste Vertreter dieser Generation von Spielautomaten war der [Rotomat Monarch](http://www.rd-b.de/html/wulff_rotomat_monarch.html) von der Firma Günter Wulff Apparatebau in Berlin, der 1972 auf den Markt kam - mit der sagenhaften Stückzahl von über 30.000 Geräten. Wegen der restriktiven Glücksspiel-Gesetzgebung musste ein Spiel mindestens 15 Sekunden dauern, der Höchsteinsatz pro Spiel lag bei 20 Pf und der Höchstgewinn betrug 2 DM. Um diese gesetzlichen Vorgaben formal einzuhalten und doch tricky-tricky zu umgehen, haben die Automatenbauer sich etwas geradezu Geniales einfallen lassen: _Sonderspiele_. Auch in diesen Spielen konnte man maximal 2 DM gewinnen, aber die Wahrscheinlichkeit für diesen Spielgewinn lag während der Sonderspiel-Dauer bedeutend höher (mehr als 50%). Wenn man den _höchst seltenen Fall_ erlebte, dass der Automat den Höchstgewinn von 50 Sonderspielen gab, konnten - unter völliger Einhaltung der gesetzlichen Bestimmungen - so aus 20 Pf mehr als 50 DM werden (50 mal Erwartungswert von ca. 1 DM). Eine Menge Geld im Jahr 1972, inflationsbereinigt über 100 Euro heute.

Neben dem Reiz, den die Aussicht auf Geldgewinne für viele Menschen darstellt, war die [Geräuschkulisse solcher Automaten](https://www.youtube.com/watch?v=yDXITgWsWbw) wirklich faszinierend. Ein ständiges Rattern und Klingeln. Auch die Optik der Geräte ist ein schöner Spiegel der Zeit. Allerdings durften diese Maschinen nur 3 Jahre lang gewerblich im Einsatz sein, danach mussten sie aus dem Verkehr gezogen werden und waren eigentlich Elektroschrott. Sie wurden dann bestenfalls an Privatpersonen verkauft und hingen oft als Spardose für die nächste Party in Hobbykellern. Mit der Euro-Einführung waren diese Geräte dann wirklich nutzlos geworden und wurden an Selbstabholer (Gewicht über 40 Kilo!) über eBay vertickt. Auch heute noch sind solche Automaten mühelos zu bekommen und mit etwas technischem Geschick lassen sie sich sogar auf die Annahme von Euro und Cent umrüsten. Aber Vorsicht, im Inneren sind praktisch überall 230 Volt. Das kann lebensgefährlich tödlich sein!

II.

Wie gerne hätte ich damals (80er) auch so einen Automaten in meinem Zimmer gehabt! Aber eBay gab´s damals nicht und offenbar kannte ich nicht die richtigen Leute. Matthias hatte einen "Rotomat Trianon" und Jürgen einen "Rotomat Exquisit Gold", mit denen sie uns das Taschengeld abluchsten. Aber ich hatte... zuerst ein Yps-Radio für 6,50 DM, dann zu Weihnachten einen Philips EE2050 Elektronik-Baukasten, danach schrittweise die ganze Palette Baukästen von Busch und schließlich - den [Microtronic 2090](https://www.busch-modell.de/information/Microtronic-Computer.aspx). Ein Lerncomputer, mit dem man selbst programmieren (lernen) konnte. Und das konnte man wirklich, weil auch die [Handbücher zu diesem Lerncomputer](https://github.com/lambdamikel/Busch-2090/blob/master/manuals/anl2090-1.pdf) wirklich gut gemacht waren.

Irgendwann reifte der kühne Plan: **Ich programmiere mir meinen Automaten selbst!**

Mit den mir damals zur Verügung stehenden [Möglichkeiten](https://github.com/rab-berlin/Monarch2090/blob/main/README.md#Toolchain) hab ich das dann auch gemacht. 

## Wen interessiert´s?

Der Kreis derjenigen, die ebenfalls einen 2090 hatten (und womöglich noch haben), dürfte reichlich überschaubar sein. Bildet man dann noch die Schnittmenge mit Personen, die bei elektro-mechanischen Geldspielgeräten in Verzückung geraten, wäre eine Abschätzung der verbleibenden Interessengruppe etwa mit der Größe 1 zu beziffern - also bin ich wohl alleine :-) 

Aber egal, andere lösen Kreuzworträtsel oder Sudoku. Es ist, was es ist, sagte die Liebe. Also hier nun mein Programm...

# Der Monarch

Zuvor aber: [Wie funktioniert der Monarch?](https://github.com/rab-berlin/Monarch2090/blob/main/documents/MonarchTechnischeBeschreibung.pdf)

## Walzen 

Das Gerät hat drei Walzen, links, rechts und in der Mitte. Zu Beginn jedes Spiels werden vom Guthabenspeicher 20 Pf Spieleinsatz abgezogen, danach beginnen alle Walzen sich zu drehen. Anschließend stoppen die Walzen nacheinander in der Reihenfolge "Links - Rechts - Mitte" und zeigen Gewinnsymbole: entweder einen Geldbetrag oder Krone bzw. König. Auf der linken und rechten Seite werden je zwei Symbole angezeigt, in der Mitte nur eins.

## Nachstarten

Nachdem die linke Walze gestoppt hat, kann der Spieler entscheiden, ob ihm die angezeigten Symbole gefallen. Einige Sekunden lang leuchet dann eine Taste auf, mit der die linke Walze einmalig pro Spiel nachgestartet werden kann. 

## Gewinnkombination

Wenn auf allen drei Walzen das gleiche Symbol (der gleiche Betrag) erscheint, dann hat man gewonnen. Die Kombination 40 - 40 - 40 z.B. bedeutet 40 Pfennig Gewinn. Jede Kombination gleicher Symbole gewinnt - egal ob oben oder unten auf den äußeren Walzen. Der König auf der mittleren Walze funktioniert dabei als _Joker_, d.h. er ersetzt jedes notwendige Symbol für eine Gewinnkombination.

## Sonderspiele (Serie)

Was alle Spieler aber wollen, sind nicht die "Kleingewinne" (dreimal der gleiche Betrag), sondern Sonderspiele (eine _Serie_). Denn wie oben bereits erwähnt, ist in diesen Spielen die Gewinnerwartung deutlich höher. Sonderspiele gewinnt man durch die Kombination "König - König - König" (10 Sonderspiele) oder "Krone - König - Krone" (5 Sonderspiele). Wenn nacheinander links und rechts ein König erscheint, dann steigt die Spannung und man betet zu Fortuna, dass in der Mitte der Regent auch auftauchen möge. 

![Monarch: Gewinnkombination für 10 Sonderspiele](/pics/monarch-vollbild.jpg)

Während einer Serie wird jeder erzielte Gewinn auf 2 DM erhöht. Zusätzlich gewinnt jedes karierte Feld in der Mitte ebenfalls 2 DM (die doppelt vorhandenen Beträge 40 Pf, 2 DM sind kariert hinterlegt, der König alleine gewinnt sowieso). Insgesamt hat man also in jedem Sonderspiel eine mehr als 50%-ige Chance, 2 DM zu gewinnen - denn 5 von 10 Feldern sind kariert, dazu kommen die möglichen Gewinne durch Kombination von Beträgen unterhalb von 2 DM.

## Tableau

Die Sonderspiele 20 bis 1 zeigt der Monarch auf einem Leucht-Tableau an; die jeweilige Position des Sonderspiele-Zählers leuchtet während des Spiels. Wenn eine Serie läuft, dann kann sie verlängert werden. Steht z.B. der Sonderspiele-Zähler auf der Position 10 und erscheint dann ein König in der Mitte, werden 10 zusätzliche Sonderspiele gegeben. Auf den Positionen 9 bis 2 jeweils 2 zusätzliche Sonderspiele, auf der Position 1 ganze 20 Sonderspiele. Auf Position 15 gibt es bei König in der Mitte sogar 50 Sonderspiele (davon träumen alle). Auf Position 14 werden 2 Sonderspiele gegeben (sodass man erneut die Chance auf den Großgewinn von 50 Sonderspielen bekommt). Adrenalin pur. 

## Wahrscheinlichkeiten

Da jede Walze 10 Stellungen hat, erhält man durchschnittlich alle 500 Spiele eine Serie - linke Walze König oder Krone (2/10), rechte Walze passend dazu König oder Krone (1/10), mittlere Walze nur König, denn Krone gibt es in der Mitte nicht (1/10). Also 0,2 x 0,1 x 0,1 = 0,002 (= 1/500). 

## Strategie

Nutzt man konsequent die Nachstart-Möglichkeit der ersten Walze, wird die Wahrscheinlichkeit für eine Serie etwa verdoppelt - was aber dann auf Kosten der "Kleingewinne" geht. 

Jetzt aber wirklich mein Programm...

## Design-Entscheidungen

Um den Spielablauf des Automaten möglichst authentisch abzubilden, musste ich einige Entscheidungen treffen. **Was** wird **wann** **wie** und in **welcher Reihenfolge** dargestellt? Wir haben ja nur eine 6-stellige Sieben-Segment-Anzeige.

### Walzensymbole

Jeder Walzenkörper des Monarchen hat 10 Positionen, auf denen Gewinnbeträge bzw. Symbole abgebildet sind. Diese und ihre Entsprechungen auf dem 2090 sind:

```
 Monarch-	Microtronic-
  Symbol	   Symbol
----------	------------
  -,40		     4
  -,80		     8
  1,-		     9
  1,20		     A
  1,40		     B
  1,60		     C
  2,-		     D
 Krone		     E
 König		     F
```

### Programmablauf

1. Prüfung, ob Geld auf dem Münzspeicher
2. Anzeige Münzspeicher
3. Abbuchung 20 Pf Spieleinsatz
4. Wenn Serie läuft,
     - Anzeige Sonderspiele-Zähler
5. Anzeige der Walzen
6. Ermittlung linke Walze
7. Ermittlung rechte Walze
8. Ermittlung mittlere Walze
9. Gewinnauswertung
10. Anzeige Gewinn (meistens 0)
11. Anzeige Münzspeicher
12. Aufbuchung Gewinn
13. Wenn Sonderspiele laufen
     - Auswertung Verlängerungs-Tableau
14. Wenn Sonderspiele laufen oder gewonnen,
     - Anzeige Sonderspiele-Gewinn
     - Anzeige Sonderspiele-Zähler
     - Aufbuchung Sonderspiele-Gewinn
15. Zurück zum Anfang

Sonderspiele und Sonderspiel-Gewinne werden nur angezeigt, wenn der Sonderspiel-Zähler größer als 0 ist (also eine Serie gewonnen wurde oder schon läuft).

## Zufallszahlen im 2090

Der Microtronic 2090 hat einen Befehl zur Ermittlung einer 3-stelligen hexadezimalen Zufallszahl - RND. Faktisch wird dabei der Zählerstand eines internen Zählers zur Tastaturabfrage ausgelesen und in die Arbeitsregister D, E und F übertragen. Solange im Programm immer mal wieder auf eine Benutzereingabe mit KIN gewartet wird, ist das auch kein Problem, da das nötige zufällige Element in der Dauer der Wartezeit auf den Benutzerfinger begründet liegt, mithin ist der Zufallswert hinreichend zufällig. Wenn aber das Programm automatisiert und ohne Benutzereingaben abläuft (und das soll der Spielautomat ja), dann ergibt sich das Problem, dass der interne Zähler und das Programm synchron laufen - wodurch sich immer wieder feste Folgen in der Abarbeitung des Programms ergeben. 

Als kleiner Junge war mir dieser Zusammenhang übrigens nicht klar, und ich wunderte mich damals nur darüber, dass mein "Krieg der Sterne"-Programm mich deutlich öfter als theoretisch erwartet gewinnen ließ. 

Kurz: der Zufall ist nicht zufällig genug. 

[Michael Wessel](https://github.com/lambdamikel/Busch-2090) hat mich darauf aufmerksam gemacht, dass ein anderer zu dieser Zeit ebenfalls erhältlicher Lerncomputer, der [Kosmos CP1](http://www.8bit-homecomputermuseum.at/computer/kosmos_computer_praxis_cp1.html), seine "Zufallszahlen" einfach durch obskure Verdrahtung seiner Aus- und Eingänge generiert. Worauf ich versprach, dass ich mich nie wieder über den RND-Befehl des 2090 beschweren wolle. Gleichwohl brauchte ich für mein Programm einen *zufälligeren Zufall*, sonst isses halt einfach zu langweilig. 

Eine Möglichkeit wäre natürlich, nach jeder zufälligen Aktion auf eine Benutzerreaktion zu warten (s.o.) - aber das würde den Charme der Simulation zerstören. Opa Erwin musste 1972 in der Gaststätte "Zu den drei Hasen" auch nicht nach jedem Walzenstopp irgendwas drücken, damit es weiterging. Er warf einfach einen Heiermann ein (für die jüngeren unter uns: ein 5-Mark-Stück - der Monarch war der erste Automat, der auch diese Münzen dankbar schluckte) und setzte sich wieder an seinen Tisch, während die Kiste von alleine weiterlief und gelegentlich durch einen charakteristischen Türgong auf einen Gewinn aufmerksam machte.

## Peripherie muss her

Der erste Gedanke war, den Busch-Baukasten Digitaltechnik 2075 zu nutzen. Damit wäre ich auch schön im Busch-Universum geblieben. Theoretisch ein Rauschen auf den Takteingang des Zählerbausteins und seine Ausgänge A-D dann auf die Eingänge des 2090 legen. Aber... ich konnte ihn im Keller nicht mehr finden. Irgendwie hat meine Busch-Kiste einen der letzten Umzüge nicht überlebt oder wurde aus dem Keller geklaut. Falls letzteres, wer tut sowas? Möge der Blitz dich beim ~~Schei~~ was-auch-immer treffen. Das ist ein echter Verlust für mich :-(((

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

Der Befehlssatz des 2090 ist nach allem, was ich bescheiden dazu sagen kann, wirklich durchdacht. Kudos an Jörg Vallen, den Vater des Microtronic, der das System im Rahmen seiner Diplomarbeit entscheidend mitentwickelt hatte. Man kann damit tatsächlich Programme schreiben, auch wenn man echt viel knobeln muss - und praktisch ständig mit den ganzen Sprungbefehlen GOTO, BRZ, BRC und CALL durcheinander kommt. Es ist zwar nicht _Programmieren auf dem blanken Metall_, aber es kommt dem schon recht nahe. 

Besonders mühsam war es, Änderungen am Code vorzunehmen, weil alle danach erfolgenden Sprünge im Programm neue Zieladressen erhalten mussten. Eine Arbeit für jemanden, der Vater und Mutter erschlug. Also war es gute Praxis, an kritischen Stellen eine Menge von NOPs in den Code einzufügen, damit man später noch genug Platz für seine brillanten Ideen hatte. Reichlich Karopapier, Bleistift, Radiergummi und Schokolade waren unerlässlich für eine funktionierende [_Toolchain_](https://github.com/rab-berlin/Monarch2090/blob/main/README.md#Toolchain) :-P

Es gab sogar einen Programmierwettbewerb, und später wurde auch ein kleines Büchlein ["Computerspiele"](https://github.com/lambdamikel/Busch-2090/blob/master/manuals/anl2094.pdf) veröffentlicht, in dem die jeweils mit 100 DM prämierten Programme zum Abtippen standen. Ich wollte auch teilnehmen, und ich schwör - ich hätte so abgeräumt und euch alle zerstört. Aber irgendwie hatte ich wohl vergessen, mein fantastisches Hammer-Programm abzuschicken. Keinen passenden Umschlag? Keine Briefmarke? Hier trübt sich meine Erinnerung...

Inzwischen sind wir etwas weiter. Beim Programmieren stellte ich allerdings fest, dass mein Programm zunehmend unübersichtlich wurde, insbesondere wegen des notwendigen Gebotes zur Sparsamkeit im Programm- und Registerspeicher. Register mussten mehrfach belegt werden, Subroutinen wurden recycelt für verschiedene Zwecke usw. Der 2090 hat übrigens keine ["Von-Neumann-Architektur"](https://de.wikipedia.org/wiki/Von-Neumann-Architektur), sondern eine ["Harvard-Architektur"](https://de.wikipedia.org/wiki/Harvard-Architektur) - Programmspeicher und Datenspeicher sind getrennt. Gespart werden muss aber bei beiden. Wer den Microtronic kennt, weiß den Wert eines einzelnen Bytes noch zu schätzen. Wer das Byte nicht ehrt, ist des RAMs nicht wert... Zum Glück ist das meine Seite, deswegen darf ich so viel abschweifen wie ich möchte. Also noch eine völlig unbedeutende Anekdote an dieser Stelle: Für den ZX81 (1 KB RAM!) schrieb nach meiner Erinnerung seinerzeit jemand mal ein Schachprogramm. Gerüchtehalber lief es wohl, aber war natürlich vollkommen unlesbar. Naja, und auch nicht sehr stark...

Leider vergisst der 2090 alle seine mühevoll von Menschenhirn ersonnenen und Menschenfinger eingegebenen Programmschritte, sobald (versehentlich natürlich) die Steckdose etwa dem Staubsauger weichen musste. Es wurde Zeit, die Programmentwicklung zu professionalisieren. Ein Simulator und/oder eine Speichermöglichkeit und/oder ein Assembler wären doch wirklich nützlich. Zum Glück hat [Martin Sauter](https://blog.wirelessmoves.com/) das Protokoll für das optional erhältliche [Kassetten-Interface 2095](https://blog.wirelessmoves.com/2017/06/emulating-a-busch-2090-tape-interface-part-1.html) _reverse-engineered_ und als Python-Programm für den Raspberry Pi zur Verfügung gestellt. Und auch einen [Assembler für den 2090](https://blog.wirelessmoves.com/2017/07/an-assembler-for-the-busch-2090.html) geschrieben, der auf Calc ([LibreOffice](https://de.libreoffice.org/)) läuft. 

Fortan konnte ich also am PC entwickeln, über Calc mit aktivierten Makros assemblieren (assembeln?), über WLAN und SFTP an den Raspi Pico W senden, von dort mit Python an den Microtronic übertragen, da mit HALT-PGM-1 empfangen und mit HALT-NEXT-00-RUN starten sowie schließlich alle meine Programmierfehler bestaunen. Schokolade!


## Timing des Arduino/Raspi

Der 2090 ist nicht schnell. Michael hat ein paar [Performance-Tests](https://www.youtube.com/watch?v=e8KJ-cnX9bU) durchgeführt und als Ergebnis maximal 114 Operationen pro Sekunde (1,14 HIPS) ermittelt. Da in meinem Programm das Display meistens aktiv ist, dürfte eher ein Wert von 40 _Instructions per second_ (0,4 HIPS) zu erwarten sein. Welche Dauer der Befehl KIN zum Einlesen der 4 Bits an den Eingängen beansprucht und wie er ausgeführt wird (sequentiell, parallel, quantenmechanisch o.ä.), ist im Detail nicht bekannt, aber es ist klar, dass Timing ein Faktor sein kann. Wenn die Peripherie die Zufallszahlen zu langsam liefert, wird der gleiche Wert mehrfach im Programm eingelesen, wenn die Zufallszahlen hingegen zu schnell geliefert werden, wird der Wert während des Einlesens möglicherweise "verschmiert", da sich die Bits durch eine in der Zwischenzeit neu erzeugte Zufallszahl verändern können. Dieser zweite Fall wird noch ein richtiges Problem, dazu später...

Eine saubere Lösung, um Timing-Probleme zu vermeiden, wäre: Immer wenn eine Zufallszahl benötigt wird, geben wir dem Zahlen-Lieferanten ein Signal. Der _Raspuino_<sup>TM</sup> erzeugt die Zahl, liefert sie über seine GPIO an die Eingänge des 2090, hält sie da ausreichend lange stabil und wartet dann einfach auf die nächste Zahlen-Bestellung. Das erforderte aber zusätzliche Befehle im Programmcode des 2090 (Wert in Register speichern, Register auf Ausgang legen, ggf. warten auf die Lieferung usw.) Und ein extra Kabel. Und ein wertvolles Register - wir haben nur 16 Stück brauchbare. Nope, scheidet (erstmal) aus.

## Testen ist am besten

Zur Überprüfung meiner Überlegungen und zur Ermittlung des richtigen/besten Lieferintervalls für Zufallszahlen habe ich ein bisschen mit ChatGPT geplaudert und wir haben uns auf folgendes Python-Programm geeinigt (für den Raspi, der Arduino wanderte erstmal zurück in die Schublade). Meine programmiertechnische Eigenleistung bestand darin, die richtigen GPIOs einzutragen und das Intervall zwischen den erzeugten Zahlen zu wählen. 

```
import RPi.GPIO as GPIO
import random
import time

# Setze die GPIO-Pins
pins = [12, 21, 20, 16]  # Beispiel GPIO-Pins, bitte an deine Konfiguration anpassen

def setup():
    GPIO.setmode(GPIO.BCM)
    for pin in pins:
        GPIO.setup(pin, GPIO.OUT)

def generate_random_number():
    return random.randint(0, 9)

def decimal_to_binary(decimal_number):
    return bin(decimal_number)[2:].zfill(4)

def output_to_pins(binary_string):
    for index, pin in enumerate(pins):
        GPIO.output(pin, int(binary_string[index]))

def main():
    try:
        setup()
        while True:
            random_number = generate_random_number()
            binary_number = decimal_to_binary(random_number)
            output_to_pins(binary_number)
            print("Zufallszahl:", random_number, "Binär:", binary_number)
            time.sleep(0.05)  # Wartezeit in Sekunden
    except KeyboardInterrupt:
        print("\nProgramm wurde beendet.")
    finally:
        GPIO.cleanup()

if __name__ == "__main__":
    main()
```

### Annahmen

What if? Zahlen von 0-9 werden geliefert. Aber werden sie auch eingelesen? ASSERT gibt es im Microtronic Befehlssatz nicht. Im Programmcode wird auf das letzte CMPI verzichtet, weil andernfalls "es ja eine Null/Neun sein muss". Aber was wenn nicht? 

## Addition und Subtraktion, Schiebung und Anzeige

Im Programm müssen 

- der Spieleinsatz von 20 Pf abgezogen,
- eventuell Gewinne im Bereich von 20 Pf bis 2 DM dazugezählt,
- eventuell jeweils ein Sonderspiel (sofern vorhanden) abgezogen und
- eventuell gewonnene Sonderspiele (2, 5, 10, 20 oder 50) dazugezählt werden.

Zunächst hatte ich für Addition und Subtraktion - schön ordentlich und strukturiert - jeweils separate Unterprogramme geschrieben. Der 2090 rechnet Plus und Minus registerweise hexadezimal, also mussten für eine dezimale Darstellung jeweils Dezimalkorrektur und Carry-Flag-Übertrag berücksichtigt werden. Kurzum komplex, die Routinen für eine bis zu 3-stellige dezimale Plus- oder Minus-Operation waren lang und belegten deutlich zu viel Platz im Programmspeicher. So wird das nix.

Die erste Entscheidung war: Ich halte alles hexadezimal in den Registern und wandele es nur bei Bedarf, also für die Anzeige, in Dezimalwerte um. Dazu stehen im Befehlssatz erfreulicherweise zwei formschöne Instruktionen zur Verfügung: HXDZ und DZHX, die den Inhalt der Register D bis F jeweils umrechnen. Damit war auch klar, dass der _Münzspeicher_ in den Registern D bis F residieren wird, denn dadurch konnte ich die vielen MOV-Befehle sparen, mit denen ich sonst Werte in den Registern hätte hin- und herschieben müssen. 

```
Anzeige		HXDZ				Konvertierung in Dez
		MOVI #F,ZÄHLER	
pause1		SUBI #1,ZÄHLER	
		BRZ pauseEnde	
		GOTO pause1	
pauseEnde	DZHX				Konvertierung in Hex
		RET				
```

Aber ich habe ja nicht nur den 3-stelligen Münzspeicher, sondern auch den _Sonderspiele-Zähler_... Wohin damit? Ich müsste den ja temporär in die Register D-F schieben, damit Umrechnung und Anzeige erfolgen können. Schon wieder jede Menge MOVes :-( 

Neben den 16 Arbeitsregistern gibt es beim Microtronic noch 16 Speicherregister. Spricht irgendwas dagegen, die Sonderspiele (die man meistens sowieso nicht hat), im "Schatten", also in den **Speicher**registern D-F zu halten und diese bei Bedarf zur Anzeige oder Berechnung einfach elegant einzublenden mit dem Befehl EXRM, der praktischerweise in einem Rutsch alle Arbeitsregister 8-F mit den entsprechenden Speicherregistern 8-F tauscht? Nein? Spart viel "Schiebung", also ist das so beschlossen.



Halt, es gibt ja EXRA, den Befehl, mit dem in einem Rutsch alle Speicherregister von 0-7 mit denen von 8-F getauscht werden. Spart viel "Schiebung", dann müsste der Sonderspiele-Zähler also notwendigerweise in die Register 5 bis 7... Hmmm... Check.

Mir war noch vage von der Uni in Erinnerung, dass binäre Subtraktion ja auch nichts anderes als Addition mit der Inversen des Subtrahenden plus 1 ist. Wer´s nicht glaubt, prüft es nach. Also konnte ich die Rechen-Routinen zu einer einzigen zusammenfassen; es wird nur addiert. Da nur zwei feste Werte (20 Pf, 1 Spiel) ggf. zu subtrahieren sind, konnte ich diese im Programm "fest verdrahten" (die Werte FFE und FFF werden _subtraddiert_<sup>TM</sup>). Insgesamt wurde dadurch das _Rechenwerk_ des Monarchen angenehm schlank und viele Programmschritte wurden eingespart. Ob das Programm dadurch auch übersichtlicher wurde, darf allerdings bezweifelt werden.

```
DeltaSub	MOVI #F,DELTA_E			Einsprungadresse für Subtraktion (Addition mit invertiertem HEX-Wert + 1)
	        MOVI #F,DELTA_F	
DeltaAdd	ADD DELTA_D,rD	
	        ADC rE	
	        ADC rF	
	        ADD DELTA_E,rE	
	        ADC rF	
	        ADD DELTA_F,rF	              wegen mögl. Subtraktion auch letzte Stelle “addieren”
	        RET
```

## Schleifentricks

Wir erinnern uns: Um eine Warteschleife für die Anzeige zu realisieren, hatte ich den Startwert F in ein Register gespeichert, davon solange 1 abgezogen, bis der Wert 0 im Register erreicht, dadurch das Zero-Flag gesetzt wurde und die Schleife dann mit BRZ verlassen wurde. Unterm Strich also 4 Instruktionen. Geht das nicht besser?

Doch. Statt der beiden Sprung-Befehle BRZ (bei 0 raus aus der Schleife) und GOTO (bei nicht-0 zum Schleifenfang) auf den SUBI-Befehl vertrauen, der das Carry-Flag bei einem Unterlauf setzt. Und statt 1 immer F abziehen, so dass bei fast jeder Subtraktion ein Unterlauf entsteht - außer bei F - F = 0.

```

Anzeige		HXDZ				Konvertierung in Dez
		MOVI #0,ZÄHLER	
pause1		SUBI #F,ZÄHLER	
		BRC pause1			nur bei F - F = 0 nicht erfüllt, also Schleifenexit
		DZHX				Konvertierung in Hex
		RET	
```

Juhuu, eine Instruktion eingespart. Im Kopf können wir nicht so gut F von einem Register abziehen und mit irgendwelchen Unter- und Überläufen hantieren, wir möchten automatisch lieber 1 von einem vorher gegebenen Startwert abziehen - dem Computer ist es aber schnuppe.

## Nullerkennung

Wir ziehen regelmäßig 20 Pf bzw. 1 Spiel von den Speichern für Geld und Sonderspiele ab. Wie können wir dann erkennen, ob einer von diesen Speichern leer ist? Denn dann müsste der Automat ja anhalten bzw. den Sonderspiele-Status zurücksetzen. Natürlich könnte ich alle 3 Register D-F einzeln auf Null testen in einer verschachtelten CMPI-Konstruktion... Aber wie viele Instruktionen das wieder kosten würde! :-(

Es wird einfach die übliche Vor-dem-Spiel-Subtraktion erneut ausgeführt. Wenn einer dieser Speicher leer ist (also 0), dann entsteht durch die Subtraktion ein Wert "Fxx", also steht anschließend definitiv im Register F der Wert F. Und nur auf diesen müssen wir anschließedn testen, um zu erkennen, dass der Speicher leer ist/war.  

Nun, da das Problem der Nullerkennung gelöst ist, bleibt noch das Aufräumen in den Speichern. Immerhin steht da ja hexadezimal irgendwas mit Fxx drin (über 380 DM). Man könnte alles wieder mit MOVI #0 löschen. Ist das nötig? 

Nö. Für die Anzeige wird der hexadezimale Wert (Geld oder Sonderspiele) jeweils mit HXDZ in einen dezimalen umgewandelt. Undokumentiert ist folgendes Verhalten: HXDZ ist so freundlich, einen hexadezimal zu großen Wert (größer als 3E7, also dezimal 999) in den Registern D-F in eine komfortable 0 in all diesen Registern umzuwandeln. Also einfach nochmal anzeigen lassen, und schon wird aus einer theoretischen Null auch eine praktische Null. Check.

Übrigens: Findige, mit der nötigen kriminellen Energie ausgestattete Menschen sollen natürlich versucht haben, mit allerlei Werkzeugen und Drähten das 10-DM-Relais beim Stand von 0 zu einem klitzekleinen weiteren Abzug-Impuls zu überreden. Und ruckzuck wurden aus 0,20 DM Guthaben dann 90,20 DM. Auszahlknopf gedrückt und nix wie raus aus der Kneipe... Hatte ich schon erwähnt, dass fast überall 230 Volt im Gerät anliegen?

## Kleinigkeiten

Bei der Darstellung der Walzen habe ich die doppelt vorhandenen - also häufiger auftretenden - Walzenstellungen erst an das Ende der Auswertung gesetzt. Dadurch ist der (erwünschte) optische _Würfel-Effekt_ mit höherer Wahrscheinlichkeit länger zu sehen.

# Was fehlt?

Alle 256 Programmschritte sind mehr oder weniger verbraucht. ~~Wahrscheinlich~~ Mit Sicherheit kann man an der einen oder anderen Stelle noch etwas herausmelken, aber es wird schwierig. Falls sich doch jemand damit beschäftigen will, ich bin dankbar für jede Idee. Ich vermute z.B., dass die Auswertung des Tableaus bei Sonderspielen noch irgendwie optimiert werden kann.

## Nachstarten 

Der echte Monarch bietet die Möglichkeit, die erste Walze einmalig in jedem Spiel nochmal zu starten, wenn die angezeigte Kombination nicht gefällt. Man kann also gezielt "auf Sonderspiele" spielen, weil man dafür ja König oder Krone als Symbol auf der ersten Walze haben will. 

Um diese Funktion auch noch zu integrieren, wäre es nötig, innerhalb der Warteschleife auf einen Tastendruck an einem Eingang (also ohne Anhalten des Programms) zu warten. Aber alle vier Eingänge sind derzeit schon vom Zufallszahlen-Lieferanten belegt.

Ein paar Ideen hab ich dazu:

- Der Raspuino möge schweigen, solange er nicht gebraucht wird. Das bedeutet, er bekommt über einen Ausgang das Signal, eine Zufallszahl zu liefern. Würde wahrscheinlich auch alle möglichen Timing-Probleme lösen. Dann könnte man eine Taste "parallel" auf einen der Eingänge legen, und dieser Eingang wird dann während der Warteschleife geprüft, ob Taste gedrückt oder nicht... Aaaber. Jede Erzeugung einer Zufallszahl erforderte dann mindestens 2 Befehle (statt bisher einen). Ein Kabel zusätzlich wäre auch nötig.  

- Der Raspuino liefert nur Zufallszahlen von 0-7. Das würde reichen, denn mehr als 8 Symbolkombinationen gibt es auf keiner Walze. Man müsste die Walzen-Wahrscheinlichkeitsverteilung dann dem Raspuino überlassen, also bestimmte Zufallszahlen müssten doppelt so häufig wie andere erzeugt werden (da 2x auf der Walze vorhanden). Dann müsste man dem Zahlen-Lieferanten aber auch mitteilen, für welche Walze die nächste Zufallszahl erzeugt werden soll, da die Kombinationen auf den Walzen unterschiedliche Häufigkeiten haben. Auch hier wird ein "Rückkanal" vom 2090 zur Peripherie benötigt.

- Die Taste wird an einen Eingang des Raspuino gelegt. Wenn gedrückt, erzeugt der Raspuino eine "unmögliche" Zahl für die zweite Walze, z.B. "F", welche dann vom Programm erkannt wird und einen Sprung zurück zu Walze 1 auslöst. Ebenso: Rückmeldung nötig.

In jedem Fall wäre es wahrscheinlich gut, wenn der Raspuino wüsste, welche Walze gerade mit einer Zufallszahl zu versorgen ist. Allerdings - und das ist der Nachteil - könnte man dann ja auch gleich die ganze Simulation auf dem Raspuino laufen lassen .-(

Ich denke darüber nach.

## Ton bei Gewinn von 1,60 DM

Ist nicht, musste dem Sparzwang geopfert werden. Denn 16 ist hexadezimal 10, das heißt im Delta-Register 5 steht eine Null - und genau dieses Register wird geprüft, ob ein Gewinn vorliegt. Natürlich könnte man die Prüfung allumfassend über beide Delta-Register vornehmen, aber dafür war kein Platz mehr.

## Sonderspiele-Stopp

Der 40-Kilo-Monarch hat ein "Sonderspiele-Stop-Relais" eingebaut. Das heißt, wenn man den Volltreffer mit 50 Sonderspielen gelandet hat, können keine weiteren Verlängerungen der Serie erzielt werden (also ist das Verlängerungs-Tableau danach inaktiv). Mit anderen Worten, der Monarch lässt dich wissen: "Du hast genug gewonnen, jetzt reicht´s aber mal!" Aber das erleben wir nicht, dafür ist die Wahrscheinlichkeit einfach zu gering und/oder das Leben zu kurz.

Also YAGNI.

## Hexadezimalzahlen sind kurz zu sehen

Jaaa, da müsste man noch ein paar mehr DISOUTs einbauen, bevor die Umwandlung vorgenommen wird. Aber - kein Platz dafür, und so schlimm sieht´s nicht aus. Ich lass das jetzt so.




