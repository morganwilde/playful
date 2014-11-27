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

void TestShapeTriangle::testMatrix()
{
    this->testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(123,456,0);
    Point top = Point(333, height, 0);
    Point right = Point(width, 333, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, top, right);

    // Tests
    double a11 = origin.getX() - right.getX();
    double a12 = top.getX() - right.getX();
    double a21 = origin.getY() - right.getY();
    double a22 = top.getY() - right.getY();
    if (a11 != triangle.getMatrix()[0]) {
        this->testFailed();
    }
    if (a12 != triangle.getMatrix()[1]) {
        this->testFailed();
    }
    if (a21 != triangle.getMatrix()[3]) {
        this->testFailed();
    }
    if (a22 != triangle.getMatrix()[4]) {
        this->testFailed();
    }

    this->testInterpret();
}

void TestShapeTriangle::testDeterminant2D()
{
    testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(123,456,0);
    Point top = Point(333, height, 0);
    Point right = Point(width, 333, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, top, right);

    // Tests
    double a11 = origin.getX() - right.getX();
    double a12 = top.getX() - right.getX();
    double a21 = origin.getY() - right.getY();
    double a22 = top.getY() - right.getY();
    double determinant2D = (a11 * a22) - (a12 * a21);
    if (determinant2D != triangle.getDeterminant2D()) {
        testFailed();
    }
    
    testInterpret();
}

void TestShapeTriangle::testDeterminant3D()
{
    testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(123,456,0);
    Point top = Point(333, height, 0);
    Point right = Point(width, 333, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, top, right);

    // Tests
    double a11 = origin.getX() - right.getX();
    double a12 = top.getX() - right.getX();
    double a21 = origin.getY() - right.getY();
    double a22 = top.getY() - right.getY();
    double determinant3D = 0;
    if (determinant3D != triangle.getDeterminant3D()) {
        testFailed();
    }
    testInterpret();
}

void TestShapeTriangle::test2DPointContained()
{
    testInit(__func__);
    double width = 200;
    double height = 200;
    Point origin = Point(100,100,0);
    Point top = Point(100, height, 0);
    Point right = Point(width, 100, 0);

    ShapeTriangle triangle = ShapeTriangle(origin, top, right);

    // Tests
    // See if all vertices are contained
    if (!triangle.pointContained(origin)) {
        testFailed();
    }
    if (!triangle.pointContained(top)) {
        testFailed();
    }
    if (!triangle.pointContained(right)) {
        testFailed();
    }
    // Test point inside
    Point inside = Point(120, 120);
    if (!triangle.pointContained(inside)) {
        testFailed();
    }
    // Point outside
    Point outside = Point(99, 99);
    if (triangle.pointContained(outside)) {
        testFailed();
    }
    
    testInterpret();
}