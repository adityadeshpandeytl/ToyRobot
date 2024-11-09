#ifndef __DIRECTION_FACTORY_H__
#define __DIRECTION_FACTORY_H__

#include <memory>
#include <string>
#include <functional>
#include <unordered_map>
#include "ConcreteDirections.h"
#include "Direction.h"

/* Setup for creating direction instance */

#define DIRECTION_FACTORY_SETUP(DIRECTION, DIRECTION_CLASS) \
    mDirectionFactory[#DIRECTION] = []() { return std::make_unique<Direction<DIRECTION_CLASS> >(); };
class DirectionFactory final
{
    public:
        DirectionFactory()
        {
            DIRECTION_FACTORY_SETUP(NORTH, NorthFacing);
            DIRECTION_FACTORY_SETUP(SOUTH, SouthFacing);
            DIRECTION_FACTORY_SETUP(EAST, EastFacing);
            DIRECTION_FACTORY_SETUP(WEST, WestFacing);
        }
        std::unique_ptr<IDirection> GetDirection(const std::string& inDirection);
    private:
        std::unordered_map<std::string, std::function<std::unique_ptr<IDirection> ()> > mDirectionFactory;
};
#undef DIRECTION_FACTORY_SETUP

#endif
