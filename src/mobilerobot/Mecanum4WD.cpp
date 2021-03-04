#include "../../include/mobilerobot/Mecanum4WD.h"

namespace mobile {

bool Meca4WD::MotorCtrl(float* velocity){
    float wheelVelocityCmd[4];

    float linVel[] = {velocity[Vx] , velocity[Vy]};
    float angVel   = velocity[Wtheta];

    wheelVelocityCmd[FR_LEFT]   = velocity[Vx] - velocity[Vy] - (trackDist + wheelBase) * velocity[Wtheta];
    wheelVelocityCmd[FR_RIGHT]  = velocity[Vx] + velocity[Vy] - (trackDist + wheelBase) * velocity[Wtheta];
    wheelVelocityCmd[BA_LEFT]   = velocity[Vx] - velocity[Vy] + (trackDist + wheelBase) * velocity[Wtheta];
    wheelVelocityCmd[BA_RIGHT]  = velocity[Vx] + velocity[Vy] + (trackDist + wheelBase) * velocity[Wtheta];

    // Assign the motor velocity command to motor;
    // if command fail then return false

    return true;
}

// meca_vel InvKinematics(const twist_vel tv) {
//   meca_vel mv;

//   mv.vel1 = tv.vx - tv.vy - (ROBOT_L + ROBOT_D) * tv.vtheta;
//   mv.vel2 = tv.vx + tv.vy - (ROBOT_L + ROBOT_D) * tv.vtheta;
//   mv.vel3 = tv.vx - tv.vy + (ROBOT_L + ROBOT_D) * tv.vtheta;
//   mv.vel4 = tv.vx + tv.vy + (ROBOT_L + ROBOT_D) * tv.vtheta;

//   return mv;
// }
