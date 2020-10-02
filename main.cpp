#include "Controller.hpp"
#include "SlowThermometer/SlowThermometer.hpp"
#include "Fan.hpp"
#include "LcdDisplay.hpp"
#include <memory>
#include <iostream>

int main() try {
    SlowThermometer t;
    Fan f;
    double targetTemperature = 36.6;
    double tolerance = .5;
    auto lcdDisplay = std::make_shared<LcdDisplay>();
    
    // no display
    Controller oldController{t, f, targetTemperature, tolerance, nullptr};
    oldController.updateRpm();
    oldController.displayInfo();

    // no display
    Controller newController{t, f, targetTemperature, tolerance, std::shared_ptr<LcdDisplay>()};
    newController.updateRpm();
    newController.displayInfo();

    // instance of display
    Controller newestController{t, f, targetTemperature, tolerance, lcdDisplay};
    newestController.updateRpm();
    newestController.displayInfo();

    return 0;
} catch (const std::exception & e) {
    std::cerr << e.what() << '\n';
    return -1;
}
