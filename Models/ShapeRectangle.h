#ifndef SHAPERECTANGLE_H
#define SHAPERECTANGLE_H

#include "Shape.h"

class ShapeRectangle : public Shape
{
private:
    Point origin;
    double width;
    double height;
public:
    ShapeRectangle(Point origin, double width, double height);
    ~ShapeRectangle();
    // Setters
    void setOrigin(Point origin);
    void setWidth(double width);
    void setHeight(double height);
    // Getters
    Point getOrigin();
    double getWidth();
    double getHeight();
    double getArea();
    // Comparison methods
    template <class ShapeClass>
    bool compareAreaWith(ShapeClass shape);
};

#endif
