// FCCmadLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string color, pluralNoun, food;

    std::cout << "Enter a color: ";
    std::getline(std::cin, color);
    std::cout << "Enter a plural noun: ";
    std::getline(std::cin, pluralNoun);
    std::cout << "Enter a food: ";
    std::getline(std::cin, food);

    std::cout << "Roses are " << color << std::endl;
    std::cout << pluralNoun << " are blue" << std::endl;
    std::cout << "I love " << food << std::endl;

    return 0;
}