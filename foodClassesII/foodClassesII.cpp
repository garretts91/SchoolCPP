// Lab 3 - Classes II
// This lab will rely on the Food class from the previous lab.
// For this lab we will construct a new class for a Recipe.

// A Recipe should consist of:
// a name
// number of servings
// multiple Food items, along with an amount for each of them
// a public method that calculates and returns the number of calories in a single serving
// a public method to print the recipe, displaying the name, servings and list of Food items with amounts

//TODO: Display ingredients

#include <iostream>
#include <vector>

class Food {
public:
    Food(std::string name, int calories, std::vector<std::string> flavors);
    int getCalorieCount();
    bool hasFlavor(std::string flavor);
    std::string name;
private:
    int calories;
    std::vector<std::string> flavors;
};

Food::Food(std::string name, int calories, std::vector<std::string> flavors) {
    this->name = name;
    this->calories = calories;
    this->flavors = flavors;
}

class Recipe {
public:
    Recipe(std::string name, int servings, std::vector<std::pair<Food, int>> ingredients);
    void addFood(Food food, int amount);
    int getCaloriesPerServing();
    void display();
private:
    std::string name;
    int servings;
    std::vector<std::pair<Food, int>> ingredients;
};

Recipe::Recipe(std::string name, int servings, std::vector<std::pair<Food, int>> ingredients) {
    this->name = name;
    this->servings = servings;
    this->ingredients = ingredients;
}

int main() {
    Food salmon("King Salmon", 725, { "Smooth", "Buttery", "Meaty" });
    Food garlic("Garlic", 25, { "Pungent", "Spicy", "Sharp" });
    Food lemonJuice("Lemon Juice", 12, { "Sour", "Acidic"});
    Food oliveOil("Olive Oil", 125, { "Smooth", });
    Food butter("Salted Butter", 200, { "Fatty", "Salty"});
    Food mustard("Dijon Mustard", 50, { "Tangy", "Sharp" });
    Food basil("Dried Basil", 5, { "Herby" });
    Food dill("Dried Dill", 5, { "Herby" });
    Food pepper("Cayenne Pepper", 2, { "Spicy" });

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

int Food::getCalorieCount() {
    return calories;
}

bool Food::hasFlavor(std::string flavor) {
    for (std::string f : flavors) {
        if (f == flavor) {
            return true;
        }
    }
    return false;
}

void Recipe::addFood(Food food, int amount) {
    ingredients.push_back(std::make_pair(food, amount));
}

int Recipe::getCaloriesPerServing() {
    int totalCalories = 0;
    for (auto food : ingredients) {
        totalCalories += food.first.getCalorieCount() * food.second;
    }
    return totalCalories / servings;
}

void Recipe::display() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Servings: " << servings << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (auto food : ingredients) {
        std::cout << food.second << " " << " (" << food.first.getCalorieCount() << " calories each)" << std::endl;
    }
    std::cout << "Calories per serving: " << getCaloriesPerServing() << std::endl;
}

// display ingredients