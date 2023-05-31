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

std::vector<std::string> Food::getFlavors() const
{
    return std::vector<std::string>(flavors);
}

Food Food::operator+(const Food& otherFood) const {
    std::string newName = name + " and " + otherFood.name;
    int newCalories = calories + otherFood.calories;
    std::vector<std::string> newFlavor = flavors;
    newFlavor.insert(newFlavor.end(), otherFood.flavors.begin(), otherFood.flavors.end());
    return Food(newName, newCalories, newFlavor);
}

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