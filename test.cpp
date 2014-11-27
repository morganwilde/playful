#include "Tests/TestWindow.h"
#include "Tests/TestPoint.h"
#include "Tests/TestShape.h"
#include "Tests/TestShapeTriangle.h"
#include "Tests/TestShapesArray.h"
#include "Tests/TestRectangle.h"
#include "Tests/TestCircle.h"

int main(int argc, char *argv[])
{
    {
        TestWindow testWindow;
        testWindow.testWindowSingletonCreation();
        testWindow.testConstructor();
        testWindow.testSetterWidth();
        testWindow.testSetterHeight();
        testWindow.testSetterTitle();
        testWindow.testSetterTitleCString();
        testWindow.testSetterDisplayLoop();
    } 
    {
        TestPoint testPoint;
        testPoint.testConstructor();
        testPoint.testSetterX();
        testPoint.testSetterY();
        testPoint.testSetterZ();
        testPoint.testGetterX();
        testPoint.testGetterY();
        testPoint.testGetterZ();
        testPoint.testOperatorEqualEqual();
        testPoint.testOperatorNotEqual();
    }
    {
        TestShape testShape;
        testShape.testConstructor();
        testShape.testPointCount();
        testShape.testPushToPointArray();
        testShape.testPopFromPointArray();
    }
    {
        TestShapeTriangle testShapeTriangle;
        testShapeTriangle.testConstructor();
        testShapeTriangle.testPointCount();
        testShapeTriangle.testPoints();
    }
    {
        TestShapesArray testShapesArray;
        testShapesArray.testConstructor();
        testShapesArray.testShapeCount();
        testShapesArray.testShapeAdd();
        testShapesArray.testShapesArrayAdd();
        testShapesArray.testVertexCount();
        testShapesArray.testVertexArray();
    }
    {
        TestRectangle testRectangle;
        testRectangle.testConstructorShapeCount();
        testRectangle.testConstructorTrianglePoints();
    }
    {
        TestCircle testCircle;
        testCircle.testConstructorShapeCount();
        testCircle.testConstructorShapeCountFive();
        testCircle.testPerimeter();
        testCircle.testSegmentWidth();
    }

    return 0;
}
