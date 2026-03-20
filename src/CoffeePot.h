#pragma once

#include <string>
#include "Subject.h"

class CoffeePot : public Subject {
private:
    std::string state;
public:
    CoffeePot();
    void fill();
    void empty();
};

