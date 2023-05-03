// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include "Course.h"

int main()
{
    Course cs132;
    cs132.name = "CS132";
    Course cs1337(1337, "CS1337");
    // same as calling cs132.operator+(cs1337);
    Course cs1321337 = cs132 + cs1337;
    std::cout << cs1321337.name << " " << cs1321337.getCredits() << std::endl;
    std::map<std::string, Course> myMap;
    myMap["cs132"] = cs132;
    myMap["cs1337"] = cs1337;
    myMap[(cs132 + cs1337).name] = cs132 + cs1337;

    std::cout << myMap["CS132 CS1337"].getCredits();

    return 0;
}