#include "CommandFactory.h"
#include "ICommand.h"

std::unique_ptr<ICommand> CommandFactory::CreateCommandInstance(const std::string& inCommand)
{
	// If input command not present return nullptr
	if(mCommandFactoryMap.find(inCommand) == mCommandFactoryMap.end())
		return nullptr;	

	return mCommandFactoryMap[inCommand]();
}
