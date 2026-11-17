// ==============================================================
// File: 10_robot_encapsulation.cpp
// Concept: Encapsulation (The Hardware Circuit Breaker)
// ==============================================================
//
// What is Encapsulation?
// It means putting sensitive hardware variables inside a protective shell (`private`),
// and only allowing the outside world to interact through safe buttons (`public`).
//
// Why do we need this in Robotics?
// An Arduino PWM motor driver can only take speeds from -255 to +255.
// If someone writes: `motor.speed = 99999;`, the motor controller burns out!
// With Encapsulation, we write a `setSpeed()` function that clamps illegal values!
// ==============================================================

#include <iostream>
#include <string>

class SafeMotor {
private:
    // PRIVATE: Nobody outside this class can touch these variables directly!
    std::string name_;
    int speed_pwm_; // safe between -255 and +255

public:
    void init(std::string name) {
        name_ = name;
        speed_pwm_ = 0;
    }

    // SAFE SETTER: Clamps speeds like a hardware fuse
    void setSpeed(int requested_speed) {
        if (requested_speed > 255) {
            std::cout << "[FUSE TRIGGERED] " << requested_speed 
                      << " PWM is too high! Clamped to safe limit: 255.\n";
            speed_pwm_ = 255;
        } 
        else if (requested_speed < -255) {
            std::cout << "[FUSE TRIGGERED] Reverse speed too fast! Clamped to: -255.\n";
            speed_pwm_ = -255;
        } 
        else {
            speed_pwm_ = requested_speed;
        }
    }

    // GETTER: Allows the user to read the speed safely (read-only)
    int getSpeed() const {
        return speed_pwm_;
    }

    void status() const {
        std::cout << "Motor [" << name_ << "] is running at: " << speed_pwm_ << " PWM\n";
    }
};

int main() {
    SafeMotor motor;
    motor.init("Left-Drive");

    // UNCOMMENTING THIS WOULD CAUSE A COMPILATION ERROR:
    // motor.speed_pwm_ = 99999; // ERROR: 'speed_pwm_' is private!

    std::cout << "--- TESTING SAFE MOTOR CONTROLLER ---\n";

    // 1. Sending normal speed
    motor.setSpeed(180);
    motor.status();

    // 2. Dangerous input: Someone tries to send 50,000 PWM!
    std::cout << "\n[Accidental bug in navigation code: requesting 50000 PWM]\n";
    motor.setSpeed(50000);
    motor.status(); // Motor stayed safe at 255!

    return 0;
}

