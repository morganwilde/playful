#include "TestPoint.h"
#include "../Models/Point.h"

TestPoint::TestPoint()
{
    this->testingClassName = "Point";
    this->init();
}

void TestPoint::testConstructor()
{
    this->testInit(__func__);
    Point point = Point();
    if (point.getX() != 0) {
        this->testFailed();
    }
    if (point.getY() != 0) {
        this->testFailed();
    }
    if (point.getZ() != 0) {
        this->testFailed();
    }

    Point point1 = Point(1.2, 3.4, 5.6);
    if (point1.getX() != 1.2) {
        this->testFailed();
    }
    if (point1.getY() != 3.4) {
        this->testFailed();
    }
    if (point1.getZ() != 5.6) {
        this->testFailed();
    }

    this->testInterpret();
}

void TestPoint::testSetterX()
{
    this->testInit(__func__);
    Point point = Point(1.2, 3.4, 5.6);
    point.setX(-1.2);
    if (point.getX() != -1.2) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testSetterY()
{
    this->testInit(__func__);
    Point point = Point(1.2, 3.4, 5.6);
    point.setY(-3.4);
    if (point.getY() != -3.4) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testSetterZ()
{
    this->testInit(__func__);
    Point point = Point(1.2, 3.4, 5.6);
    point.setZ(-5.6);
    if (point.getZ() != -5.6) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testGetterX()
{
    this->testInit(__func__);
    Point point = Point(5.6, 4.3, 1.2);
    if (point.getX() != 5.6) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testGetterY()
{
    this->testInit(__func__);
    Point point = Point(5.6, 4.3, 1.2);
    if (point.getY() != 4.3) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testGetterZ()
{
    this->testInit(__func__);
    Point point = Point(5.6, 4.3, 1.2);
    if (point.getZ() != 1.2) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testOperatorEqualEqual()
{
    this->testInit(__func__);
    Point a = Point(1, 2, 3);
    Point b = Point(1, 2, 3);
    Point c = Point(2, 2, 3);
    if (!(a == b)) {
        this->testFailed();
    }
    if (a == c) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestPoint::testOperatorNotEqual()
{
    this->testInit(__func__);
    Point a = Point(1, 2, 3);
    Point b = Point(1, 2, 3);
    Point c = Point(2, 2, 3);
    if (a != b) {
        this->testFailed();
    }
    if (!(a != c)) {
        this->testFailed();
    }
    this->testInterpret();
}
