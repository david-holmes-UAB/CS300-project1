#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

const char * KEYBOARD = "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

std::string decypher(std::string &input);

int main() {

    std::string usrInput;
    std::cout << "Enter user input (in all uppercase for letters): \n";

    getline(std::cin, usrInput);

    // Line for testing input recieved
    //std::cout << usrInput << " was typed.";

    /*
    * For debugging whitespace not being included in output string
    for (char curr : usrInput) {
        std::cout << curr << "\n";
    }
    */

    std::cout << "Output: " << decypher(usrInput);


    
}

std::string decypher(std::string &input) {
    std::string output = "";
    for (char curr : input) {
        if (curr == ' ') {
            output = output + ' ';
        }
        else {
            for (int i = 0; i < strlen(KEYBOARD); i++) {
                if (curr != 'Q' && curr != 'A' && curr != 'Z') {
                    if (curr == KEYBOARD[i]) {
                        output = output + KEYBOARD[i - 1];
                    }
                }
                else {
                    output = output + curr;
                }
            }
        }
    }



    return output;
}