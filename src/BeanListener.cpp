#include "BeanListener.h"
#include <iostream>

BeanListener::BeanListener(const std::string& name) : 
    name(name), 
    pots_left(10) {}

void BeanListener::update(const std::string& coffeeState) {
    if (coffeeState == "empty") {
        if (pots_left == 0) {
            std::cout << "Ordering more beans now!" << std::endl;
            pots_left = 10;
        }
    } else if (coffeeState == "full") {
        pots_left -= 1;
        std::cout << "pots left: " << pots_left << std::endl;
    }
}

