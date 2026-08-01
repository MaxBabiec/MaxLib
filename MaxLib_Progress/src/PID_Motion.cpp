#include <main.h>

void inchDrive(float target, bool reverse, int maxSpeed = 60)
{
    RF.setPosition(0, rev);
    float dist = 0;

    float facing = gt.heading();

    float kp = 2.0;
    float ki = 0.0;
    float kd = 0.0;

    float accuracy = 0.1;

    int integral = 0;
    float prevError = 0;

    int wt = 10;

    while (fabs(prevError) <= accuracy)
    {
        float error = target - dist;
        float proportional = error;
        integral = integral + error * wt;
        float derivative = (error - prevError) * wt;
        float output = kp * proportional + ki * integral + kd * derivative;

        float correction = gt.heading() - facing;

        if (output > maxSpeed)
        {
            output = maxSpeed;
        }

        if (reverse)
        {
            output = -output;
        }
        
        if (correction >= 1)
        {
            drive(output + correction, output, wt);
        }
        else if (correction <= -1)
        {
            drive(output, output + correction, wt);
        }
        else
        {
            drive(output, output, wt);
        }

        dist = (RF.position(rev) / (motorGear / wheelGear)) * wheelCircumference;
        prevError = error;
        // wait(wt, msec);
    }
}

void gyroTurn(float target, string forceDir = "none", int maxSpeed = 70)
{
    float heading = gt.heading();

    float kp = 0.5;
    float ki = 0.0;
    float kd = 0.0;

    float accuracy = 0.3;

    int integral = 0;
    float prevError = 0;

    int wt = 10;

    while (fabs(prevError) <= accuracy)
    {
        float error = target - heading;

        if(error > 180 && forceDir == "none")
        {
            error -= 360;
        }
        else if(error < -180 && forceDir == "none")
        {
            error += 360;
        }

        if(forceDir == "right" && error < 0)
        {
            error += 360;
        }
        else if(forceDir == "left" && error > 0)
        {
            error -= 360;
        }

        float proportional = error;
        integral = integral + error * wt;
        float derivative = (error - prevError) * wt;
        float output = kp * proportional + ki * integral + kd * derivative;

        if (output > maxSpeed)
        {
            output = maxSpeed;
        }

        drive(-output, output, wt);

        heading = gt.heading();
        prevError = error;
        // wait(wt, msec);
    }
}

void swingTurn(float target, string side, bool reverse = false, int maxSpeed = 500, float radius = 0)
{
    float heading = gt.heading();

    int rs;
    float innerR = 0;
    float outerR = trackWidth;
    float radiusRatio = innerR / outerR;

    float kp = 20.0;
    float ki = 0.0;
    float kd = 0.0;

    float accuracy = 0.3;

    int integral = 0;
    float prevError = 0;

    int wt = 10;

    while (fabs(prevError) <= accuracy)
    {
        float error = target - heading;
        float proportional = error;
        integral = integral + error * wt;
        float derivative = (error - prevError) * wt;
        float output = kp * proportional + ki * integral + kd * derivative;

        if(output > maxSpeed)
        {
            output = maxSpeed;
        }

        if(reverse)
        {
            output = -fabs(output);
        }

        if(radius <= trackWidth / 2)
        {
            rs = 0;
        }
        else
        {
            float offset = radius - (trackWidth / 2);
            innerR += offset;
            outerR += offset;
            
            float radiusRatio = outerR / innerR;
            rs = output / radiusRatio;
        }

        if(side == "right")
        {
            rpmDrive(output, rs, wt);
        }
        else if(side == "left")
        {
            rpmDrive(rs, output, wt);
        }

        heading = gt.heading();
        prevError = error;
        // wait(wt, msec);
    }
}