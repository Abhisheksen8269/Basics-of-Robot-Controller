// ==============================================================
// File: 06_robot_arrays.cpp
// Concept: Arrays (Storing Multi-Sensor Robot Readings)
// ==============================================================
//
// What is an array?
// A regular variable holds ONE number:
//    double front_distance = 15.0;
//
// But a real robot has 4 ultrasonic sensors (Front, Back, Left, Right).
// An ARRAY is an egg carton that holds MULTIPLE numbers in a row under ONE name!
//
// Remember: C++ starts counting at 0, not 1!
// index [0] = Front
// index [1] = Back
// index [2] = Left
// index [3] = Right
// ==============================================================

#include <iostream>

int main() {
    // An array of 4 sensor readings (in centimeters)
    double sensor_distances[4] = {45.2, 120.5, 12.4, 88.0};

    // Print individual readings using their index number [ ]
    std::cout << "--- 4-WAY COLLISION SENSOR READINGS ---\n";
    std::cout << "Front Sensor [0]: " << sensor_distances[0] << " cm\n";
    std::cout << "Back Sensor  [1]: " << sensor_distances[1] << " cm\n";
    std::cout << "Left Sensor  [2]: " << sensor_distances[2] << " cm\n";
    std::cout << "Right Sensor [3]: " << sensor_distances[3] << " cm\n";

    // Loop through all sensors to find the CLOSEST obstacle
    double closest_obstacle = sensor_distances[0]; // assume first is closest
    int closest_index = 0;

    for (int i = 0; i < 4; i++) {
        if (sensor_distances[i] < closest_obstacle) {
            closest_obstacle = sensor_distances[i];
            closest_index = i;
        }
    }

    std::cout << "\n[SAFETY SCANNER RESULT]\n";
    std::cout << "Closest obstacle is at sensor index [" << closest_index 
              << "] at a distance of " << closest_obstacle << " cm!\n";

    if (closest_obstacle < 20.0) {
        std::cout << "WARNING: Dangerously close obstacle! Steer away immediately!\n";
    }

    return 0;
}

