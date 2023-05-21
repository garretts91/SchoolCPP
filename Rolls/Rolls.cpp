#include <iostream>
#include <random>

class Wizard {
private:
    std::string name;
    int level;
    std::string specialization;

public:
    Wizard(const std::string& name, int level, const std::string& specialization)
        : name(name), level(level), specialization(specialization) {
    }

    void castSpell(const std::string& spellName) {
        std::cout << name << " casts " << spellName << "!" << std::endl;
    }

    void levelUp() {
        level++;
        std::cout << name << " reaches level " << level << "." << std::endl;
    }

    void setSpecialization(const std::string& specialization) {
        this->specialization = specialization;
        std::cout << name << " specializes in " << specialization << "." << std::endl;
    }

    void displayInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "Specialization: " << specialization << std::endl;
    }
};

class DiceRoller {
public:
    int rollD20() {
        return roll(20);
    }

    int rollD12() {
        return roll(12);
    }

    int rollD10() {
        return roll(10);
    }

    int rollD6() {
        return roll(6);
    }

    int roll(int sides) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, sides);
        return dis(gen);
    }

    int rollMultiple(int sides, int numRolls) {
        int sum = 0;
        for (int i = 0; i < numRolls; ++i) {
            int rollResult = roll(sides);
            std::cout << "Roll " << (i + 1) << ": " << rollResult << std::endl;
            sum += rollResult;
        }
        return sum;
    }
};

int main() {
    Wizard wizard("Gandalf", 5, "Evocation");

    wizard.displayInfo();
    wizard.castSpell("Fireball");
    wizard.levelUp();
    wizard.setSpecialization("Enchantment");
    wizard.displayInfo();
    DiceRoller diceRoller;

    int d20Result = diceRoller.rollD20();
    std::cout << "D20 Roll: " << d20Result << std::endl;

    int d12Result = diceRoller.rollD12();
    std::cout << "D12 Roll: " << d12Result << std::endl;

    int d10Result = diceRoller.rollD10();
    std::cout << "D10 Roll: " << d10Result << std::endl;

    int d6Result = diceRoller.rollD6();
    std::cout << "D6 Roll: " << d6Result << std::endl;

    int sum = d20Result + d12Result + d10Result + d6Result;
    std::cout << "Sum of Rolls: " << sum << std::endl;

    return 0;
}




//// MoarInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <vector>
//
//class Character {
//public:
//    virtual std::string getSecretIdentity() = 0;
//    virtual void print() = 0;
//};
//
//struct Person {
//protected:
//    std::string realName;
//    std::string jobTitle;
//};
//
//class Hero : public Character, public Person {
//public:
//    std::string name;
//    std::vector<std::string> superPowers;
//    std::string weakness;
//    Hero() {
//        this->realName = "Aragorn, Son of Arathorn";
//        this->jobTitle = "1st High King of the Reunited Kingdom ";
//    }
//    std::string getSecretIdentity() {
//        return realName;
//    };
//    void print() {
//        std::cout << "Hero" << std::endl;
//        std::cout << "name: " << name << std::endl;
//        std::cout << "title: " << jobTitle << std::endl;
//        std::cout << "secret identity: " << realName << std::endl;
//        std::cout << "super powers: ";
//        for (std::string power : superPowers) {
//            std::cout << power << " ";
//        }
//        std::cout << std::endl;
//        std::cout << "weaknesses: " << weakness << std::endl;
//    };
//};
//
//class Villain : public Character {
//public:
//    std::string name;
//    std::vector<std::string> superPowers;
//    std::string weakness;
//    void print() {
//        std::cout << "Villain" << std::endl;
//        std::cout << "name: " << name << std::endl;
//        std::cout << "super powers: ";
//        for (std::string power : superPowers) {
//            std::cout << power << " ";
//        }
//        std::cout << std::endl;
//        std::cout << "weaknesses: " << weakness << std::endl;
//    };
//    std::string getSecretIdentity() {
//        return "placeholder";
//    }
//};
//
//enum COLORS {
//    NC = -1,
//    BLACK,
//    RED,
//    GREEN,
//    YELLOW,
//    BLUE,
//    MAGENTA,
//    CYAN,
//    WHITE,
//};
//
////**
//* Colorize terminal colors ANSI escape sequences.
//*
//* @param font font color (-1 to 7), see COLORS enum
//* @param back background color (-1 to 7), see COLORS enum
//* @param style font style (1==bold, 4==underline)
//**/
//
//const char* colorize(int font, int back = -1, int style = -1) {
//    static char code[20];
//
//    if (font >= 0)
//        font += 30;
//    else
//        font = 0;
//    if (back >= 0)
//        back += 40;
//    else
//        back = 0;
//
//    if (back > 0 && style > 0) {
//        sprintf_s(code, "\033[%d;%d;%dm", font, back, style);
//    }
//    else if (back > 0) {
//        sprintf_s(code, "\033[%d;%dm", font, back);
//    }
//    else {
//        sprintf_s(code, "\033[%dm", font);
//    }
//    return code;
//}
//
//struct superHero {
//    std::string realName;
//    std::string jobTitle;
//    std::string catMeme;
//    std::string favoriteLeotard;
//    int shoeSize;
//    std::vector<int> luckyNumbers;
//};
//
//int main()
//{
//    Hero superMe;
//    superMe.name = "Aragorn";
//    superMe.superPowers = { "Bravery", "Loyalty", "Healing"};
//    superMe.weakness = "Ring of Power";
//    superMe.getSecretIdentity();
//    std::cout << colorize(CYAN, BLACK);
//    superMe.print();
//
//    Villain superVillain;
//    superVillain.name = "Sauron";
//    superVillain.superPowers = { "Dark Magic", "Manipulation", "Deceit"};
//    superVillain.weakness = "Arrogance";
//    std::cout << colorize(RED, BLACK);
//    superVillain.print();
//    
//    superHero baldEagleman = { "Dave", "Pizza Delivery Driver", "Grumpy", "Purple", 12, {1, 3, 5, 7, 9} };
//    
//    std::cout << colorize(MAGENTA, BLACK);
//    printf("Bald Eagleman's real name is %s. They are a %s while watching %s Cat in a %s leotard in size %d shoes. Their lucky numbers are ",
//        baldEagleman.realName.c_str(), baldEagleman.jobTitle.c_str(), baldEagleman.catMeme.c_str(), baldEagleman.favoriteLeotard.c_str(), baldEagleman.shoeSize
//    );
//    for (int luckyNumber : baldEagleman.luckyNumbers) {
//        printf("%d, ", luckyNumber);
//    }
//    printf(" and they are all winners");
//    std::cout << colorize(WHITE, BLACK);
//} 