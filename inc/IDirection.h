#ifndef __I_DIRECTION_H__
#define __I_DIRECTION_H__

#include <string>
#include "Sys.h"

/* Interface for Directions */
class IDirection
{
    public:
        virtual std::unique_ptr<IDirection> Left() = 0;
        virtual std::unique_ptr<IDirection> Right() = 0;
        virtual std::pair<SYSINT, SYSINT> Move(SYSINT inX, SYSINT inY) = 0;
        virtual const std::string& GetDirection() = 0;
        virtual ~IDirection(){}
        IDirection() {}
        IDirection(const IDirection& obj) = delete;
        IDirection& operator = (const IDirection& obj) = delete;
        bool operator == (const IDirection& obj) = delete;
};

#endif
