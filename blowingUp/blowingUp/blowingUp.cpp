// Uh oh, this code is blowing up!
// Add a try-catch block to handle the exception and print the error message.

#include <iostream>
#include <stdio.h>
#include <exception>

struct OopsException : public std::exception {
    const char* what() const throw () {
        return "Uh oh, spaghetti codes. Did you divide by zero? You're a madman. \n";
    }
};

int runTheNumbers(int x, int y) {
    if (y == 0)
        throw OopsException();
    else
        return (x + y) * x / y;
}

int main() {
    int x = 5, y = 0;

    try {
        printf("runTheNumbers(%d, %d) = %d", x, y, runTheNumbers(x, y));
    }
    catch (OopsException& oops) {
        std::cout << oops.what();
    }

    return 0;
}