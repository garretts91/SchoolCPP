#pragma once

#include <string>

class Course {
public:
    Course();
    Course(int credits, std::string name);
    int getCredits();
    std::string name = "Unknown";
    Course operator+ (Course c) {
        Course clone = *this;
        clone.credits += c.getCredits();
        clone.name += " " + c.name;
        return clone;
    }

private:
    int credits = 5;
};
