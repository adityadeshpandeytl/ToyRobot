#include "ConcreteDirections.h"
#include "Direction.h"
#include <memory>

// State design patter implemented here.
// If the object is facing North, when 
// turned left it will face West, so 
// a new instance of direction West is returned
// and the Robot will now hold direction instance
// which will be of Facing West.
std::unique_ptr<IDirection> NorthFacing::HandleTurnLeft()
{
	return std::make_unique<Direction<WestFacing> >();
}

std::unique_ptr<IDirection> NorthFacing::HandleTurnRight()
{
	return std::make_unique<Direction<EastFacing> >();
}

std::pair<SYSINT, SYSINT> NorthFacing::HandleMovement(SYSINT inX, SYSINT inY)
{
	// North facing movement will result in incrementing Y
	// coordinate.
	return std::pair<SYSINT, SYSINT>(inX, ++inY);
}

std::unique_ptr<IDirection> WestFacing::HandleTurnLeft()
{
    return std::make_unique<Direction<SouthFacing> >();
}

std::unique_ptr<IDirection> WestFacing::HandleTurnRight()
{
    return std::make_unique<Direction<NorthFacing> >();
}

std::pair<SYSINT, SYSINT> WestFacing::HandleMovement(SYSINT inX, SYSINT inY)
{
	// West facing movement will result in decrementing
	// X coordinate.
    return std::pair<SYSINT, SYSINT>(--inX, inY);
}

std::unique_ptr<IDirection> EastFacing::HandleTurnLeft()
{
    return std::make_unique<Direction<NorthFacing> >();
}

std::unique_ptr<IDirection> EastFacing::HandleTurnRight()
{
    return std::make_unique<Direction<SouthFacing> >();
}

std::pair<SYSINT, SYSINT> EastFacing::HandleMovement(SYSINT inX, SYSINT inY)
{
	// East facing movement will result in incrementing 
	// X coordinate.
    return std::pair<SYSINT, SYSINT>(++inX, inY);
}

std::unique_ptr<IDirection> SouthFacing::HandleTurnLeft()
{
    return std::make_unique<Direction<EastFacing> >();
}

std::unique_ptr<IDirection> SouthFacing::HandleTurnRight()
{
    return std::make_unique<Direction<WestFacing> >();
}

std::pair<SYSINT, SYSINT> SouthFacing::HandleMovement(SYSINT inX, SYSINT inY)
{
	// The south facing move will decrement 
	// Y coordinate.
    return std::pair<SYSINT, SYSINT>(inX, --inY);
}

