#ifndef SHAPETRIANGLE_H
#define SHAPETRIANGLE_H

#include "Shape.h"

class ShapeTriangle : public Shape
{
private:
    Point origin;
    double width;
    double height;
public:
    ShapeTriangle(Point origin, double width, double height);
    ~ShapeTriangle();
    // Setters
    void setOrigin(Point origin);
    void setWidth(double width);
    void setHeight(double height);
    // Getters
    Point getOrigin();
    double getWidth();
    double getHeight();
};

#endif
