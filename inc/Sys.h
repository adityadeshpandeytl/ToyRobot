#ifndef __SYS_H__
#define __SYS_H__

#include <cstdint>
#include <string>
#include <vector>

// Size of the coordinate can be changed any time
// by changing SYSINT.
using SYSINT = int16_t;

// Remove all the spaces in input string
// to handle input argument list for place command
// something like 1,   2,   NORTH
void RemoveSpacesInStr(std::string& inStr);

// To split input arguments for PLACE command.
void SplitStr(const std::string& inStr, const std::string& delimiter, std::vector<std::string>& oSplitStrings);

// To separate command from its input arguments.
void ExtractCommandFromInput(const std::string& inStr, std::pair<std::string, std::string>& oSplitStrings);
#endif
