// moveCapitals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// Function to move capital letters to the front of a word
std::string moveCapitalLettersToFront(const std::string& word) {
    std::string result;
    std::string capitals;

    for (char c : word) {
        if (std::isupper(c)) {
            capitals += c;
        }
        else {
            result += c;
        }
    }

    result = capitals + result;
    return result;
}

int main() {
    std::string input = "HeLLoWorLD";
    std::string modified = moveCapitalLettersToFront(input);

    std::cout << "Original word: " << input << std::endl;
    std::cout << "Modified word: " << modified << std::endl;

    return 0;
}
