#include "Table.h"
#include "Robot.h"

Table::Table(SYSINT inMinX, SYSINT inMaxX, SYSINT inMinY, SYSINT inMaxY) : 
	mpCanvas(std::move(std::make_unique<Canvas>(inMinX, inMaxX, inMinY, inMaxY))), mpRobot(nullptr) {}

// Create instance of Robot
std::unique_ptr<IObject>&  Table::CreateObject(SYSINT inX, SYSINT inY, const std::string& inDirection)
{
	if(!mpCanvas->ValidatePosition(inX, inY))
		throw std::invalid_argument("Input Coordinates not valid");

	try {
		std::unique_ptr<IObject> pNewObject = std::make_unique<Robot>(inX, inY, mpCanvas, inDirection);
		mpRobot = std::move(pNewObject);
		return std::ref(mpRobot);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
	catch ( ... ) {
		throw std::runtime_error("Unknown error");
	}
}

// Get instance of Robot, return reference to
// the unique_ptr.
std::unique_ptr<IObject>& Table::GetObject()
{
	return std::ref(mpRobot);
}
