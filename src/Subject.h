#pragma once

#include <vector>
#include <string>
#include "Observer.h"

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() {}
    virtual void addObserver(Observer* o);
    virtual void removeObserver(Observer* o);
    virtual void notifyObservers(const std::string& state);
};


