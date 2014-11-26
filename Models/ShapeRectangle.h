#ifndef SHAPERECTANGLE_H
#define SHAPERECTANGLE_H

#include "Shape.h"
#include "ShapeTriangle.h"

class ShapeRectangle : public Shape
{
private:
    Point origin;
    double width;
    double height;
    ShapeTriangle triangleA;
    ShapeTriangle triangleB;
public:
    ShapeRectangle(Point origin, double width, double height);
    ~ShapeRectangle();
    // Setters
    void setOrigin(Point origin);
    void setWidth(double width);
    void setHeight(double height);
    void setTriangleA(Point a1, Point a2, Point a3);
    void setTriangleB(Point a1, Point a2, Point a3);
    // Getters
    Point getOrigin();
    double getWidth();
    double getHeight();
    double getArea();
};

#endif
