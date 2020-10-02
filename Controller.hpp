#pragma once
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>

class LcdDisplay;

class Controller {
public:
    Controller(SlowThermometer thermometer,
               Fan fan,
               double targetTemperature,
               double tolerance,
               std::shared_ptr<LcdDisplay> lcd);
    void updateRpm();
    void displayInfo();

private:
    SlowThermometer& thermometer_;
    Fan& fan_;
    double targetTemperature_;
    double tolerance_;
    std::shared_ptr<LcdDisplay> lcd_;
    static double currentTemperature_;
};
