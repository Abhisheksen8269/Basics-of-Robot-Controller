// ==============================================================
// File: 08_robot_struct.cpp
// Concept: Structs (Grouping Related Robot Data)
// ==============================================================
//
// In robotics, data always travels in groups:
// - A 2D Pose is always: x, y, and heading angle theta.
// - An IMU reading is always: ax, ay, az.
//
// Instead of writing 3 separate variables everywhere, a 'struct'
// bundles them into one single custom data type!
// ==============================================================

#include <iostream>

// Grouping x, y, and theta (heading in radians)
struct RobotPose {
    double x;     // position in meters
    double y;     // position in meters
    double theta; // angle in radians (0.0 = facing North)
};

// Function that updates a robot's pose by reference
void moveRobotForward(RobotPose& pose, double distance_m) {
    // For simplicity, pretend we are moving along the X axis
    pose.x = pose.x + distance_m;
    std::cout << "[Movement] Drove " << distance_m << " meters forward.\n";
}

int main() {
    // Create our robot's pose starting at origin (0, 0, 0)
    RobotPose my_rover;
    my_rover.x = 0.0;
    my_rover.y = 0.0;
    my_rover.theta = 0.0;

    std::cout << "--- ROBOT ODOMETRY ---\n";
    std::cout << "Initial Position: X = " << my_rover.x 
              << " m, Y = " << my_rover.y 
              << " m, Theta = " << my_rover.theta << " rad\n";

    // Move the robot!
    moveRobotForward(my_rover, 2.5);
    moveRobotForward(my_rover, 1.0);

    std::cout << "Updated Position: X = " << my_rover.x 
              << " m, Y = " << my_rover.y 
              << " m, Theta = " << my_rover.theta << " rad\n";

    // Why is struct not enough for full robotics?
    // In a struct, anyone can accidentally corrupt data:
    // my_rover.x = -999999.0; // Nobody stopped this invalid jump!
    // That is why we upgrade to CLASSES in OOP!
    return 0;
}

