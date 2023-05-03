#include "Course.h"
#include <iostream>

Course::Course() {}

Course::Course(int credits, std::string name) {
    this->credits = credits;
    this->name = name;
}

int Course::getCredits() {
    return this->credits;
}
