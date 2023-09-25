// FCCgetUserInput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    int age;
    std::string name;

    std::cout << "Enter your age: " << std::endl;
    std::cin >> age;
    std::cout << "You are " << age << " years old." << std::endl;
    

    std::cout << "What is your name? \n";  
    getline(std::cin, name);

    std::cout << "Hello " << name;
    return 0;
}
