#include "main.h"

void setDriveBrake(brakeType b)
{
    RF.setBrake(b);
    RM.setBrake(b);
    RB.setBrake(b);
    LF.setBrake(b);
    LM.setBrake(b);
    LB.setBrake(b);
}

void driveStop(brakeType b)
{
    RF.stop(b);
    RM.stop(b);
    RB.stop(b);
    LF.stop(b);
    LM.stop(b);
    LB.stop(b);
}

void drive(int rs, int ls, int wt)
{
    RF.spin(fwd, rs, pct);
    RM.spin(fwd, rs, pct);
    RB.spin(fwd, rs, pct);

    LF.spin(fwd, ls, pct);
    LM.spin(fwd, ls, pct);
    LB.spin(fwd, ls, pct);

    wait(wt, msec);
    driveStop(brake);
}

void voltDrive(int rs, int ls, int wt)
{
    RF.spin(fwd, rs * 120, vex::voltageUnits::mV);
    RM.spin(fwd, rs * 120, vex::voltageUnits::mV);
    RB.spin(fwd, rs * 120, vex::voltageUnits::mV);

    LF.spin(fwd, ls * 120, vex::voltageUnits::mV);
    LM.spin(fwd, ls * 120, vex::voltageUnits::mV);
    LB.spin(fwd, ls * 120, vex::voltageUnits::mV);

    wait(wt, msec);
    driveStop(coast);
}

void rpmDrive(int rs, int ls, int wt)
{
    RF.spin(fwd, rs, rpm);
    RM.spin(fwd, rs, rpm);
    RB.spin(fwd, rs / 3, rpm);

    LF.spin(fwd, ls, rpm);
    LM.spin(fwd, ls, rpm);
    LB.spin(fwd, ls / 3, rpm);

    wait(wt, msec);
    driveStop(brake);
}

void intakeRun(int speed)
{
    Intake.spin(fwd, speed * 120, vex::voltageUnits::mV);
}

bool p1Pos = false;
void p1Toggle()
{
    p1.set(!p1Pos);
    p1Pos = !p1Pos;
}
