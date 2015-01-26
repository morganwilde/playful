#include "Rectangle.h"

Rectangle::Rectangle(Point origin, double width, double height)
{
    ShapesArray::ShapesArray();

    // Store attributes
    this->origin = origin;
    this->width = width;
    this->height = height;

    // Create three more anchor points
    Point originW = Point(origin.getX() + width, origin.getY());
    Point originH = Point(origin.getX(), origin.getY() + height);
    Point originWH = Point(origin.getX() + width, origin.getY() + height);

    ShapeTriangle *triangle1 = new ShapeTriangle(origin, originW, originH);
    ShapeTriangle *triangle2 = new ShapeTriangle(originWH, originW, originH);

    // Add triangles to the Shape array
    add(triangle1);
    add(triangle2);
}

Rectangle::~Rectangle()
{

}

std::string Rectangle::getShapesArrayType() const
{
    std::stringstream ss;
    ss << "Rectangle( ";
    ss << origin << ", ";
    ss << width << ", ";
    ss << height << " )";
    return ss.str();
}