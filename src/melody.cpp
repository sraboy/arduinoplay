#include "pitches.h"
#include <Arduino.h>

const struct _note { 
    const int 
    g3 = NOTE_G3,
    a4 = NOTE_A4,
    b4 = NOTE_B4, 
    c4 = NOTE_C4, 
    d4 = NOTE_D4,
    e4 = NOTE_E4,
    f4 = NOTE_F4,
    g4 = NOTE_G4,
    c5 = NOTE_C5, 
    g5 = NOTE_G5;
} note;

const struct _duration { 
    const int 
    eighth = 125, 
    quarter = 250, 
    half = 500, 
    whole = 1000; 
} duration;

const struct _camptown_races {
    const static int length = 21;
    const int melody[length] = {
        note.a4, note.a4, note.a4, note.f4,
        note.a4, note.b4, note.a4, note.f4,
        note.f4, note.e4, note.f4, note.e4,
        note.a4, note.a4, note.a4, note.f4,
        note.e4, note.g4, note.f4, note.e4, 
        note.d4
    };
} camptown_races;

const int out_pin = 8;



void melody_setup() {
    int dur = duration.quarter * 1.3;
    for(int n = 0; n < camptown_races.length; n++) {
        tone(out_pin, camptown_races.melody[n], duration.quarter);
        delay(dur);
        noTone(out_pin);
    }
}

void melody_loop() { }