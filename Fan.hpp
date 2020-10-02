#pragma once

class Fan {
    int rpm = 0;

public:
    Fan();
    ~Fan();
    Fan(const Fan&);
    Fan(Fan&&);
    Fan& operator=(const Fan&);
    Fan& operator=(Fan&& other);

    void setSpeed(int newRpm);
    int getSpeed() const;
    bool disable();
    bool enable();
};
