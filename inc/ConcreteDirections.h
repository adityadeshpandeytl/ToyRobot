#ifndef __CONCRETE_DIRECTIONS_H__
#define __CONCRETE_DIRECTIONS_H__

#include "IDirection.h"
#include "Sys.h"
#include <string>
#include <memory>

// Single reponsibility direction classes with
// all the three system required properties in each
// one of them. TurningLeft, Right, and Moving Forward.
class NorthFacing
{
	public:
		std::unique_ptr<IDirection> HandleTurnLeft();
		std::unique_ptr<IDirection> HandleTurnRight();
		std::pair<SYSINT, SYSINT> HandleMovement(SYSINT inX, SYSINT inY);
        const std::string& DirectionName() { return mDirection; }
    private:
        const std::string mDirection = "NORTH";
};

class SouthFacing
{
    public:
        std::unique_ptr<IDirection> HandleTurnLeft();
        std::unique_ptr<IDirection> HandleTurnRight();
        std::pair<SYSINT, SYSINT> HandleMovement(SYSINT inX, SYSINT inY);
        const std::string& DirectionName() { return mDirection; }
    private:
        const std::string mDirection = "SOUTH";
};

class EastFacing
{
    public:
        std::unique_ptr<IDirection> HandleTurnLeft();
        std::unique_ptr<IDirection> HandleTurnRight();
        std::pair<SYSINT, SYSINT> HandleMovement(SYSINT inX, SYSINT inY);
        const std::string& DirectionName() { return mDirection; }
    private:
        const std::string mDirection = "EAST";
};

class WestFacing
{
    public:
        std::unique_ptr<IDirection> HandleTurnLeft();
        std::unique_ptr<IDirection> HandleTurnRight();
        std::pair<SYSINT, SYSINT> HandleMovement(SYSINT inX, SYSINT inY);
		const std::string& DirectionName() { return mDirection; }
	private:
		const std::string mDirection = "WEST";
};

#endif
