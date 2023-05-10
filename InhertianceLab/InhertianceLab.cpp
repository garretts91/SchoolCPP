// MoarInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class Character {
public:
    virtual std::string getSecretIdentity() = 0;
    virtual void print() = 0;
};

struct Person {
protected:
    std::string realName;
    std::string jobTitle;
};

class Hero : public Character, public Person {
public:
    std::string name;
    std::vector<std::string> superPowers;
    std::string weakness;
    Hero() {
        this->realName = "Garrett";
    }
    std::string getSecretIdentity() {
        return realName;
    };
    void print() {
        std::cout << "name: " << name << std::endl;
        std::cout << "job title: " << jobTitle << std::endl;
        std::cout << "secret identity: " << realName << std::endl;
        std::cout << "super powers: ";
        for (std::string power : superPowers) {
            std::cout << power << " ";
        }
        std::cout << std::endl;
        std::cout << "weaknesses: " << weakness << std::endl;
    };
};

class Villain : public Character {
public:
    std::string name;
    std::vector<std::string> superPowers;
    std::string weakness;
    void print() {
        std::cout << "name: " << name << std::endl;
        std::cout << "super powers: ";
        for (std::string power : superPowers) {
            std::cout << power << " ";
        }
        std::cout << std::endl;
        std::cout << "weaknesses: " << weakness << std::endl;
    };
    std::string getSecretIdentity() {
        return "placeholder";
    }
};

enum COLORS {
    NC = -1,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

/**
* Colorize terminal colors ANSI escape sequences.
*
* @param font font color (-1 to 7), see COLORS enum
* @param back background color (-1 to 7), see COLORS enum
* @param style font style (1==bold, 4==underline)
**/

const char* colorize(int font, int back = -1, int style = -1) {
    static char code[20];

    if (font >= 0)
        font += 30;
    else
        font = 0;
    if (back >= 0)
        back += 40;
    else
        back = 0;

    if (back > 0 && style > 0) {
        sprintf_s(code, "\033[%d;%d;%dm", font, back, style);
    }
    else if (back > 0) {
        sprintf_s(code, "\033[%d;%dm", font, back);
    }
    else {
        sprintf_s(code, "\033[%dm", font);
    }
    return code;
}

struct superHero {
    std::string realName;
    std::string jobTitle;
    std::string catMeme;
    std::string favoriteLeotard;
    int shoeSize;
    std::vector<int> luckyNumbers;
};

int main()
{
    Hero superMe;
    superMe.name = "banana man";
    superMe.superPowers = { "bananas" };
    superMe.weakness = "ghosts";
    superMe.getSecretIdentity();
    superMe.print();


    Villain superVillain;

    superHero baldEagleman = { "Dave", "Pizza Delivery Driver", "Grumpy", "Purple", 12, {1, 3, 5, 7, 9} };

    std::cout << colorize(MAGENTA, WHITE);
    printf("Bald Eagleman's real name is %s. They are a %s while watching %s Cat in a %s leotard in size %d shoes. Their lucky numbers are ",
        baldEagleman.realName.c_str(), baldEagleman.jobTitle.c_str(), baldEagleman.catMeme.c_str(), baldEagleman.favoriteLeotard.c_str(), baldEagleman.shoeSize
    );
    for (int luckyNumber : baldEagleman.luckyNumbers) {
        printf("%d, ", luckyNumber);
    }
    printf(" and they are all winners");
    std::cout << colorize(WHITE, BLACK);
}