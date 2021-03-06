#include "../../include/unit/unit.h"

namespace UNIT {
/////////////////////////////////////
/// Class Positon
/////////////////////////////////////

Position::Position()  : pos{0}, quaternion{0} {}
Position::Position(const float x, const float y, const float z)
: pos{x, y, z}, euler{0} {
    ToQuaternion_();
}
Position::Position(const float x, const float y, const float z,
                   const float roll, const float pitch, const float yaw)
: pos{x, y, z}, euler{roll, pitch, yaw} {
    ToQuaternion_();
}
Position::Position(const float x, const float y, const float z,
                   const float xx, const float yy, const float zz, const float ww)
: pos{x, y, z}, quaternion{xx, yy, zz, ww} {
    ToEuler_();
}
Position::Position(const Position &copy)
: pos{copy.pos[X], copy.pos[Y], copy.pos[Z]},
euler{copy.euler[X], copy.euler[Y], copy.euler[Z]},
quaternion{copy.quaternion[X], copy.quaternion[Y], copy.quaternion[Z],
    copy.quaternion[W]} {
        ToEuler_();
    }
Position::~Position() {}

Position Position::operator+(const Position& pos){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] += pos.pos[idx];
        this->quaternion[idx] += pos.quaternion[idx];
    }
    ToEuler_();
    return *this;
}
Position Position::operator-(const Position& pos){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] -= pos.pos[idx];
        this->quaternion[idx] -= pos.quaternion[idx];
    }
    ToEuler_();
    return *this;
}
Position Position::operator*(const float& ref){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] *= ref;
        this->quaternion[idx] *= ref;
    }
    ToEuler_();
    return *this;
}
Position Position::operator/(const float& ref){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] /= ref;;
        this->quaternion[idx] /= ref;
    }
    ToEuler_();
    return *this;
}

Position operator*(const float& ref, Position& pos)  {
    Position result = pos * ref;
    return result;
}
Position operator/(const float& ref, Position& pos)  {
    Position result = pos / ref;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Position& pos){
    //
    os << "[" <<
    pos.pos[X] << ", " << pos.pos[Y] <<  ", " << pos.pos[Z] <<  ", " <<
    pos.euler[ROLL] <<  ", " << pos.euler[PITCH] <<  ", " << pos.euler[YAW] << "]";
    return os;
}

void Position::ToQuaternion_(){
    double cy = cos(euler[YAW] * 0.5);
    double sy = sin(euler[YAW] * 0.5);
    double cp = cos(euler[PITCH] * 0.5);
    double sp = sin(euler[PITCH] * 0.5);
    double cr = cos(euler[ROLL] * 0.5);
    double sr = sin(euler[ROLL] * 0.5);
    
    quaternion[W] = cr * cp * cy + sr * sp * sy;
    quaternion[X] = sr * cp * cy - cr * sp * sy;
    quaternion[Y] = cr * sp * cy + sr * cp * sy;
    quaternion[Z] = cr * cp * sy - sr * sp * cy;
}

void Position::ToEuler_() {
    // roll (x-axis rotation)
    double sinr_cosp = 2 * (quaternion[W] * quaternion[X] + quaternion[Y] * quaternion[Z]);
    double cosr_cosp = 1 - 2 * (quaternion[X] * quaternion[X] + quaternion[Y] * quaternion[Y]);
    euler[ROLL] = std::atan2(sinr_cosp, cosr_cosp);
    
    // pitch (y-axis rotation)
    double sinp = 2 * (quaternion[W] * quaternion[Y] - quaternion[Z] * quaternion[X]);
    if (std::abs(sinp) >= 1) euler[PITCH] = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else euler[PITCH] = std::asin(sinp);
    
    // yaw (z-axis rotation)
    double siny_cosp = 2 * (quaternion[W] * quaternion[Z] + quaternion[X] * quaternion[Y]);
    double cosy_cosp = 1 - 2 * (quaternion[Y] * quaternion[Y] + quaternion[Z] * quaternion[Z]);
    euler[YAW] = std::atan2(siny_cosp, cosy_cosp);
}

/////////////////////////////////////
/// Class Twist
/////////////////////////////////////


Twist::Twist()
: linear{0}, angular{0} {}
Twist::Twist(const float x, const float y, const float z)
: linear{x, y, z}, angular{0} {}
Twist::Twist(const float x, const float y, const float z,
             const float roll, const float pitch, const float yaw)
: linear{x, y, z}, angular{roll, pitch, yaw} {}
Twist::Twist(const Twist &copy)
: linear{copy.linear[X], copy.linear[Y], copy.linear[Z]},
angular{copy.angular[ROLL], copy.angular[PITCH], copy.angular[YAW]} {}
Twist::~Twist() {}


Twist Twist::operator+(const Twist& twist){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  += twist.linear[idx];
        this->angular[idx] += twist.angular[idx];
    }
    return *this;
}
Twist Twist::operator-(const Twist& twist){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  -= twist.linear[idx];
        this->angular[idx] -= twist.angular[idx];
    }
    return *this;
}
Twist Twist::operator*(const float& ref){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  *= ref;
        this->angular[idx] *= ref;
    }
    return *this;
}
Twist Twist::operator/(const float& ref){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  /= ref;
        this->angular[idx] /= ref;
    }
    return *this;
}
Twist operator*(const float& ref, Twist& twist)  {
    return twist * ref;
}
Twist operator/(const float& ref, Twist& twist)  {
    return twist / ref;
}
std::ostream& operator<<(std::ostream& os, const Twist& twist){
    //
    os << "[" <<
    twist.linear[X] << ", " << twist.linear[Y] <<  ", " << twist.linear[Z] <<  ", " <<
    twist.angular[X] <<  ", " << twist.angular[Y] <<  ", " << twist.angular[Z] << "]";
    return os;
}
} // namespace
