#include <stdio.h>
#include <string>
#include <iostream>

#define KEYBOARD std::string "QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"

std::string decypher(std::string &input);

int main() {

    std::string usrInput;
    std::cout << "Enter user input: \n";

    getline(std::cin, usrInput);
    //std::cout << usrInput << " was typed.";

    //std::cout << "Output: " << decypher(usrInput) << "\n";


    
}

std::string decypher(std::string &input) {
    std::string output = "";
    for (char curr : input) {
        // TODO
    }



    return output;
}