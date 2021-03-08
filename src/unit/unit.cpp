#include "../../include/unit/unit.h"

namespace UNIT {

/////////////////////////////////////
/// Class Positon
/////////////////////////////////////

Position::Position()  : pos{0}, querternion{0} {}
Position::Position(const float x, const float y, const float z)
    : pos{x, y, z}, querternion{0} {}
Position::Position(const float x, const float y, const float z,
                   const float xx, const float yy, const float zz, const float ww)
    : pos{x, y, z}, querternion{xx, yy, zz, ww} {}
Position::Position(const Position &copy)
    : pos{copy.pos[X], copy.pos[Y], copy.pos[Z]},
      querternion{copy.querternion[X], copy.querternion[Y], copy.querternion[Z],
                  copy.querternion[W]} {}
Position::~Position() {}

inline Position Position::operator+(Position& pos){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] += pos.pos[idx];
        this->querternion[idx] += pos.querternion[idx];
    }
    return *this;
}
inline Position Position::operator-(Position& pos){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] -= pos.pos[idx];
        this->querternion[idx] -= pos.querternion[idx];
    }
    return *this;
}
inline Position Position::operator*(float& ref){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] *= ref;
        this->querternion[idx] *= ref;
    }
    return *this;
}
inline Position Position::operator/(float& ref){
    for(int idx = 0; idx < CONST_POSITION ; idx++){
        if (idx != CONST_POSITION - 1) this->pos[idx] /= ref;;
        this->querternion[idx] /= ref;
    }
    return *this;
}

inline Position operator*(float& ref, Position& pos)  {
    return pos * ref;
}
inline Position operator/(float& ref, Position& pos)  {
    return pos / ref;
}

/////////////////////////////////////
/// Class Twist
/////////////////////////////////////


Twist::Twist()  
    : linear{0}, angular{0} {}
Twist::Twist(const float x, const float y, const float z,
             const float roll, const float pitch, const float yaw)
    : linear{x, y, z}, angular{0} {}
Twist::Twist(const float x, const float y, const float z,
             const float roll, const float pitch, const float yaw)
    : linear{x, y, z}, angular{roll, pitch, yaw} {}
Twist::Twist(const Twist &copy)
    : linear{copy.linear[X], copy.linear[Y], copy.linear[Z]},
      angular{copy.angular[ROLL], copy.angular[PITCH], copy.angular[YAW]} {}
Twist::~Twist() {}


inline Twist Twist::operator+(Twist& twist){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  += twist.linear[idx];
        this->angular[idx] += twist.angular[idx];
    }
    return *this;
}
inline Twist Twist::operator-(Twist& twist){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  -= twist.linear[idx];
        this->angular[idx] -= twist.angular[idx];
    }
    return *this;
}
inline Twist Twist::operator*(float& ref){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  *= ref;
        this->angular[idx] *= ref;
    }
    return *this;
}
inline Twist Twist::operator/(float& ref){
    for(int idx = 0; idx < CONST_TWIST ; idx++){
        this->linear[idx]  /= ref;
        this->angular[idx] /= ref;
    }
    return *this;
}

inline Twist operator*(float& ref, Twist& pos)  {
    return pos * ref;
}
inline Twist operator/(float& ref, Twist& pos)  {
    return pos / ref;
}


} // namespace