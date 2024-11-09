#include "CommandArgsFactory.h"

std::unique_ptr<ICommandArgs> CommandArgsFactory::CreateCommandArgsInstance(const std::string& inCmd,
		const std::string& inCmdArgs, Table& inTableObj)
{
	// Validate that input command is valid, if not return nullptr.
	if(mCommandArgsFactoryMap.find(inCmd) == mCommandArgsFactoryMap.end())
		return nullptr;

	// Create command Args Instance.
	auto pICommandArgs =  mCommandArgsFactoryMap[inCmd](inCmdArgs, inTableObj);

	// Once the instance is created call
	// build function to 
	// parse input arguments and prepare
	// actual input for the command.
	pICommandArgs->Build();

	return pICommandArgs;
}
