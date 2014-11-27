#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapesArray.h"
#include "ShapeTriangle.h"

class Rectangle : public ShapesArray
{
public:
    Rectangle(Point origin, double width, double height);
    ~Rectangle();
};

#endif