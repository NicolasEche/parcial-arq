#include "mbed.h"
#include <iostream>
using namespace std;
    
PwmOut ledRojo(LED1);
PwmOut ledVerde(LED2);
PwmOut ledAzul(LED3);

int main() {

    string hex_code;

    cout << "Enter an RGB hexadecimal color code: ";
    cin >> hex_code;

    // Remove the '#' character from the beginning of the hex code.

    std::string hex_code_no_hash(hex_code);
    hex_code_no_hash.erase(0, 1);

    // Convert each of the two digits of the hex code to an integer.

    int red = std::stoi(hex_code_no_hash.substr(0, 1), nullptr, 16);
    int green = std::stoi(hex_code_no_hash.substr(2, 3), nullptr, 16);
    int blue = std::stoi(hex_code_no_hash.substr(4, 5), nullptr, 16);

    ledRojo = red;
    ledVerde = green;
    ledAzul = blue;
}
