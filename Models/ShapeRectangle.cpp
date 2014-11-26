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
    
    setTriangleA(origin, topLeft, bottomRight);
    setTriangleB(topRight, bottomRight, topLeft);
    std::cout << "ShapeRectangle" << triangleA.getPointCount() << std::endl;
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
void ShapeRectangle::setTriangleA(Point a1, Point a2, Point a3)
{
    triangleA = ShapeTriangle(a1, a2, a3);
    for (int i = 0; i < triangleA.getPointCount(); i++) {
        //pushToPointArray(triangleA.popFromPointArray());
    }
}
void ShapeRectangle::setTriangleB(Point a1, Point a2, Point a3)
{
    triangleB = ShapeTriangle(a1, a2, a3);
    for (int i = 0; i < triangleB.getPointCount(); i++) {
        //pushToPointArray(triangleB.popFromPointArray());
    }
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