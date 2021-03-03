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

#define LEFT   0
#define RIGHT  1

namespace mobile{

class DiffDrive : public MobileRobot {
private:
    int   actNum;
    float wheelDiameter;
    float trackDist;
    float wheelBase;
public:
    DiffDrive(const int actNum, const float wheelDiameter, const float trackDist)
    :actNum(actNum), wheelDiameter(wheelDiameter), trackDist(trackDist), wheelBase(0) {};
    ~DiffDrive(){}

    void setActNum(const int actNum)                 { this -> actNum = actNum; }
    void setWheelDiameter(const float wheelDiameter) { this -> wheelDiameter = wheelDiameter; } 
    void setTrackDist(const float trackDist)         { this -> trackDist = trackDist; } 

    bool MotorCtrl(float* velocity);
}; // class
}
#endif // __DIFF_DRIVE_H__
