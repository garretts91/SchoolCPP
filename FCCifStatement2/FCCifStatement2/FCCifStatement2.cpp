// FCCifStatement2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int getMax(int num1, int num2, int num3) {
    int result;

    if (num1 >= num2 && num1 >= num3) {
        result = num1;
    }
    else if (num2 >= num1 && num2 >= num3) {
        result = num2;
    }
    else {
        result = num3;
    }
    return result;
}

int main()
{
    std::cout << getMax(2, 5, 3);
    
    return 0;
}
