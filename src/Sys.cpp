#include "Sys.h"

// File has all the helper functions.

void RemoveSpacesInStr(std::string& inStr)
{
	// Remove all the spaces from the input string.
	inStr.erase(std::remove_if(inStr.begin(), inStr.end(), ::isspace), inStr.end());
}

void SplitStr(const std::string& inStr, const std::string& delimiter, std::vector<std::string>& oSplitStrings)
{
	size_t position = 0;

	while(position < inStr.size())
	{
		// Get first position of input delimiters.
		auto delimiterPos = inStr.find_first_of(delimiter, position);
		// Extract the string from the position to the delimiter.
		std::string splitStr = inStr.substr(position, delimiterPos - position);
		// If the string is empty, do not bother to
		// add it to output vector.
		if(!splitStr.empty())
			oSplitStrings.push_back(splitStr);
		// If the delimiter position is end of string then break.
		if(delimiterPos == std::string::npos)
			break;
		// Else update the position to start next
		// search for delimiters.
		position = delimiterPos + 1;
	}
}

void ExtractCommandFromInput(const std::string& inStr, std::pair<std::string, std::string>& oSplitStrings)
{
	// Just get the first space and split the input string in two.
	size_t position = 0;
	// Space can be anything, single space or tab.
	// Included all the possible characters represented by ::isspace in C++
	auto delimiterPos = inStr.find_first_of(" \f\t\r\v\n", position);
	oSplitStrings.first = std::move(inStr.substr(position, delimiterPos - position));
	// If the command arguments are present then only add to the output vectors.
	if(delimiterPos != std::string::npos)
		oSplitStrings.second = std::move(inStr.substr(delimiterPos));	
}
