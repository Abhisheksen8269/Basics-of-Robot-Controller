// ==============================================================
// File: 04_robot_loops.cpp
// Concept: Repeating Actions with Loops (while & for)
// ==============================================================
//
// In robotics, things happen in loops:
// 1. while loop: "Keep doing this WHILE the condition is true"
//    Example: Keep driving while battery > 0
//
// 2. for loop: "Do this a FIXED number of times"
//    Example: Take 5 sensor samples, or 3-2-1 launch countdown
// ==============================================================

#include <iostream>

int main() {
    // -----------------------------------------------------------
    // PART 1: The 'for' loop (Fixed count countdown)
    // -----------------------------------------------------------
    std::cout << "--- LAUNCH COUNTDOWN ---\n";
    
    // int i = 3;  -> start at 3
    // i >= 1;     -> keep going while i is greater than or equal to 1
    // i--         -> decrease i by 1 each time
    for (int i = 3; i >= 1; i--) {
        std::cout << "Ignition in " << i << " seconds...\n";
    }
    std::cout << "ROBOT DEPLOYED!\n\n";

    // -----------------------------------------------------------
    // PART 2: The 'while' loop (Driving until battery drains)
    // -----------------------------------------------------------
    std::cout << "--- PATROL MISSION STARTED ---\n";
    
    int battery = 100; // 100% full battery
    int waypoint = 1;

    // Keep patrolling as long as we have more than 20% battery
    while (battery > 20) {
        std::cout << "Reached Waypoint #" << waypoint 
                  << " | Battery remaining: " << battery << "%\n";
        
        battery = battery - 25; // Driving uses 25% battery each lap
        waypoint++;             // Go to next waypoint (waypoint = waypoint + 1)
    }

    std::cout << "\nBattery is now at " << battery << "%! Mission paused.\n";
    std::cout << "Robot safely returned to base for recharging.\n";

    return 0;
}

