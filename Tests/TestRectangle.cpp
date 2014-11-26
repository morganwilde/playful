#include "TestRectangle.h"
#include "../Models/Rectangle.h"

TestRectangle::TestRectangle()
{
    this->testingClassName = "Rectangle";
    this->init();
}

void TestRectangle::testConstructorShapeCount()
{
    this->testInit(__func__);
    Point origin = Point(0, 0);
    double width = 100;
    double height = 100;
    Rectangle rect = Rectangle(origin, width, height);
    if (rect.getShapeCount() != 2) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestRectangle::testConstructorTrianglePoints()
{
    this->testInit(__func__);
    double width = 100;
    double height = 100;
    // Origin anchor point
    Point origin = Point(0, 0);
    // Create three more anchor points
    Point originW = Point(origin.getX() + width, origin.getY());
    Point originH = Point(origin.getX(), origin.getY() + height);
    Point originWH = Point(origin.getX() + width, origin.getY() + height);

    Rectangle rect = Rectangle(origin, width, height);
    
    ShapeTriangle *triangle1 = (ShapeTriangle *)rect.getShapeArray()[0];
    if (triangle1->getPointA1() != origin) {
        this->testFailed();
    }
    if (triangle1->getPointA2() != originW) {
        this->testFailed();
    }
    if (triangle1->getPointA3() != originH) {
        this->testFailed();
    }
    ShapeTriangle *triangle2 = (ShapeTriangle *)rect.getShapeArray()[1];
    if (triangle2->getPointA1() != originWH) {
        this->testFailed();
    }
    if (triangle2->getPointA2() != originW) {
        this->testFailed();
    }
    if (triangle2->getPointA3() != originH) {
        this->testFailed();
    }

    this->testInterpret();
}