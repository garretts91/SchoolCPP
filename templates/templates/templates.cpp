// Lab 09 - Templates
// Combine the following four "divide" functions into a templated function
// with any necessary specializations to handle different operations.

#include<iostream>

template <typename D>
D divide(D x, D y) {
    return x / y;
}

template <>
char divide<char>(char x, char y) {
    return (char)((int)x / (int)y);
    //cant seem to get return ascii?
    //not sure if it is my computer
    //return x / y;
}

//int divide(int x, int y)
//{
//    return x / y;
//}
//
//float divide(float x, float y)
//{
//    return x / y;
//}
//
//double divide(double x, double y)
//{
//    return x / y;
//}
//
//char divide(char x, char y)
//{
//    return (char)((int)x / (int)y);
//}

int main()
{
    std::cout << "Let's divide some things!\n";
    std::cout << "12 / 6 = " << divide(12, 6) << "\n";
    std::cout << "3.5 / 1.2 = " << divide(3.5, 1.2) << "\n";
    std::cout << "0.0007 / 0.0000001 = " << divide(0.0007, 0.0000001) << "\n";
    std::cout << "z / $ = " << divide('z', '$') << "\n";
    std::cout << "* / # = " << divide('*', '#') << std::endl;
}