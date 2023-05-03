#include "food.h"

Food::Food(std::string name, int calories, std::vector<std::string> flavors) {
    this->name = name;
    this->calories = calories;
    this->flavors = flavors;
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

// loop over the food items for the operator to work?
// https://www.geeksforgeeks.org/operator-overloading-cpp/#

//Food Food::operator+(const Food& x)
//{
//    return Food();
//}
//
//Food Food::operator+(const Food& x)
//{
//    return Food();
//}
//
//Food Food::operator>(const Food& y) const {
//    std::string newName = name + " and " + y.name;
//    int newCalories = x.calories + y.calories;
//    std::string newFlavor = flavors + " and " + y.flavors;
//    return Food(newName, newCalories, newFlavor);
//}

Recipe::Recipe(std::string name, int servings, std::vector<std::pair<Food, int>> ingredients) {
    this->name = name;
    this->servings = servings;
    this->ingredients = ingredients;
}

void Recipe::addFood(Food food, int amount) {
    ingredients.push_back(std::make_pair(food, amount));
}

int Recipe::getCaloriesPerServing() {
    int totalCalories = 0;
    for (auto& food : ingredients) {
        totalCalories += food.first.getCalorieCount() * food.second;
    }
    return totalCalories / servings;
}

void Recipe::display() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Servings: " << servings << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (auto& food : ingredients) {
        std::cout << food.second << " " << food.first.name << " " << food.first.getCalorieCount() << " calories" << std::endl;
    }
    std::cout << "Calories per serving: " << getCaloriesPerServing() << std::endl;
}