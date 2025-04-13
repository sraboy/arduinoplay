#include <stdint.h>
#include <Arduino.h>

#include "projects.h"

const int8_t LED_PIN = 10;
int8_t brightness = 0;
int8_t fade = 5;

void fade_setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
}

void fade_loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LED_PIN, brightness);
  brightness += fade;

  if (brightness <= 0 || brightness >= 255)
    fade = -fade;
  
  delay(30);
}
