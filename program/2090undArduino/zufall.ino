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

