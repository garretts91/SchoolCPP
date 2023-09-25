// FCCvariables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::string characterName = "John";
    int characterAge = 35;

    std::cout << "There once was a man named " << characterName << std::endl;
    std::cout << "He was " << characterAge << " years old" << std::endl;

    characterName = "Mike";

    std::cout << "He liked the name " << characterName << std::endl;
    std::cout << "He did not like being " << characterAge << std::endl;

    return 0;
}

