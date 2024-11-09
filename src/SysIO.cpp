#include "SysIO.h"
#include <iostream>

FileCommandReader::FileCommandReader(const std::string& inFileName)
{
	if(!std::filesystem::exists(inFileName))
		throw std::runtime_error("Input File not Present.");

	mStream = std::move(std::ifstream(inFileName));

	if(!mStream.is_open() ||  !mStream.good() )
		throw std::runtime_error("Cannot open the file.");
};

bool FileCommandReader::ReadCommand(std::string& ioCommand)
{
	if(!mStream.is_open())
		return false;

	std::getline(mStream, ioCommand);

	if(mStream.eof())
		return false;

	return true;
}

FileCommandReader::~FileCommandReader()
{
	if(mStream.is_open())
	{
		mStream.close();
	}
}

ConsoleCommandReader::ConsoleCommandReader()
{ }

bool ConsoleCommandReader::ReadCommand(std::string& ioCommand)
{
	std::getline(std::cin, ioCommand);

	if(std::cin.eof())
		return false;

	return true;
}
