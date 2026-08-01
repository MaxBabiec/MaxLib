#pragma once
#include "main.h"

void inchDrive(float target, bool reverse, int maxSpeed = 60);

void gyroTurn(float target, string forceDir = "none", int maxSpeed = 70);

void swingTurn(float target, string side, bool reverse = false, int maxSpeed = 500, float radius = 0);