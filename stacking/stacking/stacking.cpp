// Given the following code,
// what is the next animal from the queue, AND the next plant from the stack?

#include <iostream>
#include <queue>
#include <stack>

void printQueue(const std::queue<std::string>& q) {
    std::queue<std::string> temp = q;
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

void printStack(const std::stack<std::string>& s) {
    std::stack<std::string> temp = s;
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::queue<std::string> animals;
    animals.push("Aardvark");
    animals.push("Bobcat");
    animals.push("Cougar");
    animals.pop();

    std::stack<std::string> plants;
    plants.push("Acacia");
    plants.pop();
    plants.push("Balsa");
    plants.push("Cedar");

    std::cout << "Animals: ";
    printQueue(animals);

    std::cout << "Plants: ";
    printStack(plants);

}