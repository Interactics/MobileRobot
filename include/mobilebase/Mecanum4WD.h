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

#include "MobileBase.h"

namespace mobile {

class Meca4WD : public MobileBase {
private:
    enum { FR_LEFT = 0, FR_RIGHT, BA_LEFT, BA_RIGHT };

public:
    Meca4WD(const float wheelDiameter, const float trackDist)
    : MobileBase() {
        setActNum(4);
        setWheelDiameter(wheelDiameter);
        setTrackDist(trackDist);
    };
    ~Meca4WD(){}

    bool MotorCtrl(float* cmdVelocity);
    float* InvKinematics(Twist* twistVel);
    Twist* ForKinematics(float* wheelVelocity);

    float *CalOdometry(Twist *twistVel);

};

} // namespace 


#endif // __MECANUMMOBILE_H__
