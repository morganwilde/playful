#include "TestShape.h"
#include "../Models/Shape.h"
#include "../Models/Point.h"

TestShape::TestShape()
{
    this->testingClassName = "Shape";
    this->init();
}

void TestShape::testConstructor()
{
    this->testInit(__func__);
    Shape shape = Shape();
    if (shape.getPointArray() == NULL) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestShape::testPointCount()
{
    this->testInit(__func__);
    Shape shape = Shape();
    if (shape.getPointCount() != 0) {
        this->testFailed();
    }
    this->testInterpret();
}
void TestShape::testPushToPointArray()
{
    this->testInit(__func__);
    Shape shape = Shape();
    Point *points = new Point[2];
    points[0] = Point(1,2,3);
    points[1] = Point(-1.2,-3.4,-5.6);

    shape.pushToPointArray(points[0]);
    shape.pushToPointArray(points[1]);
    if (shape.getPointCount() != 2) {
        this->testFailed();
    }
    for (int i = 0; i < shape.getPointCount(); i++) {
        Point point = shape.getPointArray()[i];
        if (point.getX() != points[i].getX()) {
            this->testFailed();
        }
        if (point.getY() != points[i].getY()) {
            this->testFailed();
        }
        if (point.getZ() != points[i].getZ()) {
            this->testFailed();
        }
    }
    this->testInterpret();
}

void TestShape::testPopFromPointArray()
{
    this->testInit(__func__);
    Shape shape = Shape();
    Point *points = new Point[2];
    points[0] = Point(1,2,3);
    points[1] = Point(-1.2,-3.4,-5.6);
    shape.pushToPointArray(points[0]);
    shape.pushToPointArray(points[1]);

    Point point = shape.popFromPointArray();
    if (shape.getPointCount() != 1) {
        this->testFailed();
    }
    if (point.getX() != points[1].getX()) {
        this->testFailed();
    }
    if (point.getY() != points[1].getY()) {
        this->testFailed();
    }
    if (point.getZ() != points[1].getZ()) {
        this->testFailed();
    }
    this->testInterpret();
}
