#include "../../include/mobilerobot/DifferentialDrive.h"

namespace mobile {

bool DiffDrive::MotorCtrl(float* velocity){
    float* wheelVelocityCmd = InvKinematics(velocity);

    // Assign the motor velocity command to motor;
    // if command fail then return false
    delete[] wheelVelocityCmd;
    return true;
}

float* DiffDrive::InvKinematics(float* twistVel){
    float* wheelVelocityCmd = new float[2];

    wheelVelocityCmd[LEFT]   = twistVel[Vx] - (twistVel[Wtheta] * trackDist / 2);
    wheelVelocityCmd[RIGHT]  = twistVel[Vx] + (twistVel[Wtheta] * trackDist / 2);

    return wheelVelocityCmd;
}
}
