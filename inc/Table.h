#ifndef __TABLE_H__
#define __TABLE_H__

#include <memory>
#include <string>
#include "Sys.h"
#include "Canvas.h"
#include "IObject.h"

// Container to hold canvas and all the objects that 
// can be placed on the canvas.
class Table
{
	public:
		Table(SYSINT inMinX, SYSINT inMaxX, SYSINT inMinY, SYSINT inMaxY);
		std::unique_ptr<IObject>& CreateObject(SYSINT inX, SYSINT inY, const std::string& inDirection);
		std::unique_ptr<IObject>& GetObject();
		std::unique_ptr<Canvas>& GetCanvas() { return std::ref(mpCanvas); }
		Table(const Table& obj) = delete;
		Table& operator = (const Table& obj) = delete;
		bool operator == (const Table& obj) = delete;
	private:
		std::unique_ptr<Canvas> mpCanvas;
		std::unique_ptr<IObject> mpRobot;
};

#endif
