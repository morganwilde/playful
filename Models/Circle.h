#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapesArray.h"
#include "ShapeTriangle.h"
#include <cmath>

class Circle : public ShapesArray
{
private:
    Point center;
    int segments;
    double radius;
    void init(Point center, double radius, int segments);
public:
    Circle(Point center, double radius, int segments);
    Circle(Point center, double radius);
    ~Circle();
    // Setters
    void setCenter(Point center);
    void setRadius(double radius);
    // Getters
    Point getCenter() const;
    double getRadius() const;
    int getSegments() const;
    double getPerimeter();
    Point getPointFromPolarAngle(double angle);
    // Getters Private
    double getSegmentWidth();
    std::string getShapesArrayType() const;
};

#endif