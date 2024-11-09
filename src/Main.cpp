#include "Table.h"
#include "SysIO.h"
#include "CommandFactory.h"
#include "CommandArgsFactory.h"
#include <iostream>
#include <stdexcept>

int main()
{

	/* Table class acts as a container to hold
	 * all the objects that could be present or placed
	 * on top of the table.
	 */
	Table t(0, 4, 0, 4);

	/* Command Reader is all together a different
	 * module implemented as class hierarchy
	 * to read command from either file or 
	 * from console. It establishes stream
	 * to read the input commands. Code below
	 * creates an instance of a Command reader.
	 * The file path is hardcoded at the moment
	 * however, it can be provided to the code
	 * using a config file for the application
	 * where it can also be specified whether
	 * the program should be run to read input from
	 * console or from the file.
	 * If required, an additional class or function
	 * could be added to read from config file and 
	 * the hardcoding can be removed. 
	 */
	std::unique_ptr<ICommandReader> pCmdReader;
	try {
		//pCmdReader = std::move(std::make_unique<ConsoleCommandReader>());
		pCmdReader = std::move(std::make_unique<FileCommandReader>("CommandFile.txt"));
	}
	catch ( const std::exception& e) {
		std::cout<<"Failed to create command reader.\n";
		std::cout<<e.what()<<"\n";
		return 0;
	}

	std::string cmd;
	// CommandFactory is responsible for
	// creating an instance of the input
	// command.
	CommandFactory cmdFactory;

	// CommandArgsFactory is responsible for
	// creating an instance of Arguments
	// required to run execute the command.
	// It takes instance of ostream as input
	// The program can be made to record the output
	// of Report command to a file. Again, config
	// file can be introduced to decide whether the output
	// should be in a file or on console. The code is not 
	// implemented to record output to a file, but that
	// can be done just by creating a stream for a file
	// and by passing the stream instance to 
	// CommandArgsFactory. 
	CommandArgsFactory cmdArgsFactory(std::cout);

	// Keep reading from the input stream till the 
	// enf of file is reached. If code is made to read
	// input from the Console then Ctrl+D or Ctrl+C 
	// should be pressed to stop the program.
	while (pCmdReader->ReadCommand(cmd))
	{
		try {
			// Extract the actual command from the
			// line read using the input stream.
			// Except for the PLACE command rest all
			// the commands do not have any argument
			// so much of the logic here is to handle 
			// the PLACE command. First step is to
			// separate Command from its arguments, if 
			// the command has any. The format for
			// every command is assumed as below.
			// <cmd> <arg1>,<arg2>,<arg>
			// So the command and its arguments are separated
			// by a space. ExtractCommandFromInput function
			// internally just splits the input string
			// at the position where the first space is 
			// encountered. First element in pair is
			// the actual Command and second element will
			// hold the comma separated argument list.
			std::pair<std::string, std::string> cmdPr;
			ExtractCommandFromInput(cmd, cmdPr);

			// Create command arguments for the input command
			// that is extracted in the previous step.
			auto pCmdArgs = cmdArgsFactory.CreateCommandArgsInstance(cmdPr.first, cmdPr.second, t);

			// Create an instance of command class depending
			// on the input command extracted.
			auto pCmd = cmdFactory.CreateCommandInstance(cmdPr.first);

			// Validate that both the command and command args
			// instances are not null. This could happen
			// if the input command is not valid or the arguments
			// are not correct. If the input format to enter
			// command and its arguments is incorrect. And, then
			// finally execute the command on the object,
			// Robot in this case, using the input command args.
			// If table is holding more than one objects, then
			// code can be extended to select an object using 
			// some identifier on which the command needs to be
			// executed. More than one object is like a scenario
			// where 2 or even 3 robots and a Toy Car is placed 
			// on the table.
			if(pCmdArgs != nullptr && pCmd != nullptr)
				pCmd->Execute(t.GetObject(), pCmdArgs);
		} catch ( const std::exception& e) {
			std::cout<<"Failed to execute command.\n";
			std::cout<<e.what()<<"\n";
		}	
	}
	return 0;
}


