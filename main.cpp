#include "mbed.h"
#include <string>
#include <map>

std::map<char, std::string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}
};

std::string stringToMorse(const std::string& text) {
    std::string morse;
    for (char ch : text) {
        if (ch == ' ') {
            morse += " ";
        } else {
            morse += morseCode[toupper(ch)] + " ";
        }
    }
    return morse;
}

int main() {
    DigitalOut led(LED1);

    std::string text = "Mykhailo";

    std::string morse = stringToMorse(text);

    while (1) {
        for (char dotDash : morse) {
            if (dotDash == '.') {
                led = 1;
                ThisThread::sleep_for(200ms);
                led = 0;
                ThisThread::sleep_for(200ms);
            } else if (dotDash == '-') {
                led = 1;
                ThisThread::sleep_for(600ms);
                led = 0;
                ThisThread::sleep_for(200ms);
            } else if (dotDash == ' ') {
                ThisThread::sleep_for(800ms);
            }
        }
    }
}