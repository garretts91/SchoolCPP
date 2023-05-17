// Give this class a default constructor and call the build function in main.

#include <stdio.h>

class Skyscraper {
public:
    Skyscraper() {
        this->floors = 1000;
        this->sqft = 123456789.01;
    }

    void build() {
        printf("Building a %0.2f sqft, %d floor skyscraper!\n",
            this->sqft, this->floors);
    }
private:
    int floors;
    double sqft;
};

int main()
{
    Skyscraper searsTower;
    searsTower.build();

    return 0;
}