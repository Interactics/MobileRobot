/*******************************************************************************
* Date 2021.03.02
* Created by Interatics
*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for Differential Drive Mobile Robot
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __DIFF_DRIVE_H__
#define __DIFF_DRIVE_H__

#include "robot.h"
namespace mobile{
class DiffDrive : public MobileRobot{
private:
    int ActuatorNum;
    int WheelSize;
    int TrackSize;
    int WheelBase;
public:
    DiffDrive(int ActNum, int WheelDiameter, int Trackdist);
    
}; // class
}
#endif // __DIFF_DRIVE_H__
