// Why isn't this code working and how might we fix it?

#include <iostream>

class MyPerfectClass {
public:
    MyPerfectClass() {
        this->favoriteNumber = 5;
    }
    void pleaseWork() {
        std::cout << "Hooray, it's working!";
    }
private:
    int favoriteNumber;
};

int main()
{
    MyPerfectClass mpc;
    mpc.pleaseWork();
}