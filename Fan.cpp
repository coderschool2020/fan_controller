#include "Fan.hpp"
#include <stdexcept>
#include <cmath>

Fan::Fan() : rpm{} {}
Fan::~Fan() {}

Fan::Fan(const Fan& other) : rpm(other.rpm) {}
Fan::Fan(Fan&& other) : rpm(other.rpm) {
    other.rpm = 0;
}

Fan& Fan::operator=(const Fan& rhs) {
    if (this != &rhs) {
        rpm = rhs.rpm;
    }
    return *this;
}
Fan& Fan::operator=(Fan&& rhs) {
    if (this != &rhs) {
        rpm = rhs.rpm;
        rhs.rpm = 0;
    }
    return *this;
}

void Fan::setSpeed(int newRpm) {
    if ((newRpm < 1000 and newRpm != 0) or newRpm > 3000) {
        throw std::invalid_argument("Invalid speed");
    }
    rpm = newRpm;
}

int Fan::getSpeed() const {
    return rpm;
}

bool Fan::disable() {
    rpm = 0;
    return true;
}

bool Fan::enable() {
    rpm = 1000;
    return true;
}
