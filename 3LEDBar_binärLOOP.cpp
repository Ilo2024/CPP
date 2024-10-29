byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 28};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 8; j++) {
      digitalWrite(ledPins[j], bitRead(i, j));
    }
    delay(500);
  }
}
