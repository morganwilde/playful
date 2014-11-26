#include "RectangleTriangle.h"

RectangleTriangle::RectangleTriangle(Point origin, double width, double height)
{
    this->rectangle = ShapeRectangle(Point(origin.getX() + width/2, origin.getY(), origin.getZ()), width/2, height);
    this->triangle = ShapeTriangle(origin, width/2, height);
}
