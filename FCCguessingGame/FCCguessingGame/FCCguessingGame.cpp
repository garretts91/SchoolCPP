// FCCguessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int secretNum = 7;
    int guess{};
    
    while (secretNum != guess) {
        std::cout << "Enter guess: ";
        std::cin >> guess;
    }
    
    std::cout << "you win.";

    return 0;
}

