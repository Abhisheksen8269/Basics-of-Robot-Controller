// ==============================================================
// File: 15_robot_mini_project.cpp
// Concept: Capstone Project: Autonomous Obstacle-Avoiding Rover
// ==============================================================
//
// CONGRATULATIONS! You made it through Basics of C++ and OOP!
//
// In this final mini-project, we combine ALL concepts:
// 1. Classes & Objects (Motors, Sensors, Robot)
// 2. Encapsulation (Safe motor speeds with clamping)
// 3. Inheritance (Sensor -> FrontSonar)
// 4. Polymorphism (Reading obstacles through Sensor pointers)
// 5. Composition (Robot HAS motors and sensors)
//
// Let's run a full autonomous obstacle avoidance loop!
// ==============================================================

#include <iostream>
#include <string>
#include <vector>

// --------------------------------------------------------------
// PILLAR 1: SENSOR HIERARCHY (Inheritance & Polymorphism)
// --------------------------------------------------------------
class Sensor {
public:
    virtual ~Sensor() {}
    virtual std::string getName() const = 0;
    virtual double getDistanceCm() = 0;
};

class FrontUltrasonic : public Sensor {
private:
    double simulated_distance_;

public:
    FrontUltrasonic() : simulated_distance_(50.0) {}

    std::string getName() const override {
        return "Front HC-SR04 Sonar";
    }

    double getDistanceCm() override {
        return simulated_distance_;
    }

    // Helper to simulate an obstacle appearing closer
    void simulateObstacleApproaching(double dist) {
        simulated_distance_ = dist;
    }
};

// --------------------------------------------------------------
// PILLAR 2: MOTOR ACTUATOR (Encapsulation)
// --------------------------------------------------------------
class Motor {
private:
    std::string side_;
    int speed_pwm_;

public:
    Motor(std::string side) : side_(side), speed_pwm_(0) {}

    void setSpeed(int pwm) {
        // Safety clamp: -255 to 255
        if (pwm > 255) pwm = 255;
        if (pwm < -255) pwm = -255;
        speed_pwm_ = pwm;
    }

    int getSpeed() const { return speed_pwm_; }
    void stop() { speed_pwm_ = 0; }
};

// --------------------------------------------------------------
// PILLAR 3: COMPLETE ROVER (Composition)
// --------------------------------------------------------------
class AutonomousRover {
private:
    std::string name_;
    Motor leftWheel_;
    Motor rightWheel_;
    std::vector<Sensor*> sensors_;

public:
    AutonomousRover(std::string name)
        : name_(name), leftWheel_("Left"), rightWheel_("Right") {
        std::cout << "[Bootup] Autonomous Rover '" << name_ << "' is ONLINE!\n";
    }

    void mountSensor(Sensor* s) {
        sensors_.push_back(s);
        std::cout << "[Mounted] " << s->getName() << " installed on rover chassis.\n";
    }

    void driveForward(int speed) {
        leftWheel_.setSpeed(speed);
        rightWheel_.setSpeed(speed);
        std::cout << "[Drive] Rover cruising forward at " << speed << " PWM.\n";
    }

    void emergencyBrake() {
        leftWheel_.stop();
        rightWheel_.stop();
        std::cout << "[Safety] !!! EMERGENCY BRAKE TRIGGERED !!! Both motors locked at 0 PWM.\n";
    }

    // AUTONOMOUS NAVIGATION LOOP
    void runNavigationCycle() {
        std::cout << "\n--- SCANNING AHEAD ---\n";
        for (Sensor* s : sensors_) {
            double distance = s->getDistanceCm();
            std::cout << "[" << s->getName() << "] reports distance: " << distance << " cm\n";

            if (distance < 20.0) { // Safety threshold: 20 cm
                std::cout << "--> ALERT: Wall detected at " << distance << " cm! Stopping!\n";
                emergencyBrake();
                return;
            }
        }
        std::cout << "--> Path is clear. Continuing mission.\n";
    }
};

// --------------------------------------------------------------
// 4. MAIN SIMULATION RUN
// --------------------------------------------------------------
int main() {
    std::cout << "==========================================\n";
    std::cout << "     ROBOTICS OOP AUTONOMOUS TEST RUN     \n";
    std::cout << "==========================================\n";

    AutonomousRover myRover("Scout-1");
    FrontUltrasonic sonar;

    // Attach sensor using polymorphism
    myRover.mountSensor(&sonar);

    // Step 1: Normal driving when road is clear (50 cm)
    std::cout << "\n[TEST STEP 1: Driving with clear path ahead]\n";
    myRover.driveForward(180);
    myRover.runNavigationCycle();

    // Step 2: Obstacle suddenly gets close (12 cm)!
    std::cout << "\n[TEST STEP 2: Wall appears 12 cm ahead!]\n";
    sonar.simulateObstacleApproaching(12.0);
    myRover.runNavigationCycle();

    std::cout << "\n==========================================\n";
    std::cout << "       SIMULATION MISSION COMPLETE        \n";
    std::cout << "==========================================\n";
    return 0;
}

