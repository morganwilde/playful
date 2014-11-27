#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapesArray.h"
#include "ShapeTriangle.h"
#include <cmath>

class Circle : public ShapesArray
{
private:
    int segments;
    double radius;
    void init(Point center, double radius, int segments);
public:
    Circle(Point center, double radius, int segments);
    Circle(Point center, double radius);
    ~Circle();
    // Setters
    void setRadius(double radius);
    // Getters
    double getRadius();
    double getPerimeter();
    // Getters Private
    double getSegmentWidth();
};

#endif