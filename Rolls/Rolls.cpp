#include <iostream>
#include <random>

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