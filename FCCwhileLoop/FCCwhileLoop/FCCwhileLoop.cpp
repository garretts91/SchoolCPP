// FCCwhileLoop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int index = 1;

    //while (index <= 10) {
    //    std::cout << index << std::endl;
    //    index++;
    //}

    do {
        std::cout << index << std::endl;
        index++;
    } while (index <= 5);

    return 0;
}

