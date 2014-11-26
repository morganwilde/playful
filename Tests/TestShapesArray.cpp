#include "TestShapesArray.h"
#include "../Models/ShapesArray.h"
#include "../Models/ShapeTriangle.h"

TestShapesArray::TestShapesArray()
{
    this->testingClassName = "ShapesArray";
    this->init();
}

void TestShapesArray::testConstructor()
{
    this->testInit(__func__);
    ShapesArray array = ShapesArray();
    if (array.getShapeArray() == NULL) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestShapesArray::testShapeCount()
{
    this->testInit(__func__);
    ShapesArray array = ShapesArray();
    if (array.getShapeCount() != 0) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestShapesArray::testShapeAdd()
{
    this->testInit(__func__);
    // Shapes
    double width = 200;
    double height = 200;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle *triangle = new ShapeTriangle(origin, width, height);
    
    // Array
    ShapesArray array = ShapesArray();
    array.add(triangle);

    // Tests
    if (array.getShapeCount() != 1) {
        this->testFailed();
    } else {
        ShapeTriangle *triangleInArray = (ShapeTriangle *)array.getShapeArray()[0];
        if (*triangleInArray != *triangle) {
            this->testFailed();
        }
    }

    this->testInterpret();
}

void TestShapesArray::testVertexCount()
{
    this->testInit(__func__);
    ShapesArray array = ShapesArray();
    array.getVertexArray();
    if (array.getVertexCount() != 0) {
        this->testFailed();
    }
    // Shapes
    double width = 200;
    double height = 200;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle *triangle = new ShapeTriangle(origin, width, height);
    array.add(triangle);

    array.getVertexArray();
    if (array.getVertexCount() != 9) {
        this->testFailed();
    }

    this->testInterpret();
}

void TestShapesArray::testVertexArray()
{
    this->testInit(__func__);
    ShapesArray array = ShapesArray();
    array.setWindowSize(200, 200);

    // Shapes
    double width = 200/2.0;
    double height = 200/2.0;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle *triangle = new ShapeTriangle(origin, width, height);
    array.add(triangle);

    // Test
    GLfloat *vertices = array.getVertexArray();
    // Origin
    if (vertices[0] != ((origin.getX() / width) - 1)) {
        this->testFailed();
    }
    if (vertices[1] != ((origin.getY() / height) - 1)) {
        this->testFailed();
    }
    if (vertices[2] != origin.getZ()) {
        this->testFailed();
    }
    // Top
    if (vertices[3] != ((top.getX() / width) - 1)) {
        this->testFailed();
    }
    if (vertices[4] != ((top.getY() / height) - 1)) {
        this->testFailed();
    }
    if (vertices[5] != top.getZ()) {
        this->testFailed();
    }
    // Right
    if (vertices[6] != ((right.getX() / width) - 1)) {
        this->testFailed();
    }
    if (vertices[7] != ((right.getY() / height) - 1)) {
        this->testFailed();
    }
    if (vertices[8] != right.getZ()) {
        this->testFailed();
    }

    this->testInterpret();
}
