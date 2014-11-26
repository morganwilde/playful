#include "TestShapeTriangle.h"
#include "../Models/ShapeTriangle.h"

TestShapeTriangle::TestShapeTriangle()
{
    this->testingClassName = "ShapeTriangle";
    this->init();
}

void TestShapeTriangle::testConstructor()
{
    this->testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, width, height);
    
    if (triangle.getPointA1() != origin) {
        this->testFailed();
    }
    if (triangle.getPointA2() != top) {
        this->testFailed();
    }
    if (triangle.getPointA3() != right) {
        this->testFailed();
    }

    this->testInterpret();
}

void TestShapeTriangle::testPointCount()
{
    this->testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, width, height);
    // See if the necessary points were added
    if (triangle.getPointCount() != 3) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestShapeTriangle::testPoints()
{
    this->testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, width, height);
    // Test for points (independent of their order)
    bool topFound = false;
    bool originFound = false;
    bool rightFound = false;
    for (int i = 0; i < triangle.getPointCount(); i++) {
        Point p = triangle.getPointArray()[i];
        if (p == top) {
            topFound = true;
        } else if (p == origin) {
            originFound = true;
        } else if (p == right) {
            rightFound = true;
        }
    }
    if (!topFound || !originFound || !rightFound) {
        this->testFailed();
    }
    this->testInterpret();
}

