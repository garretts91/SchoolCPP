// FCCreturnStatement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double cube(double num) {
    return num * num * num;
    // return will break us out of our code
}

int main()
{
    std::cout << "Hello World!\n";
    // double answer = cube(5.0);
    // std::cout << answer;
    std::cout << cube(5.6);

    return 0;
}
