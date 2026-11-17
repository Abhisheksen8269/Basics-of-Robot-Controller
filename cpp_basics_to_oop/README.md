# 🤖 Beginner C++ & OOP for Robotics (1st-Semester Edition)

This folder contains **15 standalone, beginner-friendly C++ programs** designed for a 1st-semester engineering student.
Every file is heavily commented, uses simple physical robotics analogies, avoids confusing jargon, and compiles with zero warnings.

---

## 📚 Curriculum Index & File Map

### Part 1: C++ Basics (The Fundamentals)
| File | Concept | Hardware Analogy |
| :--- | :--- | :--- |
| **`01_hello_robot.cpp`** | `cout`, `main()`, comments, compiling | Robot boot screen & terminal display |
| **`02_robot_variables.cpp`** | `int`, `double`, `bool`, `char`, `string` | Battery voltage, speed, pin numbers, e-stop |
| **`03_robot_if_else.cpp`** | `if`, `else if`, `else` | Obstacle collision detection & low-battery warnings |
| **`04_robot_loops.cpp`** | `while` loop & `for` loop | Launch countdown & battery patrol loop |
| **`05_robot_functions.cpp`** | Reusable functions, parameters, `void` | Clamping motor PWM & distance calculation |
| **`06_robot_arrays.cpp`** | Arrays & indexing `[0]` to `[3]` | Storing 4-direction sonar collision sensors |
| **`07_robot_references_pointers.cpp`** | Pass-by-value vs Reference (`&`) vs Pointer (`*`) | Charging battery by photocopy vs real battery wire |

---

### Part 2: Object-Oriented Programming (OOP)
| File | Concept | Hardware Analogy |
| :--- | :--- | :--- |
| **`08_robot_struct.cpp`** | `struct` (Grouping data) | 2D Robot Pose (x, y, theta) |
| **`09_robot_class_and_object.cpp`** | `class` vs Object, dot `.` operator | CAD blueprint vs 3D printed motor |
| **`10_robot_encapsulation.cpp`** | `private` data + safe `setSpeed()` clamp | Hardware circuit breaker / fuse against burned motors |
| **`11_robot_constructor_destructor.cpp`** | Constructor `Motor()` & Destructor `~Motor()` | Hardware boot calibration & auto emergency stop |
| **`12_robot_inheritance.cpp`** | Base class & Child class ("IS-A") | Generic `Sensor` $\rightarrow$ `Ultrasonic` & `Lidar` |
| **`13_robot_polymorphism.cpp`** | `virtual`, `override`, Base pointers `Sensor*` | Universal multimeter: read all sensors in 1 loop |
| **`14_robot_composition.cpp`** | Composition ("HAS-A" vs "IS-A") | LEGO bricks: Robot *has* 2 motors & a battery |
| **`15_robot_mini_project.cpp`** | **Complete Capstone Rover** | Full autonomous obstacle avoidance simulation |

---

## 🛠️ How to Compile & Run

### 1. Compile & run any single file:
```bash
g++ -std=c++17 01_hello_robot.cpp -o 01_hello_robot
./01_hello_robot
```

### 2. Run all files sequentially:
```bash
chmod +x run_all.sh
./run_all.sh
```

