#ifndef __I_OBJECTS_H__
#define __I_OBJECTS_H__

#include <fstream>

/* Interface for Robot (Objects). One of the design 
 * thoughts was to treat Canvas as an object which 
 * ultimately is placed on the table. However, canvas
 * has got totaly different properties than the objects placed
 * on the table or on the Canvas like, directions coordinates
 * movements etc. The advantage of inheriting Canvas from IObjects
 * can be like to handle Commands that can operate on Canvas. Something
 * like to PLACE-MINEFIELD on canvas at location x,y. These commands 
 * then can be made part of the existing command setup and the input object
 * to execute these kind of commands then can be the instance of Canvas.
 * However, Canvas is not really an object, its more like a coordinate system
 * drawn on the table. And in case if need arises to handle these kind of 
 * command/scenarios then one more interface can be placed on top of
 * this one and that can be named as IObject where as this can be renamed
 * to IObjectOnCanvas. Or may be a separate logical module can be created to handle
 * Canvas Commands.
 */ 
class IObject
{
    public:
        IObject(){}
        virtual ~IObject(){}
        virtual bool TurnLeft() = 0;
        virtual bool TurnRight() = 0;
        virtual bool Move() = 0;
        virtual void Print(std::ostream& outputStream) = 0;
        IObject(const IObject& obj) = delete;
        IObject& operator = (const IObject& obj) = delete;
        bool operator == (const IObject& obj) = delete;
};

#endif
