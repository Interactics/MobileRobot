/*******************************************************************************
* Date 2021.03.07
* Created by Interatics
*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for Physics Unit System SI.
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __UNIT_H__
#define __UNIT_H__
#include <io>

namespace UNIT {
    enum { X = 0, Y, Z, W };

class Position{
public:
        float pos[3];            // x, y, z
        float querternion[4];    // x, y, z, w
public:
    Position() : pos{0}, querternion{0} {}
    Position(const float x, const float y, const float z) : pos{x, y, z}, querternion{0} {}
    Position(const float x, const float y, const float z, 
             const float xx, const float yy, const float zz, const float ww) : pos{x, y, z}, querternion{xx, yy, zz, ww} {}
    Position(const Position& copy) 
    : pos{copy.pos[X], copy.pos[Y], copy.pos[Z]}, 
      querternion{copy.querternion[X], copy.querternion[Y], copy.querternion[Z], copy.querternion[W]} { }
    ~Position() {}

    Position operator+(const Position&);
    Position operator-(const Position&);
    Position operator*(const Position&);
    Position operator/(const Position&);

    friend Position operator*(const int&, const Position&);
    friend Position operator/(const int&, const Position&);
};

class Twist{
public:
    float linear[3];         // x, y, z
    float angular[3];        // x, y, z
public:
    Twist() : linear{0}, angular{0} {}
    Twist(float, float, float, 
          float, float, float) : linear{0}, angular{0} {}
    Twist(const Twist& copy);

    Twist operator+(const Twist&);
    Twist operator-(const Twist&);
    Twist operator*(const Twist&);
    Twist operator/(const Twist&);

    friend Twist operator*(const int&, const Twist&);
    friend Twist operator/(const int&, const Twist&);
};
} // namespace UNIT



#endif // __UNIT_H__
