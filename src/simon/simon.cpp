#include <Arduino.h>
#include "simon.h"

void add_note_to_level() {
    int random_light = random(0, 4);
    switch(random_light) {
        case 0:
            sequence.push_back(pins::blue);
            notes::play_blue();
            delay(100);
            break;
        case 1:
            sequence.push_back(pins::red);
            notes::play_red();
            delay(100);
            break;
        case 2:
            sequence.push_back(pins::yellow);
            notes::play_yellow();
            delay(100);
            break;
        case 3:
            sequence.push_back(pins::green);
            notes::play_green();
            delay(100);
            break;
    }
}

void new_round() {
    // rotate through lights
    for (int i = 0; i < 4; i++) {
        digitalWrite((uint8_t) pins::blue, HIGH);
        delay(100);
        digitalWrite((uint8_t) pins::blue, LOW);
        digitalWrite((uint8_t) pins::red, HIGH);
        delay(100);
        digitalWrite((uint8_t) pins::red, LOW);
        digitalWrite((uint8_t) pins::yellow, HIGH);
        delay(100);
        digitalWrite((uint8_t) pins::yellow, LOW);
        digitalWrite((uint8_t) pins::green, HIGH);
        delay(100);
        digitalWrite((uint8_t) pins::green, LOW);
    }
}

void all_lights_on() {
    digitalWrite((uint8_t) pins::blue, HIGH);
    digitalWrite((uint8_t) pins::yellow, HIGH);
    digitalWrite((uint8_t) pins::green, HIGH);
    digitalWrite((uint8_t) pins::red, HIGH);
}

void all_lights_off() {
    digitalWrite((uint8_t) pins::blue, LOW);
    digitalWrite((uint8_t) pins::yellow, LOW);
    digitalWrite((uint8_t) pins::green, LOW);
    digitalWrite((uint8_t) pins::red, LOW);
}

void simon_setup() {
    randomSeed(analogRead(0));
    notes::setup_pins();
    sequence.clear();
    add_note_to_level();
    new_round();
}

void simon_loop() {
    if (sequence.size() <= max_level) {
        add_note_to_level();
        delay(1000);
    } else {
        notes::play_all();
        delay(100);
        notes::play_all();
        delay(100);
        notes::play_all();
    }
    
    
    for (uint8_t i = 0; i < sequence.size(); i++) {
        notes::play(sequence[i]);
        delay(100);
    }
}