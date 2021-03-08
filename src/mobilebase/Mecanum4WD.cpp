#include "../../include/mobilebase/Mecanum4WD.h"

namespace mobile {

// bool Meca4WD::MotorCtrl(Twist* cmdVelocity){
//     float* wheelVelocityCmd = InvKinematics(cmdVelocity);

//     // Assign the motor velocity command to motor;
//     // if command fail then return false

//     delete[] wheelVelocityCmd;
//     return true;
// }

float* Meca4WD::CalOdometry(Twist* twistVelocity){

    // float* velocity = ForKinematics(twistVelocity);
    // pos[xPos] += velocity[X];
    // read Motor Speed
}

float* Meca4WD::InvKinematics(Twist* twistVel){
    float* wheelVelocityCmd = new float[4];

    wheelVelocityCmd[FR_LEFT]   = twistVel->linear[X] - twistVel->linear[Y] - (trackDist + wheelBase) * twistVel->angular[Z];
    wheelVelocityCmd[FR_RIGHT]  = twistVel->linear[X] + twistVel->linear[Y] - (trackDist + wheelBase) * twistVel->angular[Z];
    wheelVelocityCmd[BA_LEFT]   = twistVel->linear[X] - twistVel->linear[Y] + (trackDist + wheelBase) * twistVel->angular[Z];
    wheelVelocityCmd[BA_RIGHT]  = twistVel->linear[X] + twistVel->linear[Y] + (trackDist + wheelBase) * twistVel->angular[Z];

    return wheelVelocityCmd;
}

Twist* Meca4WD::ForKinematics(float* wheelVelocity){
    Twist* twistVelocity = new Twist;

    twistVelocity->linear [X] = ( wheelVelocity[FR_LEFT] + wheelVelocity[FR_RIGHT] + wheelVelocity[BA_LEFT] + wheelVelocity[BA_RIGHT]) / 4;
    twistVelocity->linear [Y] = (-wheelVelocity[FR_LEFT] + wheelVelocity[FR_RIGHT] - wheelVelocity[BA_LEFT] + wheelVelocity[BA_RIGHT]) / 4;
    twistVelocity->angular[Z] = (-wheelVelocity[FR_LEFT] - wheelVelocity[FR_RIGHT] + wheelVelocity[BA_LEFT] + wheelVelocity[BA_RIGHT]) 
                                / float(4 * (trackDist + wheelBase));

    return twistVelocity;
}

} //namespace 