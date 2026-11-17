// ==============================================================
// File: 02_robot_variables.cpp
// Concept: Variables and Data Types (Robot Hardware Specs)
// ==============================================================
//
// What is a variable?
// Think of a variable as a labeled cardboard box on your robot.
// You put data inside it so you can read or change it later.
//
// In C++, you have to tell the computer WHAT KIND of thing is in the box:
// - int    : whole numbers (like pin numbers: 2, 13, -5)
// - double : decimal numbers (like battery voltage: 11.85, 3.14)
// - bool   : true or false (like emergency switch: true or false)
// - char   : single letter (like drive mode: 'A' for Auto, 'M' for Manual)
// - string : words and sentences (like robot name: "Wall-E")
// ==============================================================

#include <iostream>
#include <string> // Needed whenever you want to use words/sentences

int main() {
    // 1. Robot Identity
    std::string robot_name = "Rover-1";

    // 2. Hardware Pin on the microcontroller (whole number)
    int motor_pwm_pin = 9;

    // 3. Sensor / Battery measurements (decimal numbers)
    double battery_voltage = 12.6; // 12.6 Volts (Full battery)
    double speed_mps = 1.25;       // 1.25 meters per second

    // 4. Safety switch (true or false)
    bool is_emergency_stop_pressed = false;

    // 5. Operating mode (single character)
    char drive_mode = 'A'; // 'A' = Autonomous, 'M' = Manual

    // Now let's print all our robot specs to the screen:
    std::cout << "--- ROBOT STATUS REPORT ---\n";
    std::cout << "Robot Name        : " << robot_name << "\n";
    std::cout << "Motor PWM Pin     : " << motor_pwm_pin << "\n";
    std::cout << "Battery Voltage   : " << battery_voltage << " Volts\n";
    std::cout << "Current Speed     : " << speed_mps << " m/s\n";
    std::cout << "Emergency Stop?   : " << is_emergency_stop_pressed << " (0 = NO, 1 = YES)\n";
    std::cout << "Drive Mode        : " << drive_mode << "\n";

    // Changing a variable: Let's pretend the robot drove for 1 hour
    std::cout << "\n[1 Hour Later...]\n";
    battery_voltage = 10.8; // Battery drained!
    std::cout << "Updated Battery   : " << battery_voltage << " Volts (Needs Charging!)\n";

    return 0;
}

