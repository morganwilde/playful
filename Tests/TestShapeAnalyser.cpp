#include "TestShapeAnalyser.h"
#include "../Models/ShapeAnalyser.h"
#include "../Models/ShapeRectangle.h"

TestShapeAnalyser::TestShapeAnalyser()
{
    this->testingClassName = "ShapeAnalyser";
    this->init();
}

void TestShapeAnalyser::testEqualArea()
{
    this->testInit(__func__);

    ShapeRectangle rect1(Point(0, 0, 0), 100, 100);
    ShapeRectangle rect2(Point(0, 0, 0), 101, 100);

    ShapeAnalyser analyser;

    /*
    if (analyser.equalArea<ShapeRectangle, ShapeRectangle>(rect1, rect2)) {
    }
    */
    
    this->testInterpret();
}
