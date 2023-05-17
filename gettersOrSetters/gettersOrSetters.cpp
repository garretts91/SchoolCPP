// Which functions on this class are getters or setters?

// Choose all that apply.

#include <iostream>

class Obfuscated {
    double x;
    int y;
    float z;
public:
    double a() {
        return 0.0;
    }
    double b() {
        return x;
    }
    void c(int y) {
        this->y = y;
    }
    float d() {
        return z;
    }
    void e(double x) {}
};

int main()
{
    Obfuscated values;

    double a;

    double xValue = values.b();
    std::cout << "x = " << xValue << std::endl;

    values.c(20000000);
    std::cout << "y = " << values.c << std::endl;

    float zValue = values.d();
    std::cout << "z = " << zValue << std::endl;
 
    return 0;
}