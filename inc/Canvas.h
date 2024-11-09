#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "Sys.h"

/* The class represents actual two dimentional geometric
 * coordinate system. Instance of this class is created
 * in Table and is shared or passed to Robot (Object).
 * Idea for a separate class is to consider a possibility
 * where the table can get divided in 2 or even 4 parts
 * each one having an object or Robot with its movement
 * restricted to only that part. Sharing the Canvas instance
 * with Robot is meant to handle a scenario where more than
 * one robots getting placed on the canvas. The ValidatePosition
 * Function in this class is the most important one to validate
 * whether the object or Robot can be moved to that position or not.
 * Moreover, the requirement may come like few cells on the canvas
 * are filled with minefields, just to make the game interesting.
 * Such scenarios can be handled by keeping this class separated.
 */ 
class Canvas
{
	public:
		Canvas(SYSINT inMinX, SYSINT inMaxX, SYSINT inMinY, SYSINT inMaxY);
		bool ValidatePosition(SYSINT inX, SYSINT inY);
	private:
		const SYSINT mMinX; 
		const SYSINT mMaxX; 
		const SYSINT mMinY; 
		const SYSINT mMaxY; 
};

#endif
