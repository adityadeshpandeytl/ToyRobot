#ifndef __OBJECTS_H__
#define __OBJECTS_H__

#include <memory>
#include <string>
#include <fstream>
#include "Sys.h"
#include "Canvas.h"
#include "IObject.h"
#include "IDirection.h"

/* Concrete object on table, the Robot */
class Robot : public IObject
{
	public:
		Robot(SYSINT inX, SYSINT inY, std::unique_ptr<Canvas>& inpCanvas, const std::string& inDirection);
		virtual ~Robot() {}
		virtual bool TurnLeft() override;
		virtual bool TurnRight() override;
		virtual bool Move() override;
		virtual void Print(std::ostream& outputStream) override;
	private:
		SYSINT mX;
		SYSINT mY;
		std::unique_ptr<Canvas>& mpCanvas;
		std::unique_ptr<IDirection> mpDirection;
};

#endif
