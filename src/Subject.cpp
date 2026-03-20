#include "Subject.h"
#include <algorithm>

void Subject::addObserver(Observer* o) {
    observers.push_back(o);
}

void Subject::removeObserver(Observer* o) {
    observers.erase(
        std::remove(observers.begin(), observers.end(), o),
        observers.end()
    );
}

void Subject::notifyObservers(const std::string& state) {
    for (Observer* o : observers) {
        if (o != nullptr) {
            o->update(state);
        }
    }
}
