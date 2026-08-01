#pragma once
#include "main.h"

void setDriveBrake(brakeType b);

void driveStop(brakeType b);

void drive(int rs, int ls, int wt);

void voltDrive(int rs, int ls, int wt);

void rpmDrive(int rs, int ls, int wt);

void intakeRun(int speed);