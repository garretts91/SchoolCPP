// Given the following vector of Pokemon, print out each of their names.

#include <iostream>
#include <vector>

struct Pokemon {
    std::string name;
    std::vector<std::string> weaknesses;
};

int main()
{
    std::vector<Pokemon> myPokemon =
    {
        {"Pikachu", {"ground"}},
        {"Charizard", {"water", "wind"}},
        {"Gengar", {"light"}}
    };
    
    for (Pokemon poke : myPokemon) {
        std::cout << "Oh no, " << poke.name << " you're weak to ";
        for (std::string ouch : poke.weaknesses) {
            std::cout << ouch << "! ";
        }
        std::cout << "\n";
    }
    std::cout << "Return!";
    return 0;
}