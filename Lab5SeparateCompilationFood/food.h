#pragma once
#include <iostream>
#include <vector>

class Food {
public:
    Food(std::string name, int calories, std::vector<std::string> flavors);
    int getCalorieCount();
    bool hasFlavor(std::string flavor);
    //Food operator+(const Food& x) const;
    //Food operator+(const Food& y) const;
    std::string name;
private:
    int calories;
    std::vector<std::string> flavors;
};

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
