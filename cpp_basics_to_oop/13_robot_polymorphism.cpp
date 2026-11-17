// ==============================================================
// File: 13_robot_polymorphism.cpp
// Concept: Polymorphism & Virtual Functions (The Universal Sensor Loop)
// ==============================================================
//
// What is Polymorphism?
// "Poly" = Many, "Morph" = Form.
//
// Real World Analogy: The Universal Multimeter
// A multimeter has one dial with a single "Read" button.
// Whether you probe voltage, current, or resistance, you just press "Read".
//
// In Robotics:
// A robot may have Sonar, Lidar, and IR sensors.
// We want to loop through ALL of them and read distances using ONE line:
//     s->readDistanceCm();
//
// The Secret:
// 1. In Parent: `virtual double readDistanceCm() = 0;` (Pure virtual)
// 2. In Child : `double readDistanceCm() override;`
// 3. Always include `virtual ~Sensor() {}` in base classes!
// ==============================================================

#include <iostream>
#include <string>
#include <vector>

// 1. Abstract Base Class (The Interface)
class Sensor {
protected:
    std::string name_;

public:
    Sensor(std::string name) : name_(name) {}
    virtual ~Sensor() {} // Virtual destructor for safe cleanup

    // '= 0' means "pure virtual".
    // It says: "Every sensor MUST have this function, but each sensor computes it differently!"
    virtual double readDistanceCm() = 0;

    std::string getName() const { return name_; }
};

// 2. Child 1: Ultrasonic calculates distance using sound echo time
class UltrasonicSensor : public Sensor {
public:
    UltrasonicSensor() : Sensor("Ultrasonic (Sonar)") {}

    double readDistanceCm() override {
        // Pretend hardware calculation: (echo_time_us * 0.034) / 2
        return 22.4; // cm
    }
};

// 3. Child 2: Lidar calculates distance using speed of light time-of-flight
class LidarSensor : public Sensor {
public:
    LidarSensor() : Sensor("2D Lidar Scanner") {}

    double readDistanceCm() override {
        // Pretend hardware calculation: (speed_of_light * time) / 2
        return 145.8; // cm
    }
};

int main() {
    UltrasonicSensor frontSonar;
    LidarSensor topLidar;

    // We store generic Sensor pointers in a list
    std::vector<Sensor*> robotSensors;
    robotSensors.push_back(&frontSonar);
    robotSensors.push_back(&topLidar);

    std::cout << "--- READING ALL ROBOT SENSORS IN ONE UNIFIED LOOP ---\n";

    // Polymorphism in action: ONE loop handles any sensor in the universe!
    for (Sensor* s : robotSensors) {
        std::cout << "Device: " << s->getName() 
                  << " | Detected Distance: " << s->readDistanceCm() << " cm\n";
    }

    return 0;
}

