#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapesArray.h"
#include "ShapeTriangle.h"
#include "Color.h"

class Circle : public ShapesArray
{
public:
    Rectangle(Point origin, double width, double height);
    ~Rectangle();
};

#endif