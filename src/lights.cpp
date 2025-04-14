#include "pitches.h"
#include <Arduino.h>

const struct _leds {
    const int8_t blue = 13;
    const int8_t red = 12;
    const int8_t yellow = 11;
    const int8_t green = 10;
} leds;

void lights_on();
void new_round();

void lights_setup() {
    pinMode(leds.blue, OUTPUT);
    pinMode(leds.yellow, OUTPUT);
    pinMode(leds.green, OUTPUT);
    pinMode(leds.red, OUTPUT);
}

void lights_loop() {
    new_round();
}

void new_round() {
    // rotate through lights
    for (int i = 0; i < 4; i++) {
        digitalWrite(leds.blue, HIGH);
        delay(100);
        digitalWrite(leds.blue, LOW);
        digitalWrite(leds.red, HIGH);
        delay(100);
        digitalWrite(leds.red, LOW);
        digitalWrite(leds.yellow, HIGH);
        delay(100);
        digitalWrite(leds.yellow, LOW);
        digitalWrite(leds.green, HIGH);
        delay(100);
        digitalWrite(leds.green, LOW);
    }
}

void lights_on() {
    digitalWrite(leds.blue, HIGH);
    digitalWrite(leds.yellow, HIGH);
    digitalWrite(leds.green, HIGH);
    digitalWrite(leds.red, HIGH);
}