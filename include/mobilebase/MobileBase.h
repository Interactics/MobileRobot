/*******************************************************************************
 * Mecanum4WD.h
 * Date 2021.03.06
 * Created by Interatics
 *******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for Basic mobile base setup.
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __MOBILE_H__
#define __MOBILE_H__

#include "robot.h"

namespace mobile {

class MobileBase : public Robot {
protected:
    enum { xPos, yPos };

    // Specification of Mobile Robot
    int   actNum;
    float wheelDiameter;
    float trackDist;
    float wheelBase;

    // State of Mobile Robot 
    Position pos;
    Position pos_prev;

    float theta;

    Twist velocity;

public:
    MobileBase(){
        pos.pos[X] = 0, pos.pos[Y] = 0;
        pos_prev.pos[X] = 0, pos_prev.pos[Y] = 0;
    };
    ~MobileBase();

    void setActNum(const int actNum)                 { this -> actNum = actNum; }
    void setWheelDiameter(const float wheelDiameter) { this -> wheelDiameter = wheelDiameter; } 
    void setTrackDist(const float trackDist)         { this -> trackDist = trackDist; }

    virtual bool MotorCtrl(float* cmdVelocity);

    virtual float *CalOdometry(float *twistVel);
};
}
#endif //__MOBILE_H_H_
