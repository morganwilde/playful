#include "ShapeRectangle.h"

ShapeRectangle::ShapeRectangle(Point origin, double width, double height)
{
    Shape::Shape();
    // Set properties
    this->setOrigin(origin);
    this->setWidth(width);
    this->setHeight(height);

    // Create necessary points
    Point topLeft = Point(origin.getX(), origin.getY() + this->getHeight(), origin.getZ());
    Point topRight = Point(origin.getX() + this->getWidth(), origin.getY() + this->getHeight(), origin.getZ());
    Point bottomRight = Point(origin.getX() + this->getWidth(), origin.getY(), origin.getZ());
    
    // Add them to the point array
    this->pushToPointArray(origin);
    this->pushToPointArray(topLeft);
    this->pushToPointArray(bottomRight);
    this->pushToPointArray(topRight);
    this->pushToPointArray(bottomRight);
    this->pushToPointArray(topLeft);
}

ShapeRectangle::~ShapeRectangle()
{

}

// Setters
void ShapeRectangle::setOrigin(Point origin)
{
    this->origin = origin;
}
void ShapeRectangle::setWidth(double width)
{
    this->width = width;
}
void ShapeRectangle::setHeight(double height)
{
    this->height = height;
}
// Getters
Point ShapeRectangle::getOrigin()
{
    return this->origin;
}
double ShapeRectangle::getWidth()
{
    return this->width;
}
double ShapeRectangle::getHeight()
{
    return this->height;
}
double ShapeRectangle::getArea()
{
    return this->getWidth() * this->getHeight();
}

