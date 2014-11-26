#include "Rectangle.h"

Rectangle::Rectangle(Point origin, double width, double height)
{
    ShapesArray::ShapesArray();

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

// Setters
void Rectangle::setColor(Color color)
{
    this->color = color;
    for (int i = 0; i < getShapeCount(); i++) {
        getShapeArray()[i]->color = getColor();
    }
    
}
// Getters
Color Rectangle::getColor()
{
    return this->color;
}