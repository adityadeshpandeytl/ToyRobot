#include "DirectionFactory.h"

std::unique_ptr<IDirection> DirectionFactory::GetDirection(const std::string& inDirection)
{
	// The reason to throw an exception here if the Direciton
	// is not valid, is because if the input direction is not
	// valid from the PLACE command Arguments then the Robot
	// instance should not get created at all. Returning 
	// nullptr from here may will result in creating and Placing
	// Robot on the Table/Canvas whose direction is unknown.
	if(mDirectionFactory.find(inDirection) == mDirectionFactory.end())
		throw std::invalid_argument("Input Direciton not valid");

	return mDirectionFactory[inDirection]();
}
