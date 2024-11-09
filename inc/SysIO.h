#ifndef __SYS_IO_H__
#define __SYS_IO_H__

#include <fstream>
#include <string>

// Moving interface to a separate file was not really needed.
class ICommandReader
{
	public:
		virtual ~ICommandReader(){}	
		virtual bool ReadCommand(std::string& ioCommand) = 0;
        ICommandReader() {}
        ICommandReader(const ICommandReader& obj) = delete;
        ICommandReader& operator = (const ICommandReader& obj) = delete;
        bool operator == (const ICommandReader& obj) = delete;
};

// To read input from file. Destructor is needed 
// specifically to close the file stream gracefully
// on exit.
class FileCommandReader final : public ICommandReader
{
	public:
		FileCommandReader(const std::string& inFileName);
		virtual bool ReadCommand(std::string& ioCommand) override;
		~FileCommandReader();
	private:
		std::ifstream mStream;
};

// There is no need to close std::cin stream on exit in this 
// class.
class ConsoleCommandReader final : public ICommandReader
{
	public:
		ConsoleCommandReader();
		virtual bool ReadCommand(std::string& ioCommand) override;
};

#endif
