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

#include "MobileBase.h"

namespace mobile {

class DiffDrive : public MobileBase {
private:
    enum { LEFT = 0, RIGHT } ;
    enum { Vx = 0, Wtheta };
    enum { xPos, yPos };

    int   actNum;
    float wheelDiameter;
    float trackDist;
    float wheelBase;
    float pos[2];

public:
    DiffDrive(const float wheelDiameter, const float trackDist)
    :wheelDiameter(wheelDiameter), trackDist(trackDist), wheelBase(0) {
        pos[xPos] = 0, pos[yPos] = 0;

        actNum = 2;
    };
    ~DiffDrive(){}

    void setActNum(const int actNum)                 { this -> actNum = actNum; }
    void setWheelDiameter(const float wheelDiameter) { this -> wheelDiameter = wheelDiameter; } 
    void setTrackDist(const float trackDist)         { this -> trackDist = trackDist; } 

    bool MotorCtrl(float* cmdVelocity);
    float* InvKinematics(Twist* twistVel);
    Twist* ForKinematics(float* wheelVelocity);
    float* calOdometry(Twist* twistVel);

}; // class
}
#endif // __DIFF_DRIVE_H__
