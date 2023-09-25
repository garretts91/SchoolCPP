// FCCfunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void sayHi(std::string name, int age);

int main()
{
    sayHi("Grag", 42);
    sayHi("Frag", 32);
    sayHi("Erag", 22);
    return 0;
}

void sayHi(std::string name, int age) {
    std::cout << "Hello " << name << " you are " << age << std::endl;
}