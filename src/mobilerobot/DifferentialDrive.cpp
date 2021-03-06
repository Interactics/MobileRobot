#include "../../include/mobilerobot/DifferentialDrive.h"

namespace mobile {

bool DiffDrive::MotorCtrl(float* cmdVelocity){
    float* wheelVelocityCmd = InvKinematics(cmdVelocity);

    // Assign the motor velocity command to motor;
    // if command fail then return false

    delete[] wheelVelocityCmd;
    return true;
}

float* DiffDrive::InvKinematics(float* twistVel){
    float* wheelVelocityCmd = new float[2];

    wheelVelocityCmd[LEFT]   = twistVel[Vx] - ( twistVel[Wtheta] * trackDist / 2.0f );
    wheelVelocityCmd[RIGHT]  = twistVel[Vx] + ( twistVel[Wtheta] * trackDist / 2.0f );

    return wheelVelocityCmd;
}

float* DiffDrive::ForKinematics(float* wheelVelocity) {
    float* twistVelocity = new float[2];

    twistVelocity[Vx]     = (wheelVelocity[RIGHT] + wheelVelocity[LEFT]) / 2.0f;
    twistVelocity[Wtheta] = (wheelVelocity[RIGHT] - wheelVelocity[LEFT]) / trackDist;
  
    return twistVelocity;
}
}
