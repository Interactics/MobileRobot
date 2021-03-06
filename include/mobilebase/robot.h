/*******************************************************************************
* Date 2021.03.05
* Created by Interatics
*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for Mobile robot basic abstract class
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __ROBOT_H__
#define __ROBOT_H__

#include "../unit/unit.h"
using namespace UNIT;
namespace mobile {
////////////////////////////////////////////////////////////////////////////////
/// @brief The class for Mobile Robot systems. 
////////////////////////////////////////////////////////////////////////////////


class Robot{
public:
  Robot();
  virtual ~Robot();

  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that sets the number of mobile robot's wheel with actuator.
  /// @description The function that sets the number of mobile robot's wheel with actuator.
  /// @param The number of mobile robot's wheel with actuator.
  ////////////////////////////////////////////////////////////////////////////////
  virtual void setActNum(int actNum) = 0;

  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that sets the size of mobile robot's wheel with actuator.
  /// @description The function that sets the diameter size of mobile robot's wheel with actuator.
  /// @param The diameter of wheel with actuator.
  ////////////////////////////////////////////////////////////////////////////////
  virtual void setWheelDiameter(const float wheelDiameter) = 0;

  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that sets the width of mobile robot track size
  /// @description The function that sets the width of mobile robot track size
  /// which is a distance between front or back two wheel of mobile base.
  /// @param The size of track
  ////////////////////////////////////////////////////////////////////////////////
  virtual void setTrackDist(const float trackDist) = 0 ;

  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that sets the length of mobile robot wheelbase size
  /// @description The function that sets the length of mobile robot wheelbase size
  /// which is a distance between front and back wheel
  /// @param The size of wheelbase
  ////////////////////////////////////////////////////////////////////////////////
  virtual void setWheelBase(const float wheelBase) = 0;

  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that controls motors

  /// @description The function that controls the mobile robot.
  /// @param The vector of twist velocity of mobile robot
  ////////////////////////////////////////////////////////////////////////////////
  virtual bool MotorCtrl(Twist* cmdVelocity);

  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that Inverse kinematics for mobile robot.
  /// @description The function that calculates the mobile robot with inverse kinematics. 
  /// @param The vector of twist velocity of mobile robot
  /// @return Array of each motor's target velocity.
  ////////////////////////////////////////////////////////////////////////////////
  virtual float* InvKinematics(Twist* twistVel);
  
  ////////////////////////////////////////////////////////////////////////////////
  /// @brief The function that Forward kinematics for mobile robot.
  /// @description The function that calculates the mobile robot with forward kinematics. 
  /// @param  Array of current wheel velocity of mobile robot
  /// @return Twist of mobile robot.
  ////////////////////////////////////////////////////////////////////////////////
  virtual Twist* ForKinematics(float* wheelVelocity);

}; // class
} // namespace

#endif /* __ROBOT_H__ */