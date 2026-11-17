// ==============================================================
// File: 01_hello_robot.cpp
// Concept: Your Very First C++ Program (The Robot Boot Screen)
// ==============================================================
//
// Hey! Welcome to C++.
// In college, you usually start with "Hello World".
// But we are robotics engineers, so let's boot up our first robot!
//
// To compile and run this in your terminal, type:
//    g++ 01_hello_robot.cpp -o hello_robot
//    ./hello_robot
// ==============================================================

// 1. #include is like grabbing a tool from your toolbox.
// <iostream> gives us tools to print text on the screen.
#include <iostream>

// 2. main() is where the computer ALWAYS starts reading your code.
// Think of it like turning on the robot's main power switch.
int main() {
    

    std::cout << "System check: All motors ready.\n";
    std::cout << "System check: Camera ready.\n";
    std::cout << "Robot is standing by for orders!\n";

    // return 0 tells the operating system: "Robot finished with 0 errors!"
    return 0;
}

