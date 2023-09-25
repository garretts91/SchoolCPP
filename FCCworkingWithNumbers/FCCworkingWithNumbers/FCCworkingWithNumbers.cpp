// FCCworkingWithNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int main()
{
    // modulus gives the remainder
    std::cout << 10 % 3 << std::endl;
    
    int wnum = 5;
    int dnum = 5.5;
    
    wnum++;

    std::cout << wnum << std::endl;

    // cmath lib
    std::cout << pow(2, 5) << std::endl;
    std::cout << sqrt(4096) << std::endl;
    std::cout << round(6.66) << std::endl;
    std::cout << ceil(19.1) << std::endl;
    std::cout << floor(19.1) << std::endl;
    std::cout << fmax(3, 10) << std::endl;
    std::cout << fmin(3, 10) << std::endl;
    return 0;
}
