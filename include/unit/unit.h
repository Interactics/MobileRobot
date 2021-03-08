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


namespace UNIT {
    const int CONST_POSITION    = 4;
    const int CONST_TWIST       = 3;

    enum { X = 0, Y, Z, W };
    enum { ROLL = 0, PITCH, YAW };


class Position{
public:
        float pos[3];            // x, y, z
        float querternion[4];    // x, y, z, w
public:
    Position();
    Position(const float x, const float y, const float z);
    Position(const float x, const float y, const float z, 
             const float xx, const float yy, const float zz, const float ww);
    Position(const Position& copy);
    ~Position() {}

    Position operator+(Position&);
    Position operator-(Position&);
    Position operator*(float&);
    Position operator/(float&);

    friend Position operator*(float&, Position&);
    friend Position operator/(float&, Position&);
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

    Twist operator+(Twist&);
    Twist operator-(Twist&);
    Twist operator*(float&);
    Twist operator/(float&);

    friend Twist operator*(float&, Twist&);
    friend Twist operator/(float&, Twist&);
};
} // namespace UNIT



#endif // __UNIT_H__
