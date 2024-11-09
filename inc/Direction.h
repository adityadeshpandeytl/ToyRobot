#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include "IDirection.h"
#include "Sys.h"
#include <memory>

/* Templatised policy pattern implemented
 * to handle direction properties */

template<typename DIRECTION>
class Direction final : public IDirection
{
	public:
		Direction() : pDirection(std::make_unique<DIRECTION>()) {}
		virtual ~Direction() {}

		virtual std::unique_ptr<IDirection> Left() override
		{
			return pDirection->HandleTurnLeft();
		}

		virtual std::unique_ptr<IDirection> Right() override
		{
			return pDirection->HandleTurnRight();
		}

		virtual std::pair<SYSINT, SYSINT> Move(SYSINT inX, SYSINT inY) override
		{
			return pDirection->HandleMovement(inX, inY);
		}

		virtual const std::string& GetDirection() override
		{
			return pDirection->DirectionName();
		}
	private:
		std::unique_ptr<DIRECTION> pDirection;
};
#endif
