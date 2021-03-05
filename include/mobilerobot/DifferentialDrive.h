/*******************************************************************************
 * DifferentialDrive.h
 * Date 2021.03.04
 * Created by Interatics
 *******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for Differential Drive Mobile Robot
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __DIFF_DRIVE_H__
#define __DIFF_DRIVE_H__

#include "robot.h"

namespace mobile {

class DiffDrive : public MobileRobot {
private:
    enum { LEFT = 0, RIGHT } ;
    enum { Vx = 0, Wtheta };

    int   actNum;
    float wheelDiameter;
    float trackDist;
    float wheelBase;

public:
    DiffDrive(const float wheelDiameter, const float trackDist)
    :wheelDiameter(wheelDiameter), trackDist(trackDist), wheelBase(0) {
        actNum = 2;
    };
    ~DiffDrive(){}

    void setActNum(const int actNum)                 { this -> actNum = actNum; }
    void setWheelDiameter(const float wheelDiameter) { this -> wheelDiameter = wheelDiameter; } 
    void setTrackDist(const float trackDist)         { this -> trackDist = trackDist; } 

    bool MotorCtrl(float* velocity);
    float* InvKinematics(float* twistVel);
    float* ForKinematics(float* wheelVelocity);

}; // class
}
#endif // __DIFF_DRIVE_H__
