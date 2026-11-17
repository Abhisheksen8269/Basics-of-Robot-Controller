// ==============================================================
// File: 09_robot_class_and_object.cpp
// Concept: Classes and Objects (The Motor Blueprint)
// ==============================================================
//
// What is the difference between a Struct and a Class?
// - A Struct is just a dumb box of numbers (passive data).
// - A Class bundles DATA + FUNCTIONS (ACTIONS) together!
//
// Analogy:
// - Class  = The CAD 3D model of a DC Motor (Blueprint).
// - Object = The physical DC motor you hold in your hand.
// ==============================================================

#include <iostream>
#include <string>

// 1. THE CLASS (Blueprint)
class Motor {
public:
    // Variables inside a class are called "Member Variables" (What it HAS)
    std::string name;
    int speed_pwm; // 0 to 255

    // Functions inside a class are called "Member Functions" (What it CAN DO)
    void spin() {
        std::cout << "[Motor " << name << "] Spinning at " << speed_pwm << " PWM!\n";
    }

    void brake() {
        speed_pwm = 0;
        std::cout << "[Motor " << name << "] BRAKE applied! Speed is now 0.\n";
    }
};

int main() {
    std::cout << "--- 2-WHEELED ROBOT CHASSIS ---\n";

    // 2. THE OBJECTS (Creating two real motors from one blueprint)
    Motor left_wheel;
    left_wheel.name = "Left";
    left_wheel.speed_pwm = 150;

    Motor right_wheel;
    right_wheel.name = "Right";
    right_wheel.speed_pwm = 150;

    // Use the dot (.) operator to command each motor
    left_wheel.spin();
    right_wheel.spin();

    std::cout << "\n[Obstacle Detected ahead!]\n";
    left_wheel.brake();
    right_wheel.brake();

    return 0;
}

