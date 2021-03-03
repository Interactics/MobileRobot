#include "../../include/mobilerobot/DifferentialDrive.h"
namespace mobile {

bool DiffDrive::MotorCtrl(float* velocity){
    float wheelVelocityCmd[2];

    float linVel = velocity[LEFT];
    float angVel = velocity[RIGHT];

    wheelVelocityCmd[LEFT]   = linVel - (angVel * trackDist / 2);
    wheelVelocityCmd[RIGHT]  = linVel + (angVel * trackDist / 2);

    // Assign the motor velocity command to motor;
    // Assign the motor velocity command to motor;
    // if command fail then return false

    return true;
}
}
