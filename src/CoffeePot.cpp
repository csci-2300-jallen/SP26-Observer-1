#include "CoffeePot.h"

CoffeePot::CoffeePot() : state("empty") {}

void CoffeePot::fill() {
    state = "full";
    notifyObservers(state);
}

void CoffeePot::empty() {
    state = "empty";
    notifyObservers(state);
}