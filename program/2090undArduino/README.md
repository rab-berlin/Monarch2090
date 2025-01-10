Der Arduino möchte seine digitalen Ausgänge maximal mit 40 mA belastet sehen, typischerweise auch nur mit 20 mA. Die Eingänge des Microtronic haben jeweils 100 Ohm gegen GND. Das würde bei 5V dann aber 50 mA Strom fließen lassen. Wahrscheinlich auch verkraftbar für den Arduino, aber um auf der ganz sicheren Seite zu sein: 1 kOhm-Widerstände vor den Eingängen!

![Schaltplan](/pics/SchaltungArduino.png)

Wenn du mutig bist, kannst du die Stromversorung für den Arduino (+5V) vom 2090 abzweigen. Das spart ein Netzteil. Dazu müsstest du den richtigen Pin am Verbindungssockel zum 2095 anzapfen... mehr verrate ich nicht.

Der Sketch für den Arduino Nano:

```
unsigned int z;
unsigned int taste;
unsigned int m2090Out4;
unsigned int m2090Out3;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, INPUT); // m2090Out4
  pinMode(7, INPUT); // m2090Out3
  pinMode(8, INPUT_PULLUP); // taste
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


