#include "Scheduler.h"
#include <MFRC522.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  Scheduler.startLoop(loop2);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(5000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);  
  
}

void loop2() {
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    data++;
    Serial.println(data);
  }
  yield();
}
