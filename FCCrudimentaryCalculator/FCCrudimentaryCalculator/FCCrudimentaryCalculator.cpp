// FCCrudimentaryCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double num1, num2;
    
    std::cout << "Enter your first number!\n";
    std::cin >> num1;

    std::cout << "Enter your second number!\n";
    std::cin >> num2;

    std::cout << "Adding the two numbers gives: ";
    std::cout << num1 + num2;

    return 0;
}

