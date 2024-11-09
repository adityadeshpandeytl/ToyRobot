#include "Robot.h"
#include "DirectionFactory.h"

Robot::Robot(SYSINT inX, SYSINT inY, std::unique_ptr<Canvas>& inpCanvas, const std::string& inDirection) :
	mX(inX), mY(inY), mpCanvas(inpCanvas)
{  
	// If the input direction is not valid exception will be thrown 
	// from here and will be handled in the templatised Command Class
	// Execute method, but the robot will not be placed at all.
	mpDirection = std::move(DirectionFactory().GetDirection(inDirection));
}

bool Robot::TurnLeft()
{
	try {
		// Whatever direction the robot is facing currently,
		// turning left will make it face some other direction.
		// the new direction instance will be returned by 
		// the existing direction handle left turn function.
		std::unique_ptr<IDirection> pNewDirection = std::move(mpDirection->Left());
		mpDirection = std::move(pNewDirection);
	}
	catch (const std::exception& e) {
		throw e;
	}

	return true;

}

bool Robot::TurnRight()
{
	try {
		// Behaviour similar to TurnLeft above except it is
		// turn right here.
		std::unique_ptr<IDirection> pNewDirection = std::move(mpDirection->Right());
		mpDirection = std::move(pNewDirection);
	}
	catch (const std::exception& e) {
	   throw e;
	}
	
	return true;
}

bool Robot::Move()
{
	// Direction Move function will return 
	// coordinates for new position the robot will
	// result in if the move is made. The pair returned
	// will have X in the first element and Y in the second.
	auto coordinates = std::move(mpDirection->Move(mX, mY));

	// The coordinates of the new resulting position are validated
	// against the area of the canvas. If the coordinates lie outside
	// the scope or area of the canvas then do not update the 
	// coordinates of the Robot as that will mean that robot is going
	// to fall of the table, hence return false.
	if(!mpCanvas->ValidatePosition(coordinates.first, coordinates.second))
		return false;

	// If the new coordinates
	// are valid, update the coordinates
	// of the robot.
	mX = coordinates.first;
	mY = coordinates.second;

	return true;
}

void Robot::Print(std::ostream& outputStream)
{
	// Print the paramenters of the 
	// robot to output stream.
	outputStream<<mX<<","<<mY<<",";
	outputStream<<mpDirection->GetDirection();
	outputStream<<"\n";
}
