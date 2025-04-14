#include "pitches.h"
#include <Arduino.h>

const struct _pins {
    const int8_t blue = 13;
    const int8_t red = 12;
    const int8_t yellow = 11;
    const int8_t green = 10;
    const int8_t speaker = 9;
} pins;

class notes {
    private: 
        notes() {}
        ~notes() {}
    public:
        static void setup_pins() {
            pinMode(pins.blue, OUTPUT);
            pinMode(pins.yellow, OUTPUT);
            pinMode(pins.green, OUTPUT);
            pinMode(pins.red, OUTPUT);
        }
        
        static void play_blue() {
            digitalWrite(pins.blue, HIGH);
            delay(100);
            digitalWrite(pins.blue, LOW);

            tone(pins.speaker, 1000, 100);
            delay(100);
            noTone(pins.speaker);
        }

        static void play_red() {
            digitalWrite(pins.red, HIGH);
            delay(100);
            digitalWrite(pins.red, LOW);

            tone(pins.speaker, 2000, 100);
            delay(100);
            noTone(pins.speaker);
        }
        static void play_yellow() {
            digitalWrite(pins.yellow, HIGH);
            delay(100);
            digitalWrite(pins.yellow, LOW);

            tone(pins.speaker, 3000, 100);
            delay(100);
            noTone(pins.speaker);
        }
        static void play_green() {
            digitalWrite(pins.green, HIGH);
            delay(100);
            digitalWrite(pins.green, LOW);

            tone(pins.speaker, 4000, 100);
            delay(100);
            noTone(pins.speaker);
        }
        static void play_all() {
            digitalWrite(pins.blue, HIGH);
            digitalWrite(pins.red, HIGH);
            digitalWrite(pins.yellow, HIGH);
            digitalWrite(pins.green, HIGH);

            tone(pins.speaker, 5000, 100);
            delay(100);
            noTone(pins.speaker);

            digitalWrite(pins.blue, LOW);
            digitalWrite(pins.red, LOW);
            digitalWrite(pins.yellow, LOW);
            digitalWrite(pins.green, LOW);
        }
};

void all_lights_on();
void new_round();

void lights_setup() {
    notes::setup_pins();
}

void lights_loop() {
    new_round();

    notes::play_blue();
    delay(500);
    notes::play_red();
    delay(500);
    notes::play_yellow();
    delay(500);
    notes::play_green();
    delay(500);
    notes::play_all();
    delay(500);
    all_lights_on();
}

void new_round() {
    // rotate through lights
    for (int i = 0; i < 4; i++) {
        digitalWrite(pins.blue, HIGH);
        delay(100);
        digitalWrite(pins.blue, LOW);
        digitalWrite(pins.red, HIGH);
        delay(100);
        digitalWrite(pins.red, LOW);
        digitalWrite(pins.yellow, HIGH);
        delay(100);
        digitalWrite(pins.yellow, LOW);
        digitalWrite(pins.green, HIGH);
        delay(100);
        digitalWrite(pins.green, LOW);
    }
}

void all_lights_on() {
    digitalWrite(pins.blue, HIGH);
    digitalWrite(pins.yellow, HIGH);
    digitalWrite(pins.green, HIGH);
    digitalWrite(pins.red, HIGH);
}