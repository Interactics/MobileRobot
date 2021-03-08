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

#include <cmath>

namespace UNIT {
    const int CONST_POSITION    = 4;
    const int CONST_TWIST       = 3;

    enum { X = 0, Y, Z, W };
    enum { ROLL = 0, PITCH, YAW };


class Position{
public:
        float pos[3];            // x, y, z
        float quaternion[4];     // x, y, z, w
        float euler[3];          // x, y, z

public:
    Position();
    Position(const float, const float, const float); // Only Position.
    Position(const float, const float, const float,  
             const float, const float, const float); // Position with euler angle.
    Position(const float, const float, const float, 
             const float, const float, const float, const float); // Position with quaternion.
    Position(const Position& copy);
    ~Position() {}

    Position operator+(Position&);
    Position operator-(Position&);
    Position operator*(float&);
    Position operator/(float&);

    friend Position operator*(float&, Position&);
    friend Position operator/(float&, Position&);

private:
    void ToQuaternion_();
    void ToEuler_();
};

class Twist{
public:
    float linear[3];         // x, y, z
    float angular[3];        // x, y, z
public:
    Twist();
    Twist(float, float, float, float, float, float);
    Twist(const Twist& copy);
    ~Twist();

    Twist operator+(Twist&);
    Twist operator-(Twist&);
    Twist operator*(float&);
    Twist operator/(float&);

    friend Twist operator*(float&, Twist&);
    friend Twist operator/(float&, Twist&);
};
} // namespace UNIT



#endif // __UNIT_H__
