#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "ICommand.h"
#include "ICommandArgs.h"
#include "IObject.h"
#include <memory>

/* Actual Command templatised Wrapper class */
template<typename COMMAND>
class Command final : public ICommand
{
	public:
		virtual bool Execute(std::unique_ptr<IObject>& inPObject, std::unique_ptr<ICommandArgs>& inPCommandArgs) override
		{
			try {
				return COMMAND().Execute(inPObject, inPCommandArgs);
			} catch ( ... ) {
				return false;
			}
		}
};

#endif
