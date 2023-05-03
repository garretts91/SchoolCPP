// Lab 3 - Classes II
// This lab will rely on the Food class from the previous lab.
// For this lab we will construct a new class for a Recipe.

// A Recipe should consist of:
// a name
// number of servings
// multiple Food items, along with an amount for each of them
// a public method that calculates and returns the number of calories in a single serving
// a public method to print the recipe, displaying the name, servings and list of Food items with amounts

#include <iostream>
#include <vector>
#include "food.h"

int main() {
    Food salmon("King Salmon", 800, { "Smooth", "Buttery", "Meaty" });
    Food garlic("Garlic", 35, { "Pungent", "Spicy", "Sharp" });
    Food lemonJuice("Lemon Juice", 17, { "Sour", "Acidic" });
    Food oliveOil("Olive Oil", 125, { "Smooth", });
    Food butter("Salted Butter", 225, { "Fatty", "Salty" });
    Food mustard("Dijon Mustard", 125, { "Tangy", "Sharp" });
    Food basil("Dried Basil", 15, { "Herby" });
    Food dill("Dried Dill", 15, { "Herby" });
    Food pepper("Cayenne Pepper", 3, { "Spicy" });

    std::vector<Food> foods = { salmon, garlic, lemonJuice, oliveOil, butter, mustard, basil, dill, pepper };

    std::vector<std::pair<Food, int>> ingredients = { { salmon, 1}, { garlic, 4 }, { lemonJuice, 2 },
    {oliveOil, 3}, { butter, 2 }, { mustard, 2 }, { basil, 2 }, { dill, 1 }, { pepper, 2 } };

    Recipe famSalmon("Kelley's Lemon Garlic Salmon", 4, ingredients);

    famSalmon.display();
    return(5);

    std::string search;

    do
    {
        std::cout << "Input flavor to search for (Q to quit): ";
        std::cin >> search;
        for (Food food : foods)
        {
            if (food.hasFlavor(search))
            {
                std::cout << "Food: " << food.name << "\n" << "Calories: " << food.getCalorieCount() << std::endl;
            }
        }
    } while (search != "Q");

}
