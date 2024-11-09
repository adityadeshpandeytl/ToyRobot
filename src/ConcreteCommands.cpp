#include "ConcreteCommands.h"
#include "CommandArgs.h"

bool PlaceCommand::Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs)
{
	// Dynamic casting is required to retrieve parameters 
	// in PlaceCommandArgs.
	PlaceCommandArgs* ptr = dynamic_cast<PlaceCommandArgs*>(inPCommandArgs.get());

	// Create objec (Robot) instance with X and Y coordinates along with
	// direction.
	ptr->Table().CreateObject(ptr->X(), ptr->Y(), ptr->Direction());

	return true;
}

bool LeftCommand::Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs)
{
	if(inPObject == nullptr)
		return false;

	// Robot turn left
	return inPObject->TurnLeft();
}

bool RightCommand::Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs)
{
	if(inPObject == nullptr) 
        return false;

	// Robot turn right.
    return inPObject->TurnRight();
}

bool MoveCommand::Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs)
{
    if(inPObject == nullptr)
        return false;

	//Robot move.
    return inPObject->Move();
}

bool ReportCommand::Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs)
{
    if(inPObject == nullptr)
        return false;

	// Dynamic casting is required to retrieve ostream from ReportCommandArgs
	ReportCommandArgs* ptr = dynamic_cast<ReportCommandArgs*>(inPCommandArgs.get());

	// Call print on robot with input ostream from ReportCommandArgs
    inPObject->Print(ptr->OutPutStream());

	return true;
}
