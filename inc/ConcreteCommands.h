#ifndef __CONCRETE_COMMAND_H__
#define __CONCRETE_COMMAND_H__

#include <memory>
#include "IObject.h"
#include "ICommandArgs.h"

// Very straight forward single responsibility
// Actual Command classes.
class PlaceCommand
{
    public:
        bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs);
};

class LeftCommand
{
    public:
        bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs);
};

class RightCommand
{
    public:
        bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs);
};

class MoveCommand
{
    public:
        bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs);
};

class ReportCommand
{
    public:
        bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs);
};

#endif
