#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapesArray.h"
#include "ShapeTriangle.h"
#include "Color.h"

class Rectangle : public ShapesArray
{
private:
    Color color;
public:
    Rectangle(Point origin, double width, double height);
    ~Rectangle();
    // Setters
    void setColor(Color color);
    // Getters
    Color getColor();
};

#endif