#ifndef SHAPETRIANGLE_H
#define SHAPETRIANGLE_H

#include "Shape.h"

class ShapeTriangle : public Shape
{
private:
    Point a1; // Origin
    Point a2;
    Point a3;
    // Convenience methods
    void init(Point a1, Point a2, Point a3);
public:
    ShapeTriangle(Point origin, double width, double height);
    ShapeTriangle(Point a1, Point a2, Point a3);
    ~ShapeTriangle();
    // Setters
    void setPointA1(Point a1);
    void setPointA2(Point a2);
    void setPointA3(Point a3);
    // Getters
    Point getPointA1();
    Point getPointA2();
    Point getPointA3();
};

#endif
