// ==============================================================
// File: 07_robot_references_pointers.cpp
// Concept: References and Pointers in Super Simple Words
// ==============================================================
//
// Freshers get terrified of Pointers and References.
// Don't panic! Here is the physical robot mental model:
//
// 1. Pass by VALUE (The Photocopy):
//    You send a photocopy of your robot's battery percentage to a charging station.
//    The charging station writes "100%" on the paper.
//    Did your REAL battery charge? NO! Only the copy changed!
//
// 2. Pass by REFERENCE (&) (The Real Thing):
//    The '&' symbol creates a direct nickname/wire to the REAL battery.
//    When the charging station fills it, the REAL battery is charged!
//
// 3. POINTER (*) (The GPS Tag / House Address):
//    A pointer is just a sticky note with the memory address of the robot written on it.
//    &battery = "What is the memory address of this battery?"
//    *pointer = "Go to that address and read/write the value inside!"
// ==============================================================

#include <iostream>

// Attempt 1: WRONG (Pass by Value - modifies a copy!)
void chargeBatteryFail(int battery) {
    battery = 100; // Only changes the local copy!
    std::cout << "   [Inside function] Local copy changed to: " << battery << "%\n";
}

// Attempt 2: RIGHT (Pass by Reference '&' - modifies the real hardware!)
void chargeBatterySuccess(int& battery) {
    battery = 100; // Directly updates the real battery!
    std::cout << "   [Inside function] Real battery changed to: " << battery << "%\n";
}

int main() {
    int robot_battery = 25; // Robot has 25% battery

    std::cout << "Starting battery level: " << robot_battery << "%\n";

    // 1. Trying to charge by copy (Value)
    std::cout << "\n[Attempt 1] Calling chargeBatteryFail(robot_battery)...\n";
    chargeBatteryFail(robot_battery);
    std::cout << "Battery level after fail attempt: " << robot_battery << "% (STILL EMPTY!)\n";

    // 2. Charging by Reference (&)
    std::cout << "\n[Attempt 2] Calling chargeBatterySuccess(robot_battery)...\n";
    chargeBatterySuccess(robot_battery);
    std::cout << "Battery level after success attempt: " << robot_battery << "% (FULLY CHARGED!)\n";

    // -----------------------------------------------------------
    // 3. POINTERS IN 3 LINES:
    // -----------------------------------------------------------
    std::cout << "\n--- POINTERS DEMYSTIFIED ---\n";
    int wheel_speed = 50;

    // '&' gives the memory address (the house number in computer RAM)
    // '*' declares a pointer variable that stores this address
    int* ptr_to_speed = &wheel_speed;

    std::cout << "Value of wheel_speed          : " << wheel_speed << "\n";
    std::cout << "Memory address of wheel_speed : " << ptr_to_speed << " (Address in RAM)\n";
    
    // '*' in front of a pointer means "dereference" (go to the address and grab the value)
    std::cout << "Value read THROUGH pointer    : " << *ptr_to_speed << "\n";

    // Change speed using the pointer!
    *ptr_to_speed = 95;
    std::cout << "wheel_speed after *ptr = 95   : " << wheel_speed << "\n";

    return 0;
}
