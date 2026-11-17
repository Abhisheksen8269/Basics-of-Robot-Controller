// ==============================================================
// File: 12_robot_inheritance.cpp
// Concept: Inheritance (The Robot Sensor Catalog - "IS-A")
// ==============================================================
//
// What is Inheritance?
// A robot has many sensors: Ultrasonic, Lidar, Infrared, Camera.
// They ALL have:
//   - a name (e.g., "Front Sonar")
//   - a hardware GPIO pin (e.g., Pin 7)
//   - a power-up sequence
//
// Instead of re-typing those same 3 things into every single sensor file,
// we create a BASE CLASS called 'Sensor'.
//
// Then specific sensors INHERIT from it:
// - Ultrasonic IS A Sensor.
// - Lidar IS A Sensor.
// ==============================================================

#include <iostream>
#include <string>

// 1. BASE CLASS (Parent)
class Sensor {
protected:
    // 'protected' means child classes can access these directly,
    // but code inside main() cannot mess with them!
    std::string name_;
    int pin_number_;

public:
    Sensor(std::string name, int pin) {
        name_ = name;
        pin_number_ = pin;
    }

    void powerOn() {
        std::cout << "[Power Up] " << name_ << " on GPIO pin " << pin_number_ << " initialized.\n";
    }

    std::string getName() const { return name_; }
};

// 2. CHILD CLASS 1: Ultrasonic Sensor (Sound waves)
// Syntax: class Child : public Parent
class UltrasonicSensor : public Sensor {
public:
    // Pass name and pin up to parent constructor
    UltrasonicSensor(int pin) : Sensor("Ultrasonic", pin) {}

    void pingSoundWave() {
        std::cout << name_ << " transmitting 40 kHz ultrasonic pulse...\n";
    }
};

// 3. CHILD CLASS 2: Lidar Sensor (Laser pulses)
class LidarSensor : public Sensor {
public:
    LidarSensor(int pin) : Sensor("Lidar", pin) {}

    void scanLaser360() {
        std::cout << name_ << " firing 360-degree rotating laser scanner...\n";
    }
};

int main() {
    std::cout << "--- ROBOT SENSOR HARDWARE BRING-UP ---\n";

    UltrasonicSensor frontSonar(7);
    LidarSensor topLidar(12);

    // Both sensors inherited powerOn() from the base Sensor class!
    frontSonar.powerOn();
    topLidar.powerOn();

    // Each child sensor also has its own unique capabilities:
    std::cout << "\n--- Triggering Sensors ---\n";
    frontSonar.pingSoundWave();
    topLidar.scanLaser360();

    return 0;
}

