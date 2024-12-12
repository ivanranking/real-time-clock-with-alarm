#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  // Uncomment to set the RTC to the current date & time
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();
  Serial.print("T:");
  Serial.print(now.hour());
  Serial.print(",");
  Serial.print(now.minute());
  Serial.print(",");
  Serial.println(now.second());

  delay(1000);
}
