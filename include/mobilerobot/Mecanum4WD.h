/*******************************************************************************
 * Mecanum4WD.h
 * Date 2021.03.05
 * Created by Interatics
 *******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for 4WD Mecanum Mobile base
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __MECANUM4WD_H__
#define __MECANUM4WD_H__

#include <memory>
#include "robot.h"

namespace mobile {

class Meca4WD : public MobileRobot {

private:
    enum { FR_LEFT = 0, FR_RIGHT, BA_LEFT, BA_RIGHT };
    enum { Vx = 0, Vy, Wtheta };

    int   actNum;
    float wheelDiameter;
    float trackDist;
    float wheelBase;

public:
    Meca4WD(const float wheelDiameter, const float trackDist)
    :actNum(actNum), wheelDiameter(wheelDiameter), trackDist(trackDist), wheelBase(0) {
        actNum = 4;
    };
    ~Meca4WD(){}

    void setActNum(const int actNum)                 { this -> actNum = actNum; }
    void setWheelDiameter(const float wheelDiameter) { this -> wheelDiameter = wheelDiameter; } 
    void setTrackDist(const float trackDist)         { this -> trackDist = trackDist; } 

    bool MotorCtrl(float* velocity);
    float* InvKinematics(float* twistVel);
    float* ForKinematics(float* wheelVelocity);

};

} // namespace 


#endif // __MECANUMMOBILE_H__
