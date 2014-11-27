#include "TestCircle.h"
#include "../Models/Circle.h"

TestCircle::TestCircle()
{
    this->testingClassName = "Circle";
    this->init();
}

void TestCircle::testConstructorShapeCount()
{
    this->testInit(__func__);
    Point origin = Point(100, 100);
    double radius = 100;
    Circle circle = Circle(origin, radius);
    if (circle.getShapeCount() != 1) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestCircle::testConstructorShapeCountFive()
{
    this->testInit(__func__);
    Point origin = Point(100, 100);
    double radius = 100;
    Circle circle = Circle(origin, radius, 5);
    if (circle.getShapeCount() != 5) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestCircle::testPerimeter()
{
    this->testInit(__func__);
    Point origin = Point(100, 100);
    double radius = 100;
    Circle circle = Circle(origin, radius);
    if (circle.getPerimeter() != (2 * M_PI * circle.getRadius())) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestCircle::testSegmentWidth()
{
    this->testInit(__func__);
    Point origin = Point(100, 100);
    double radius = 100;
    int segments = 1;
    Circle circle = Circle(origin, radius);
    double perimeter = 2 * M_PI * circle.getRadius();
    double segmentWidth = perimeter / segments;
    if (circle.getSegmentWidth() != segmentWidth) {
        this->testFailed();
    }
    int segments2 = 5;
    Circle circle2 = Circle(origin, radius, segments2);
    double perimeter2 = 2 * M_PI * circle2.getRadius();
    double segmentWidth2 = perimeter2 / segments2;
    if (circle2.getSegmentWidth() != segmentWidth2) {
        this->testFailed();
    }
    this->testInterpret();
}