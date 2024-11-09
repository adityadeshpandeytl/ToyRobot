#include "Canvas.h"

Canvas::Canvas(SYSINT inMinX, SYSINT inMaxX, SYSINT inMinY, SYSINT inMaxY) :
	mMinX(inMinX), mMaxX(inMaxX), mMinY(inMinY), mMaxY(inMaxY) {}

// Validate whether the input position is valid and
// is within the area of the canvas.
bool Canvas::ValidatePosition(SYSINT inX, SYSINT inY)
{
	return mMinX <= inX && inX <= mMaxX && mMinY <= inY && inY <= mMaxY;
}
