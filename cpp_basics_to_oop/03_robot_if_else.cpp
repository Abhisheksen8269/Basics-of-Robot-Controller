// ==============================================================
// File: 03_robot_if_else.cpp
// Concept: Making Decisions (if, else if, else)
// ==============================================================
//
// A robot is not smart on its own.
// We make it smart by teaching it to make decisions based on sensors!
//
// Pattern:
//   if (condition is true) {
//       do this action;
//   } else if (another condition is true) {
//       do this other action;
//   } else {
//       default action;
//   }
// ==============================================================

#include <iostream>

int main() {
    // Let's pretend our ultrasonic sensor detected an obstacle ahead
    double obstacle_distance_cm = 14.5; // in centimeters
    double battery_percent = 18.0;      // 18% remaining

    std::cout << "Sensor reading: Obstacle at " << obstacle_distance_cm << " cm\n";

    // 1. OBSTACLE AVOIDANCE DECISION
    if (obstacle_distance_cm < 10.0) {
        // Dangerously close!
        std::cout << "ACTION: EMERGENCY BRAKE! Too close to wall!\n";
    } 
    else if (obstacle_distance_cm < 30.0) {
        // Getting close, slow down and turn
        std::cout << "ACTION: SLOW DOWN and turn right to avoid collision.\n";
    } 
    else {
        // Road is wide open
        std::cout << "ACTION: FULL SPEED AHEAD! Path is clear.\n";
    }

    // 2. BATTERY SAFETY CHECK
    std::cout << "\nChecking battery health...\n";
    if (battery_percent <= 20.0) {
        std::cout << "WARNING: Battery is below 20%! Return to charging dock immediately!\n";
    } else {
        std::cout << "Battery OK. Continue mission.\n";
    }

    return 0;
}

