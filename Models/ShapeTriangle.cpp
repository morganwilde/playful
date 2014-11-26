#include "ShapeTriangle.h"

void ShapeTriangle::init(Point a1, Point a2, Point a3)
{
    /* Designated initialiser */

    // Set anchor points
    this->setPointA1(a1);
    this->setPointA2(a2);
    this->setPointA3(a3);

    // Add them to the point array
    pushToPointArray(getPointA1());
    pushToPointArray(getPointA2());
    pushToPointArray(getPointA3());
}

ShapeTriangle::ShapeTriangle()
{
    // Convenience constructor
    Shape::Shape();
}

ShapeTriangle::ShapeTriangle(Point a1, Point a2, Point a3)
{
    // Designated constructor
    Shape::Shape();
    init(a1, a2, a3);
    std::cout << "ShapeTriangle" << getPointCount() << std::endl;
}

ShapeTriangle::ShapeTriangle(Point origin, double width, double height)
{
    // Convenience constructor
    Shape::Shape();
    Point top = Point(origin.getX(), origin.getY() + height, origin.getZ());
    Point right = Point(origin.getX() + width, origin.getY(), origin.getZ());
    init(origin, top, right);
}

ShapeTriangle::~ShapeTriangle()
{

}

// Setters
void ShapeTriangle::setPointA1(Point a1)
{
    this->a1 = a1;
}
void ShapeTriangle::setPointA2(Point a2)
{
    this->a2 = a2;
}
void ShapeTriangle::setPointA3(Point a3)
{
    this->a3 = a3;
}
// Getters
Point ShapeTriangle::getPointA1() const
{
    return this->a1;
}
Point ShapeTriangle::getPointA2() const
{
    return this->a2;
}
Point ShapeTriangle::getPointA3() const
{
    return this->a3;
}
