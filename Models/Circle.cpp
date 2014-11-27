#include "Circle.h"

void Circle::init(Point center, double radius, int segments)
{
    this->segments = segments;
    this->setCenter(center);
    this->setRadius(radius);

    // The environment
    double circleRadius = 2 * M_PI;
    double segmentRadius = circleRadius / this->segments;
    double angleStart = 0;
    double angle = angleStart;

    // Create segments
    for (int i = 0; i < this->segments; i++) {
        Point pointFrom = getPointFromPolarAngle(angle);
        Point pointTo = getPointFromPolarAngle(angle + segmentRadius);
        ShapeTriangle *segment = new ShapeTriangle(getCenter(), pointFrom, pointTo);
        add(segment);
        //std::cout << "segment #" << i << "; angle: " << angle << pointFrom << pointTo << std::endl;
        angle += segmentRadius;
    }
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
void Circle::setCenter(Point center)
{
    this->center = center;
}
void Circle::setRadius(double radius)
{
    this->radius = radius;
}

// Getters
Point Circle::getCenter()
{
    return this->center;
}
double Circle::getRadius()
{
    return this->radius;
}
double Circle::getPerimeter()
{
    return 2 * M_PI * getRadius();
}
Point Circle::getPointFromPolarAngle(double angle)
{
    double x = getRadius() * cos(angle);
    double y = getRadius() * sin(angle);
    return Point(getCenter().getX() + x, getCenter().getY() + y);
}
// Getters private
double Circle::getSegmentWidth()
{
    return getPerimeter() / segments;
}