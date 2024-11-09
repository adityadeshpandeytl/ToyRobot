#ifndef __COMMAND_ARGS_H__
#define __COMMAND_ARGS_H__

#include <string>
#include <fstream>
#include "ICommandArgs.h"
#include "Table.h"
#include "Sys.h"

/* Generic Command argument class used 
 * for LEFT, RIGHT, MOVE commands */
class CommandArgs : public ICommandArgs
{
	public:
		CommandArgs(const std::string& inInputString, class Table& inTableObj);
		virtual bool Build() override { return true; }
		virtual ~CommandArgs() {}
		class Table& Table() { return mTableObj; }
	protected:
		std::string mInputString;
		class Table& mTableObj;
};

/* Used, if the input command is to place Robot 
 * i.e for the PLACE command. */
class PlaceCommandArgs final : public CommandArgs
{
	public:
		PlaceCommandArgs(const std::string& inInputString, class Table& inTableObj);
		virtual bool Build() override;
		const SYSINT X () const { return mX; }
		const SYSINT Y () const { return mY; }
		const std::string& Direction () const { return mDirection; }
	private:
		SYSINT mX;
		SYSINT mY;
		std::string mDirection;
};

/* Used for the REPORT command, hence this one
 * has got reference to ostream */ 
class ReportCommandArgs final : public CommandArgs
{
	public:
		ReportCommandArgs(const std::string& inInputString, class Table& inTableObj, std::ostream& inOutputStream);
		std::ostream& OutPutStream() { return mOuputStream; }
	private:
		std::ostream& mOuputStream;
};
#endif
