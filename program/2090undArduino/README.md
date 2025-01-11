# Monarch2090 mit Arduino Nano

In dieser Variante benutzt du das gleiche Programm wie bei der Variante [Busch 2090 und 2075](/program/2090und2075), lediglich eine andere Peripherie wird verwendet - statt eines 2075-Zählerbausteins liefert ein Arduino Nano die Zufallszahlen und überwacht den Taster für den Nachstart der linken Walze. 

Der Nano möchte seine digitalen Ausgänge maximal mit 40 mA belastet sehen, typischerweise sogar nur mit 20 mA. Die Eingänge des Microtronic haben jeweils 100 Ohm gegen GND. Das würde dann durch die Arduino-Ausgänge bei 5V jeweils 50 mA Strom fließen lassen. Aua. Daher - um auf der ganz sicheren Seite zu sein - 1 kOhm-Widerstände vor den Eingängen des Microtronic!

![Schaltplan](/pics/SchaltungArduino.png)

## Stromversorgung

Wenn du mutig bist, kannst du die Stromversorung für den Arduino (+5V) vom 2090 abzweigen. Das spart ein Netzteil. Dazu müsstest du den richtigen Pin am Verbindungssockel zum 2095 anzapfen... mehr verrate ich nicht, mach nix kaputt! Weniger Mutige geben dem Nano seine 5 Volt mit einem USB-Netzteil und einem entsprechenden Kabel.

## Sketch

Der Sketch für den Nano:

```
unsigned int z;
unsigned int taste;
unsigned int m2090Out4;
unsigned int m2090Out3;

void setup() {
  pinMode(5, OUTPUT);           // m2090In1
  pinMode(4, OUTPUT);           // m2090In2
  pinMode(3, OUTPUT);           // m2090In3
  pinMode(2, OUTPUT);           // m2090In4
  pinMode(6, INPUT);            // m2090Out4
  pinMode(7, INPUT);            // m2090Out3
  pinMode(8, INPUT_PULLUP);     // taste
  randomSeed(analogRead(A0));
}
 
void loop() {
  
  taste = 0;
  z = 0;
  setOutputs();
  
  m2090Out4 = 0;
  m2090Out3 = 0;
  while (!(m2090Out4 || m2090Out3)) {
    m2090Out4 = digitalRead(6);
    m2090Out3 = digitalRead(7);
  }

  if (m2090Out4) {
    z = random(10);
    setOutputs();
    while (m2090Out4) {
      m2090Out4 = digitalRead(6);
    }
  }

  if (m2090Out3) {
    while (m2090Out3) {
      m2090Out3 = digitalRead(7);
      taste = digitalRead(8);
      if (!taste) {
        z = 1;
        setOutputs();
      }
    }
  }

}

void setOutputs() {
  // an Ausgänge binär legen
  digitalWrite(5,z&1);
  z = z >> 1;
  digitalWrite(4,z&1);
  z = z >> 1;
  digitalWrite(3,z&1);
  z = z >> 1;
  digitalWrite(2,z&1);
}
```

Bei mir läuft der Sketch auf einem Nano 168, den ich noch irgendwo gefunden hatte. Ein Arduino Nano 3.0 mit 328P-Chip sollte natürlich auch funktionieren. 

## Taster 

Der Taster übrigens hängt am D8-Anschluss des Arduino, welcher im Code als digitaler Eingang mit internem Pullup-Widerstand definiert ist (der Nano hat keine internen Pulldown-Widerstände). Damit ist dieser Arduino-Eingang ohne Betätigung des Tasters immer High. Nur bei Tastendruck wird der Eingang auf Low gezogen. 

## Timing

Verschiedentlich wurde bemängelt, dass der _digitalWrite_-Befehl des Arduino ziemlich langsam sei (ca. 2,2 Mikrosekunden). Der Sketch wartet in einer Schleife darauf, dass D6 high wird, macht dann noch ein bisschen Vergleich, wirft den Zufallsgenerator an, springt in ein Unterprogramm und legt schließlich Bit für Bit die Zahl auf die Ausgänge D2-D5. Es dauert also mindestens 4 x 2,2 = 8,8 Mikrosekunden, bis die Zufallszahl stabil binär an den Ausgängen anliegt. Mit dem ganzen Overhead wahrscheinlich doppelt so lange, sagen wir mal 20 **Mikro**sekunden.

Zum "Glück" ist der Microtronic noch viel langsamer. Wie Michael Wessel ermittelt hat, liegen wir bei etwa 0,4 Hips (also 40 Instruktionen pro Sekunde), wenn das Display des 2090 aktiv ist - das heißt 25 **Milli**sekunden pro Befehl. 

Milli = 1000 x Mikro. Wir dürfen also davon ausgehen, dass der Arduino seine Arbeit an seinen Ausgängen längst erledigt hat, wenn der Microtronic die Zahlenlieferung an seinen Eingängen erwartet.
