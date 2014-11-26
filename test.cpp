#include "Tests/TestWindow.h"
#include "Tests/TestPoint.h"
#include "Tests/TestShape.h"
#include "Tests/TestShapeTriangle.h"
#include "Tests/TestShapesArray.h"
#include "Tests/TestShapeAnalyser.h"

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
        //testWindow.testSetterGlutArguments();
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
        testShapesArray.testVertexCount();
        testShapesArray.testVertexArray();
    }
    {
        TestShapeAnalyser testShapeAnalyser;
        testShapeAnalyser.testEqualArea();
    }

    return 0;
}
