// ==============================================================
// File: 05_robot_functions.cpp
// Concept: Functions (Reusable Robot Commands)
// ==============================================================
//
// What is a function?
// Instead of writing the same 10 lines of code every time the robot
// wants to calculate motor speed or sound the buzzer, you write it
// ONCE inside a named function, and just call it whenever you need it!
//
// Pattern:
//   return_type function_name(input_parameters) {
//       // what the function does
//       return result;
//   }
//
// If a function doesn't return anything (just does an action), 
// we use 'void' as the return type.
// ==============================================================

#include <iostream>

// 1. A function that does an action (returns nothing -> 'void')
void playBuzzerBeep(int times) {
    std::cout << "[Buzzer] Beeping " << times << " time(s): ";
    for (int i = 0; i < times; i++) {
        std::cout << "BEEP! ";
    }
    std::cout << "\n";
}

// 2. A function that takes inputs and calculates a result
// Clamps raw speed into safe Arduino PWM range (0 to 255)
int clampSpeed(int raw_speed) {
    if (raw_speed > 255) {
        return 255; // Cap at max speed
    } else if (raw_speed < 0) {
        return 0;   // No negative speed
    } else {
        return raw_speed;
    }
}

// 3. A function to calculate travel distance: Distance = Speed * Time
double calculateTravelDistance(double speed_mps, double time_sec) {
    double distance = speed_mps * time_sec;
    return distance;
}

int main() {
    std::cout << "--- ROBOT FUNCTION DEMO ---\n";

    // Calling the void function
    playBuzzerBeep(3);

    // Calling the math functions
    int requested_speed = 350; // Too fast!
    int safe_speed = clampSpeed(requested_speed);
    std::cout << "Requested speed: " << requested_speed 
              << " -> Clamped safe PWM: " << safe_speed << "\n";

    double speed = 1.5;   // 1.5 meters per second
    double seconds = 10;  // 10 seconds of driving
    double distance = calculateTravelDistance(speed, seconds);
    std::cout << "At " << speed << " m/s for " << seconds 
              << " seconds, robot traveled: " << distance << " meters.\n";

    return 0;
}

