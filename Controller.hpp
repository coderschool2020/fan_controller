#pragma once

#include "IThermometer.hpp"
#include "Fan.hpp"
#include <memory>

class LcdDisplay;

class Controller {    
public:
    Controller(IThermometer&, Fan&, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();

private:
    IThermometer& thermometer_;
    Fan& fan_;
};
