int pin13 = 13;
int pin12 = 12;
int pin11 = 11;

int pin10 = 10;
int pin9 = 9;
int pin8 = 8;

int pin7 = 7;
int pin6 = 6;
int pin5 = 5;

int pin4 = 4;
int pin3 = 3;
int pin2 = 2;

int phase = 0;
int x;

void setup() {
  pinMode(pin13, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin2, OUTPUT);

  Serial.begin(9600);
  Serial.setTimeout(1);
}

void sinal_amarelo(int phase) {
  if (phase == 1) {
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    delay(500);
    digitalWrite(pin3, LOW);
  }
  else if (phase == 2) {
    digitalWrite(pin5, LOW);
    digitalWrite(pin6, HIGH);
    delay(500);
    digitalWrite(pin6, LOW);
  }
  else if (phase == 3) {
    digitalWrite(pin8, LOW);
    digitalWrite(pin9, HIGH);
    delay(500);
    digitalWrite(pin9, LOW);
  }
  else {
    digitalWrite(pin11, LOW);
    digitalWrite(pin12, HIGH);
    delay(500);
    digitalWrite(pin12, LOW);
  }
}

void phase_1() {
  digitalWrite(pin13, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin2, HIGH);
  
  digitalWrite(pin11, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void phase_2() {
  digitalWrite(pin13, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin4, HIGH);
        
  digitalWrite(pin11, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin7, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
}

void phase_3() {
  digitalWrite(pin13, HIGH);
  digitalWrite(pin8, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin4, HIGH);
        
  digitalWrite(pin10, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin9, LOW);
  digitalWrite(pin11, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
}

void phase_4() {
  digitalWrite(pin11, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin4, HIGH);
        
  digitalWrite(pin13, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin9, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
}

void loop() {
  if (Serial.available()) {
    String msg = Serial.readString();

    if (msg == "1") {
      if (phase != 1) {
        sinal_amarelo(phase);
      }
      phase = 1;
      phase_1();
    }
    else if (msg == "2") {
      if (phase != 2) {
        sinal_amarelo(phase);
      }
      phase = 2;
      phase_2();
    }
    else if (msg == "3") {
      if (phase != 3) {
        sinal_amarelo(phase);
      }
      phase = 3;
      phase_3();
    }
    else if (msg == "4") {
      if (phase != 4) {
        sinal_amarelo(phase);
      }
      phase = 4;
      phase_4();
    }
  }
}


