#pragma once
#include "main.h"

extern float trackWidth;
extern float wheelDiameter;
extern int wheelGear;
extern int motorGear;
extern int driveRPM;

extern float wheelRPM;
extern float wheelCircumference;

extern brain Brain;
extern controller C1;

extern motor RF;
extern motor RM;
extern motor RB;
extern motor LF;
extern motor LM;
extern motor LB;

extern motor Intake;

extern motor Lift1;
extern motor Lift2;
extern motor Lift3;

extern inertial gt;

extern rotation vertTracker;
extern rotation horizontalTracker;

extern aivision::colordesc Red;
extern aivision::colordesc Blue;
extern aivision::colordesc Neutral;
extern aivision camera;

extern digital_out p1;
extern digital_out p2;
extern digital_out p3;