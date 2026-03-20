#pragma once

#include <string>
#include "Observer.h"

class BeanListener : public Observer {
private:
    std::string name;
protected:
    int pots_left;
public:
    BeanListener(const std::string& name);
    void update(const std::string& coffeeState) override;
};

