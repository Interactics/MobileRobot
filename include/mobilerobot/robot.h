/*******************************************************************************
* Date 2021.03.02
* Created by Interatics
*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @file The file for Mobile robot basic system
/// @author Hoyeon Yu (Interactics)
////////////////////////////////////////////////////////////////////////////////

#ifndef __ROBOT_H_
#define __ROBOT_H_

namespace mobile {

////////////////////////////////////////////////////////////////////////////////
/// @brief The class for Mobile Robot systems
////////////////////////////////////////////////////////////////////////////////

  class MobileRobot {

    MobileRobot();
    virtual ~MobileRobot();

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief The function that sets the number of mobile robot's wheel with actuator.
    /// @description The function that sets the number of mobile robot's wheel with actuator.
    /// @param The number of mobile robot's wheel with actuator.
    ////////////////////////////////////////////////////////////////////////////////
    virtual void setActuatorNum(int num);

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief The function that sets the size of mobile robot's wheel with actuator.
    /// @description The function that sets the diameter size of mobile robot's wheel with actuator.
    /// @param The diameter of wheel with actuator.
    ////////////////////////////////////////////////////////////////////////////////
    virtual void setWheelSize(int diameter);

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief The function that sets the width of mobile robot track size
    /// @description The function that sets the width of mobile robot track size 
    /// which is a distance between front or back two wheel of mobile base.
    /// @param The size of track
    ////////////////////////////////////////////////////////////////////////////////    
    virtual void setTrack(int dist);

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief The function that sets the length of mobile robot wheelbase size
    /// @description The function that sets the length of mobile robot wheelbase size 
    /// which is a distance between front and back wheel 
    /// @param The size of wheelbase
    ////////////////////////////////////////////////////////////////////////////////
    virtual void setWheelBase(int dist);

  }; // class 
} // namespace

#endif /* __ROBOT_H_ */