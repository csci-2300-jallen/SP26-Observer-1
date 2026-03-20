#include "CoffeePot.h"
#include "Person.h"

int main() {

    CoffeePot pot;

    Person* alice = new Person("Alice");
    Person* bob = new Person("Bob");

    pot.addObserver(alice);
    pot.addObserver(bob);
    
    pot.fill();
    pot.empty();

    return 0;
}