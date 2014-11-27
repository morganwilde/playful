#include "Circle.h"

void Circle::init(Point center, double radius, int segments)
{
    this->segments = segments;
    this->setRadius(radius);
}

Circle::Circle(Point center, double radius, int segments)
{
    // Designated constructor
    ShapesArray::ShapesArray();
    init(center, radius, segments);
}

Circle::Circle(Point center, double radius)
{
    // Convenience constructor
    ShapesArray::ShapesArray();
    init(center, radius, 1);
}

Circle::~Circle()
{

}

// Setters
void Circle::setRadius(double radius)
{
    this->radius = radius;
}

// Getters
double Circle::getRadius()
{
    return this->radius;
}
double Circle::getPerimeter()
{
    return 2 * M_PI * getRadius();
}
// Getters private
double Circle::getSegmentWidth()
{
    return getPerimeter() / segments;
}