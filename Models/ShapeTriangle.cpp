#include "ShapeTriangle.h"

ShapeTriangle::ShapeTriangle(Point origin, double width, double height)
{
    Shape::Shape();
    // Set properties
    this->setOrigin(origin);
    this->setWidth(width);
    this->setHeight(height);

    // Create necessary points
    Point top = Point(origin.getX(), origin.getY() + this->getHeight(), origin.getZ());
    Point right = Point(origin.getX() + this->getWidth(), origin.getY(), origin.getZ());
    
    // Add them to the point array
    this->pushToPointArray(origin);
    this->pushToPointArray(top);
    this->pushToPointArray(right);
}

ShapeTriangle::~ShapeTriangle()
{

}

// Setters
void ShapeTriangle::setOrigin(Point origin)
{
    this->origin = origin;
}
void ShapeTriangle::setWidth(double width)
{
    this->width = width;
}
void ShapeTriangle::setHeight(double height)
{
    this->height = height;
}
// Getters
Point ShapeTriangle::getOrigin()
{
    return this->origin;
}
double ShapeTriangle::getWidth()
{
    return this->width;
}
double ShapeTriangle::getHeight()
{
    return this->height;
}
