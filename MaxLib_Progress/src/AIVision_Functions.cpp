#include "main.h"

void orient(string color)
{
    float error = 0.0;
    int camCenterX = 160;
    float distToBlock = 0.0;
    float angleToBlock = 0.0;
    int distFromCenter = 0;
    float blockWidth = 16;      // width in inches
    float calibrationDist = 12; // 12 inches calibration
    int calibrationWidth = 680; // Assumed pixel width at calibration distance
    float relativeSize = (calibrationWidth * calibrationDist) / blockWidth;
    camera.modelDetection(true);

    // sets the color sorted and snapshot target
    aivision::colordesc *targetSignature;

    if(color == "red")
    {
        targetSignature = &Red;
    }
    else if(color == "blue")
    {
        targetSignature = &Blue;
    }
    else if(color == "neutral")
    {
        targetSignature = &Neutral;
    }

    camera.takeSnapshot(*targetSignature);
    // camera.takeSnapshot(aivision::ALL_AIOBJS);

    if (camera.objectCount > 0)
    {
        camera.takeSnapshot(*targetSignature);
        // frontIntake.spin(fwd, 100, pct);
        distToBlock = ((blockWidth * relativeSize) / camera.largestObject.width);
        distFromCenter = (camera.largestObject.centerX - camCenterX) / (camera.largestObject.width / blockWidth);
        angleToBlock = atan(distFromCenter / distToBlock) * (180 / 3.14);

        gyroTurn(angleToBlock - gt.heading());
        camera.takeSnapshot(*targetSignature);
        distToBlock = ((blockWidth * relativeSize) / camera.largestObject.width);
        inchDrive(distToBlock, false);
    }
    else
    {
        orient(color);
    }
}