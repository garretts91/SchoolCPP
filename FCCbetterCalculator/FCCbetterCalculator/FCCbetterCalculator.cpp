// FCCbetterCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double num1, num2;
    char op;
    double result = 0;

    std::cout << "Enter first #: ";
    std::cin >> num1;
    std::cout << "Enter operator: ";
    std::cin >> op;
    std::cout << "Enter second #: ";
    std::cin >> num2;

    if (op == '+') {
        result = num1 + num2;
    }
    else if (op == '-') {
        result = num1 - num2;
    }
    else if (op == '/') {
        result = num1 / num2;
    }
    else if (op == '*') {
        result = num1 * num2;
    }
    else {
        std::cout << "Invalid Operator..." << std::endl;
    }

    std::cout << result;

    return 0;
}