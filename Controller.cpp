// #include <string>

#include "Controller.hpp"

double Controller::currentTemperature_ = 0;

Controller::Controller(SlowThermometer thermometer,
                       Fan fan,
                       double targetTemperature,
                       double tolerance,
                       std::shared_ptr<LcdDisplay> lcd)
    : thermometer_(thermometer)
    , fan_(fan)
    , targetTemperature_(targetTemperature)
    , tolerance_(tolerance)
    , lcd_(lcd)
{}

void Controller::updateRpm() {
    currentTemperature_ = thermometer_.getTemperature();
    if (currentTemperature_ >= targetTemperature_ - tolerance_ &&
        currentTemperature_ <= targetTemperature_ + tolerance_)
    {
        fan_.enable();
    } else if (currentTemperature_ < targetTemperature_ - tolerance_) {
        fan_.disable();
    } else {
        // speed must must be adjusted by 1 rpm per each 0.001 degree
        // max speed is 3000 rpm
        fan_.setSpeed(3000);
    }
}

void Controller::displayInfo() {
    if (lcd_) {
        std::string output;
        
        output += "Current temperature: ";
        output += std::to_string(currentTemperature_) + "\n";
        output += "Target temperature: ";
        output += std::to_string(targetTemperature_) + "\n";
        output += "Fan speed: ";
        output += std::to_string(fan_.getSpeed()) + "\n";
    
        lcd_->print(output);
    }
}
