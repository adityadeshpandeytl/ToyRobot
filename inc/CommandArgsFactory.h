#ifndef __COMMAND_ARGS_FACTORY_H__
#define __COMMAND_ARGS_FACTORY_H__

#include "CommandArgs.h"

/* Macro to setup table for creating instances of CommandArguments */

#define COMMAND_ARGS_FACTORY_SETUP(INPUT_COMMAND, COMMAND_ARGS_CLASS) \
	mCommandArgsFactoryMap[#INPUT_COMMAND] = std::bind(&CommandArgsFactory::ActCreateInstance<COMMAND_ARGS_CLASS>, \
			this, std::placeholders::_1, std::placeholders::_2);

class CommandArgsFactory
{
	public:
		CommandArgsFactory(std::ostream& inSysOutputStream) : mSysOutputStream(inSysOutputStream) {
			COMMAND_ARGS_FACTORY_SETUP(PLACE, PlaceCommandArgs);
			COMMAND_ARGS_FACTORY_SETUP(LEFT, CommandArgs);
			COMMAND_ARGS_FACTORY_SETUP(RIGHT, CommandArgs);
			COMMAND_ARGS_FACTORY_SETUP(MOVE, CommandArgs);
			COMMAND_ARGS_FACTORY_SETUP(REPORT, ReportCommandArgs);
		}
		std::unique_ptr<ICommandArgs> CreateCommandArgsInstance(const std::string& inCmd, const std::string& inCmdArgs,
				Table& inTableObj);
	private:
		/* Only report command arguments class has a different 
		 * input parameter list to constructor, hence a templatised
		 * class member function used, with a specialisation only for the 
		 * Report Command Arguments class. For the report command arguments
		 * there is a need to send ostream reference so that output can be
		 * directed to the desired channel.
		 */
		template<typename COMMAND_ARGS_CLASS>
		std::unique_ptr<ICommandArgs> ActCreateInstance(const std::string& inStrCmd, Table& inTableObj)
		{
			return std::make_unique<COMMAND_ARGS_CLASS>(inStrCmd, inTableObj);
		}
		template<>
		std::unique_ptr<ICommandArgs> ActCreateInstance<ReportCommandArgs>(const std::string& inStrCmd, Table& inTableObj)
		{
			return std::make_unique<ReportCommandArgs>(inStrCmd, inTableObj, mSysOutputStream);
		}
		std::ostream& mSysOutputStream;
		std::unordered_map<std::string, std::function<std::unique_ptr<ICommandArgs> (const std::string&, 
				Table&)> > mCommandArgsFactoryMap;
};

#undef COMMAND_ARGS_FACTORY_SETUP

#endif
