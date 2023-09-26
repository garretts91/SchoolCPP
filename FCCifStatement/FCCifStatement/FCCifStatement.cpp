// FCCifStatement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    bool isMale = false;
    bool isTall = false;

    if (isMale && isTall) {
        std::cout << "You are a tall male";
    }
    else if (isMale && !isTall) {
        std::cout << "You are a short male";
    }
    else if (!isMale && isTall) {
        std::cout << "You are tall but not male";
    }
    else {
        std::cout << "You are not male and not tall.";
    }

    return 0;
}
