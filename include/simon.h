#include <Arduino.h>
#include <ArduinoSTL.h>

enum class pins {
    blue = 13,
    red = 12,
    yellow = 11,
    green = 10,
    speaker = 9
};

class notes {
    private: 
        notes() {}
        ~notes() {}
    public:
        static void setup_pins() {
            pinMode((uint8_t) pins::blue, OUTPUT);
            pinMode((uint8_t) pins::yellow, OUTPUT);
            pinMode((uint8_t) pins::green, OUTPUT);
            pinMode((uint8_t) pins::red, OUTPUT);
        }
        
        static void play(pins pin) {
            switch(pin) {
                case pins::blue:
                    play_blue();
                    break;
                case pins::red:
                    play_red();
                    break;
                case pins::yellow:
                    play_yellow();
                    break;
                case pins::green:    
                    play_green();
                    break;
                default:
                    break;
            }
        }

        static void play_blue() {
            digitalWrite((uint8_t) pins::blue, HIGH);
            delay(100);
            digitalWrite((uint8_t) pins::blue, LOW);

            tone((uint8_t) pins::speaker, 1000, 100);
            delay(100);
            noTone((uint8_t) pins::speaker);
        }

        static void play_red() {
            digitalWrite((uint8_t) pins::red, HIGH);
            delay(100);
            digitalWrite((uint8_t) pins::red, LOW);

            tone((uint8_t) pins::speaker, 2000, 100);
            delay(100);
            noTone((uint8_t) pins::speaker);
        }
        static void play_yellow() {
            digitalWrite((uint8_t) pins::yellow, HIGH);
            delay(100);
            digitalWrite((uint8_t) pins::yellow, LOW);

            tone((uint8_t) pins::speaker, 3000, 100);
            delay(100);
            noTone((uint8_t) pins::speaker);
        }
        static void play_green() {
            digitalWrite((uint8_t) pins::green, HIGH);
            delay(100);
            digitalWrite((uint8_t) pins::green, LOW);

            tone((uint8_t) pins::speaker, 4000, 100);
            delay(100);
            noTone((uint8_t) pins::speaker);
        }
        static void play_all() {
            digitalWrite((uint8_t) pins::blue, HIGH);
            digitalWrite((uint8_t) pins::red, HIGH);
            digitalWrite((uint8_t) pins::yellow, HIGH);
            digitalWrite((uint8_t) pins::green, HIGH);

            tone((uint8_t) pins::speaker, 5000, 100);
            delay(100);
            noTone((uint8_t) pins::speaker);

            digitalWrite((uint8_t) pins::blue, LOW);
            digitalWrite((uint8_t) pins::red, LOW);
            digitalWrite((uint8_t) pins::yellow, LOW);
            digitalWrite((uint8_t) pins::green, LOW);
        }
};

void all_lights_on();
void all_lights_off();
void new_round();
void add_note_to_level();

// current game level/sequence
std::vector<pins> sequence;

const int max_level = 20;
