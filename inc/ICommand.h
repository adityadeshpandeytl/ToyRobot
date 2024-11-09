#ifndef __I_COMMAND_H__
#define __I_COMMAND_H__

#include <memory>
#include "IObject.h"
#include "ICommandArgs.h"

/* Interface for the Command all the interfaces are made 
 * non copyiable. If there may arise a need for copying 
 * then proper handling will be needed in concrete implementation
 * classes. */
class ICommand
{
    public:
        virtual ~ICommand() {}
        virtual bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs) = 0;
        ICommand() {}
        ICommand(const ICommand& obj) = delete;
        ICommand& operator = (const ICommand& obj) = delete;
        bool operator == (const ICommand& obj) = delete;
};

#endif
