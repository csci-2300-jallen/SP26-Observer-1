#pragma once

#include <string>
#include "Observer.h"

class Person : public Observer {
private:
    std::string name;
public:
    Person(const std::string& name);
    void update(const std::string& coffeeState) override;
};

