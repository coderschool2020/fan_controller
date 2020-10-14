#include "Controller.hpp"
#include "external/catch.hpp"
#include "external/hippomocks.h"

#include "../tests/StubThermometer.hpp"

SCENARIO("Controller can control the fan") {
    GIVEN("Conroller, Thermometer, Fan, target temperature = 36.5, tolerance = 0.5") {
        StubThermometer thermometer;
        Fan fan;
        double targetTemperature = 36.6;
        double tolerance = .5;
        Controller cut{ thermometer, fan, targetTemperature, tolerance, nullptr }; // class under test

        WHEN("Temperature drops below 0 and updateRpm() is called") {
            thermometer.temperature = -1;
            cut.updateRpm();

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == 0);
            }
        }

        WHEN("Temperature raise above 100 and updateRpm() is called") {
            thermometer.temperature = 101;
            cut.updateRpm();

            THEN("Fan should work at max speed") {
                REQUIRE(fan.getSpeed() == maxSpeed);
            }
        }
    }


}