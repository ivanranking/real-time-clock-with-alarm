void setup() {
  pinMode(11, OUTPUT); // Buzzer pin
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    if (data.startsWith("A:")) {
      digitalWrite(11, HIGH); // Turn on buzzer
      delay(120000); // Keep buzzer on for 2 minutes
      digitalWrite(11, LOW); // Turn off buzzer
    }
  }
}
