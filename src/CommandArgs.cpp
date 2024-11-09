#include "CommandArgs.h"
#include <sstream>

/* The first argument here "inInputString" is basically the command arguments
 * which are only applicable for the PLACE command. The Build function
 * then can be used to parse the string arguments and prepare proper input for the
 * command.
 */ 
CommandArgs::CommandArgs(const std::string& inInputString, class Table& inTableObj) :
	mInputString(inInputString), mTableObj(inTableObj) {}

PlaceCommandArgs::PlaceCommandArgs(const std::string& inInputString, class Table& inTableObj) :
	CommandArgs(inInputString, inTableObj) {}

/* Build function parses command args
 * and prepare input for PLACE command */
bool PlaceCommandArgs::Build()
{
	std::vector<std::string> cmdParams;

	// Remove spaces from arguments if present
	// So even if the input is 1,	2, SOUTH
	// it will still be treated as a valid
	// input.
	RemoveSpacesInStr(mInputString);

	// Split or parse the string
	// and extract each argument in
	// cmdParams in std::string format.
	SplitStr(mInputString, ",", cmdParams);

	// Validate that three 
	// arguments are present
	// representing X, Y and Direction
	if(cmdParams.size() < 3)
		return false;

	// Convert X and Y from 
	// string to SYSINT	using 
	// stringstream.
	std::stringstream ss;
	ss<<cmdParams[0];
	ss>>mX;
	if(ss.fail())
		return false;
	ss.clear();
	ss.str("");
	ss<<cmdParams[1];
	ss>>mY;
	if(ss.fail())
		return false;
	mDirection = std::move(cmdParams[2]);
	return true;
}

/* ReportCommandArgs takes an extra parameter, the ostream */
ReportCommandArgs::ReportCommandArgs(const std::string& inInputString, class Table& inTableObj,
		std::ostream& inOutputStream) : CommandArgs(inInputString, inTableObj), mOuputStream(inOutputStream) {}

