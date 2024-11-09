#ifndef __COMMAND_FACTORY_H__
#define __COMMAND_FACTORY_H__

#include <string>
#include <functional>
#include <unordered_map>
#include "ConcreteCommands.h"
#include "Command.h"

/* Macro to prepare table for creating instance of the Command */

#define COMMAND_FACTORY_SETUP(INPUT_COMMAND, COMMAND_CLASS) \
    mCommandFactoryMap[#INPUT_COMMAND] = []() { return std::make_unique<Command<COMMAND_CLASS> >(); };
class CommandFactory 
{
    public:
        std::unique_ptr<ICommand> CreateCommandInstance(const std::string& inCommand);

		/* Add entries to the table/unordered_map in the cunstructor */
        CommandFactory() {
			/* This will ultimately get expanded to
			 * mCommandFactoryMap["PLACE"] = []() { return std::make_unique<Command<PlaceCommand> >(); };
			 */
            COMMAND_FACTORY_SETUP(PLACE, PlaceCommand);
            COMMAND_FACTORY_SETUP(LEFT, LeftCommand);
            COMMAND_FACTORY_SETUP(RIGHT, RightCommand);
            COMMAND_FACTORY_SETUP(MOVE, MoveCommand);
            COMMAND_FACTORY_SETUP(REPORT, ReportCommand);
        }
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<ICommand> ()> > mCommandFactoryMap;
};
#undef COMMAND_FACTORY_SETUP


#endif
