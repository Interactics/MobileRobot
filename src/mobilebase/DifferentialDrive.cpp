#include "../../include/mobilebase/DifferentialDrive.h"

namespace mobile {

// bool DiffDrive::MotorCtrl(float* cmdVelocity){
//     float* wheelVelocityCmd = InvKinematics(cmdVelocity);

//     // Assign the motor velocity command to motor;
//     // if command fail then return false

//     delete[] wheelVelocityCmd;
//     return true;
// }

float* DiffDrive::InvKinematics(Twist* twistVel){
    float* wheelVelocityCmd = new float[2];

    wheelVelocityCmd[LEFT]   = twistVel->linear[X] - ( twistVel->angular[YAW] * trackDist / 2.0f );
    wheelVelocityCmd[RIGHT]  = twistVel->linear[X] + ( twistVel->angular[YAW] * trackDist / 2.0f );

    return wheelVelocityCmd;
}

Twist* DiffDrive::ForKinematics(float* wheelVelocity) {
    Twist* twistVelocity = new Twist;

    twistVelocity->linear[X]    = (wheelVelocity[RIGHT] + wheelVelocity[LEFT]) / 2.0f;
    twistVelocity->angular[YAW] = (wheelVelocity[RIGHT] - wheelVelocity[LEFT]) / trackDist;
  
    return twistVelocity;
}
}
