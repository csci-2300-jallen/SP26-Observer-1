#include "Person.h"
#include <iostream>

Person::Person(const std::string& name) : name(name) {}

void Person::update(const std::string& coffeeState) {
    if (coffeeState == "full") {
        std::cout << name << " says: Yay! The coffee pot is full!" << std::endl;
    } else if (coffeeState == "empty") {
        std::cout << name << " says: Oh no! The coffee pot is empty" << std::endl;
    }
}

