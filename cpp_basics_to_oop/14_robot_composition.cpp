// ==============================================================
// File: 14_robot_composition.cpp
// Concept: Composition ("HAS-A" vs "IS-A")
// ==============================================================
//
// The #1 Mistake Beginners Make:
// Students learn Inheritance and immediately write:
//     class Robot : public Motor, public Battery { ... };
//
// Ask yourself:
// Is a Robot a Motor? NO!
// Is a Robot a Battery? NO!
//
// A Robot HAS A Motor.
// A Robot HAS A Battery.
//
// In C++, when a robot HAS parts, we put those parts INSIDE the robot class
// as member variables. This is called COMPOSITION (building like LEGO bricks!).
// ==============================================================

#include <iostream>
#include <string>

// Subsystem 1: Battery
class Battery {
private:
    double voltage_;
public:
    Battery(double v) : voltage_(v) {}
    double getVoltage() const { return voltage_; }
    void drain(double amount) { voltage_ -= amount; }
};

// Subsystem 2: Motor
class Motor {
private:
    std::string side_;
    int speed_;
public:
    Motor(std::string side) : side_(side), speed_(0) {}
    void setSpeed(int s) { speed_ = s; }
    int getSpeed() const { return speed_; }
    std::string getSide() const { return side_; }
};

// ==============================================================
// The Master Robot Class: COMPOSITION IN ACTION!
// Robot "HAS-A" battery and "HAS-A" left motor and right motor.
// ==============================================================
class MobileRobot {
private:
    std::string name_;
    Battery battery_;  // Composition: Robot HAS a battery
    Motor leftMotor_;  // Composition: Robot HAS a left motor
    Motor rightMotor_; // Composition: Robot HAS a right motor

public:
    // Initializer list creates the internal components
    MobileRobot(std::string name)
        : name_(name),
          battery_(12.6),          // 12.6V battery
          leftMotor_("Left"),      // Left wheel motor
          rightMotor_("Right") {}  // Right wheel motor

    void drive(int speed) {
        if (battery_.getVoltage() < 10.0) {
            std::cout << "[" << name_ << "] CANNOT DRIVE: Battery too low!\n";
            return;
        }

        leftMotor_.setSpeed(speed);
        rightMotor_.setSpeed(speed);
        battery_.drain(0.2); // Driving drains some battery

        std::cout << "[" << name_ << "] Driving forward with both motors at " 
                  << speed << " PWM. (Battery remaining: " 
                  << battery_.getVoltage() << " V)\n";
    }

    void stop() {
        leftMotor_.setSpeed(0);
        rightMotor_.setSpeed(0);
        std::cout << "[" << name_ << "] Robot brought to complete stop.\n";
    }
};

int main() {
    std::cout << "--- CREATING ROBOT USING COMPOSITION (LEGO BLOCKS) ---\n";

    MobileRobot rover("Curiosity-Jr");

    rover.drive(150);
    rover.drive(200);
    rover.stop();

    return 0;
}

