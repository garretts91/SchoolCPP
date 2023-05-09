// midtermReview.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Movie {
public:
    int runtime = 120;
    void operator--() {
        this->runtime--;
    }
    Movie operator+(Movie m) {
        temp.runtime = m.runtime + this->runtime;
        return temp; 
    }
};

int main()
{
    std::cout << "Hello World!\n";
}