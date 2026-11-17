// ==============================================================
// File: 11_robot_constructor_destructor.cpp
// Concept: Constructors and Destructors (Bootup and Shutdown)
// ==============================================================
//
// In robotics:
// 1. CONSTRUCTOR = Bootup Sequence:
//    Runs AUTOMATICALLY the instant an object is created.
//    Initializes pins, calibrates sensors, sets speed to 0.
//    Syntax: Same name as class, NO return type!
//
// 2. DESTRUCTOR = Safe Shutdown / Emergency Stop:
//    Runs AUTOMATICALLY when the object is destroyed or program exits.
//    Turns off motor signals so the robot doesn't shoot across the room!
//    Syntax: Tilde '~' + class name.
// ==============================================================

#include <iostream>
#include <string>

class RoboticActuator {
private:
    std::string name_;
    int pwm_speed_;

public:
    // 1. CONSTRUCTOR (Runs on Power ON)
    RoboticActuator(std::string actuator_name) {
        name_ = actuator_name;
        pwm_speed_ = 0; // Guaranteed safe starting speed!
        std::cout << "[POWER ON] Actuator [" << name_ << "] boot complete. Ready at 0 PWM.\n";
    }

    // 2. DESTRUCTOR (Runs on Power OFF)
    ~RoboticActuator() {
        pwm_speed_ = 0; // Kill power to prevent runaway motors!
        std::cout << "[POWER OFF] Actuator [" << name_ << "] shut down safely. Coils de-energized.\n";
    }

    void drive(int pwm) {
        pwm_speed_ = pwm;
        std::cout << "Actuator [" << name_ << "] moving at " << pwm_speed_ << " PWM.\n";
    }
};

int main() {
    std::cout << "=== MAIN SYSTEM START ===\n";

    {
        // Curly brackets create a temporary "mission scope"
        std::cout << "\n--- Subsystem: Deploying Robotic Gripper ---\n";
        RoboticActuator gripper("Gripper-Claw");

        gripper.drive(120);

        std::cout << "--- Mission Finished: Exiting Gripper Scope ---\n";
    } // <-- Gripper leaves scope and DIES right here! Destructor runs automatically!

    std::cout << "\n=== MAIN SYSTEM FINISHED ===\n";
    return 0;
}

