#ifndef RECTANGLETRIANGLE_H
#define RECTANGLETRIANGLE_H

#include "../Models/ShapeRectangle.h"
#include "../Models/ShapeTriangle.h"

class RectangleTriangle
{
private:
    ShapeRectangle rectangle;
    ShapeTriangle triangle;
public:
    RectangleTriangle(Point origin, double width, double height);
    ~RectangleTriangle();
};

#endif
