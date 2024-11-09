#ifndef __I_COMMAND_ARGS_H__
#define __I_COMMAND_ARGS_H__

/* Interface for CommandArgs */

class ICommandArgs
{
    public:
        virtual bool Build() = 0;
        virtual ~ICommandArgs(){}
        ICommandArgs() {}
        ICommandArgs(const ICommandArgs& obj) = delete;
        ICommandArgs& operator = (const ICommandArgs& obj) = delete;
        bool operator == (const ICommandArgs& obj) = delete;
};
#endif
