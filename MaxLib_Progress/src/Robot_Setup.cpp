#include "main.h"

brain Brain;
controller C1;

// Motors
motor RF(0, ratio6_1, false);
motor RM(0, ratio6_1, false);
motor RB(0, ratio18_1, false); // 5.5W 
motor LF(0, ratio6_1, false);
motor LM(0, ratio6_1, false);
motor LB(0, ratio18_1, false); // 5.5W

motor Intake(0, ratio6_1, false);

motor Lift1(0, ratio18_1, false);
motor Lift2(0, ratio18_1, false); // 5.5W
motor Lift3(0, ratio18_1, false); // 5.5W

// Sensors
inertial gt(0);

rotation vertTracker(0, false);
rotation horizontalTracker(0, false);

aivision::colordesc Blue(1, 55, 188, 248, 12, 0.6);
aivision::colordesc Red(2, 239, 50, 95, 12, 0.6);
aivision::colordesc Neutral(3, 0, 0, 0, 0, 0);
aivision camera(0, Blue, Red);

// Pistons
digital_out p1(A);
digital_out p2(B);
digital_out p3(C);

float trackWidth = 10.0;
float wheelDiameter = 2.75;
int driveRPM = 600;
int wheelGear = 48;
int motorGear = 36;

float wheelRPM = driveRPM * (motorGear / wheelGear);
float wheelCircumference = wheelDiameter * M_PI;
