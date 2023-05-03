// separateCompilation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// this should work well for the copy vehicles (rearrange function)
// Classes III
#include <iostream>

class Sheep {
public:
    //sheep default constructor
    Sheep() {}
    Sheep(std::string name, std::string breed, int ageYears) {
        this->name = name;
        this->breed = breed;
        this->ageYears = ageYears;
    }
    //copy constructor
    Sheep(Sheep &s) {
        this->name = s.name;
        this->breed = s.breed;
        this->ageYears = s.ageYears;
    }
    std::string name = "Unknown";
    std::string breed = "Unknown";
    int ageYears = -1;
    void print() {
        std::cout << name << " " << breed << " " << ageYears << "\n";
    }
};

//void rate(Sheep s) {
//    s.print();
//    std::cout << " is a 10/10\n";
//    s.breed = "Debian";
//}

int main()
{
    Sheep anon;
    Sheep geep("Geep", "Kali", 2);
    Sheep dolly(geep);
    dolly.name = "Dolly";
    
    anon.print();
    geep.print();
    dolly.print();

    //rate(geep);
    geep.print();

}
