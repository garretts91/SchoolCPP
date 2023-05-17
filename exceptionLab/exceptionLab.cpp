// Exceptions.cpp
//

#include <iostream>
#include <stdio.h>
#include <exception>

struct UnevenException : public std::exception
{
    const char* what() const throw ()
    {
        return "This function only divides by even numbers.";
    }
};

class EvenException : public std::exception {
    const char* info;
public:
    EvenException(const char* msg, const char* info_ = "") : std::exception(msg),
        info(info_) { }
    const char* get_info() const { return info; }

};

int justTryToDivide(int x, int y) {
    // exceptions can be thrown with the "throw" keyword
    if (y == 0)
        // a simple string as an exception
        throw "Are you trying to divide by zero?!";
    // better to throw as an error though
    //throw std::runtime_error("A better way to throw an error.");
    else if (y % 2 == 1)
        // a struct as an exception
        throw UnevenException();
    else if (y % 2 == 0)
        // a class as an exception
        throw EvenException("This function only divides by odd numbers.", "Odd numbers take the form of 2n+1, where n->{N}");
    else
        // survived the gauntlet, can return without an error
        return x / y;
}

int main()
{
    int x, y;
    std::cout << "Let's divide some numbers: ";
    std::cin >> x >> y;

    // exceptions can be handled, or "caught" in a try-catch block
    try {
        int z = justTryToDivide(x, y);
        printf("%d / %d = %d", x, y, z);
    }
    catch (const char* c) {
        std::cout << c << '\n';
        return 1;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (UnevenException& uex) {
        std::cout << uex.what() << '\n';
        return 3;
    }
    catch (EvenException& eex) {
        std::cout << eex.what() << ' ' << eex.get_info() << '\n';
        return 4;
    }

    return 0;
}