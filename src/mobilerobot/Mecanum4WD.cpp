#include "../../include/mobilerobot/Mecanum4WD.h"

namespace mobile {

bool Meca4WD::MotorCtrl(float* cmdVelocity){
    float* wheelVelocityCmd = InvKinematics(cmdVelocity);

    // Assign the motor velocity command to motor;
    // if command fail then return false

    delete[] wheelVelocityCmd;
    return true;
}

float* Meca4WD::calOdometry(float* twistVelocity){

    float* velocity = ForKinematics(twistVelocity);
    pos[xPos] += velocity[Vx];
    // read Motor Speed

}

float* Meca4WD::InvKinematics(float* twistVel){
    float* wheelVelocityCmd = new float[4];

    wheelVelocityCmd[FR_LEFT]   = twistVel[Vx] - twistVel[Vy] - (trackDist + wheelBase) * twistVel[Wtheta];
    wheelVelocityCmd[FR_RIGHT]  = twistVel[Vx] + twistVel[Vy] - (trackDist + wheelBase) * twistVel[Wtheta];
    wheelVelocityCmd[BA_LEFT]   = twistVel[Vx] - twistVel[Vy] + (trackDist + wheelBase) * twistVel[Wtheta];
    wheelVelocityCmd[BA_RIGHT]  = twistVel[Vx] + twistVel[Vy] + (trackDist + wheelBase) * twistVel[Wtheta];

    return wheelVelocityCmd;
}

float* Meca4WD::ForKinematics(float* wheelVelocity){
    float* twistVelocity = new float[3];

    twistVelocity[Vx]     = ( wheelVelocity[FR_LEFT] + wheelVelocity[FR_RIGHT] 
                            + wheelVelocity[BA_LEFT] + wheelVelocity[BA_RIGHT]) / 4;
    twistVelocity[Vy]     = (-wheelVelocity[FR_LEFT] + wheelVelocity[FR_RIGHT] 
                            - wheelVelocity[BA_LEFT] + wheelVelocity[BA_RIGHT]) / 4;
    twistVelocity[Wtheta] = (-wheelVelocity[FR_LEFT] - wheelVelocity[FR_RIGHT] 
                            + wheelVelocity[BA_LEFT] + wheelVelocity[BA_RIGHT]) / float(4 * (trackDist + wheelBase));

    return twistVelocity;
}

} //namespace 