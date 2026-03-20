#include "CoffeePot.h"
#include "Person.h"
#include "BeanListener.h"

int main() {

    CoffeePot pot;

    BeanListener* BeanListener3000 = new BeanListener("BeanListener3000");
    
    pot.addObserver(BeanListener3000);

    for (int i = 0; i < 30; i ++) {
        pot.fill();
        pot.empty();
    }

    return 0;
}