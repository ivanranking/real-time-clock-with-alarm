#include <Wire.h>

#define setButton 8
#define resetButton 9
#define snoozeButton 10

int alarmHour = 8;  // Set default alarm time
int alarmMinute = 0;

void setup() {
  pinMode(setButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
  pinMode(snoozeButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    if (data.startsWith("T:")) {
      int firstComma = data.indexOf(',');
      int secondComma = data.indexOf(',', firstComma + 1);

      int hour = data.substring(2, firstComma).toInt();
      int minute = data.substring(firstComma + 1, secondComma).toInt();

      if (hour == alarmHour && minute == alarmMinute) {
        Serial.println("A:Alarm");
      }
    }
  }

  // Check buttons
  if (digitalRead(setButton) == LOW) {
    // Code to set the alarm time
    // ...
  }
  if (digitalRead(resetButton) == LOW) {
    // Code to reset the alarm
    // ...
  }
  if (digitalRead(snoozeButton) == LOW) {
    // Code to snooze the alarm
    // ...
  }
}
