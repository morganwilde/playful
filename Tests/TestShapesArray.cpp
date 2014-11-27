#include "TestShapesArray.h"
#include "../Models/ShapesArray.h"
#include "../Models/ShapeTriangle.h"
#include "../Models/Rectangle.h"

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

void TestShapesArray::testShapesArrayAdd()
{
    this->testInit(__func__);
    // Shapes
    double width = 200;
    double height = 200;
    Point origin = Point(0, 0);

    Rectangle *rect = new Rectangle(origin, width, height);
    
    // Array
    ShapesArray array = ShapesArray();
    array.add(rect);

    // Tests
    if (array.getShapeCount() != 2) {
        this->testFailed();
    }

    this->testInterpret();
}

void TestShapesArray::testShapeRemove()
{
    this->testInit(__func__);
    // Shapes
    double width = 200;
    double height = 200;
    Point origin = Point(0,0,0);
    Point top = Point(0, height, 0);
    Point right = Point(width, 0, 0);

    ShapeTriangle *triangle1 = new ShapeTriangle(origin, top, right);
    ShapeTriangle *triangle2 = new ShapeTriangle(origin, width, height);
    ShapeTriangle *triangle3 = new ShapeTriangle(origin, width + 100, height);

    // Array
    ShapesArray array = ShapesArray();
    array.add(triangle1);
    array.add(triangle2);

    // Tests

    // Simple removal
    array.remove(triangle1);
    if (array.getShapeCount() != 1) {
        this->testFailed();
    }
    // Removing twice
    array.remove(triangle1);
    if (array.getShapeCount() != 1) {
        this->testFailed();
    }
    // Removing shape that's not there
    array.remove(triangle3);
    if (array.getShapeCount() != 1) {
        this->testFailed();
    }
    // Removing last item
    array.remove(triangle2);
    if (array.getShapeCount() != 0) {
        this->testFailed();
    }

    this->testInterpret();
}

void TestShapesArray::testShapesArrayRemove()
{
    this->testInit(__func__);
    // Shapes
    double width = 200;
    double height = 200;
    Point origin = Point(0, 0);

    Rectangle *rect = new Rectangle(origin, width, height);
    
    // Array
    ShapesArray array = ShapesArray();
    array.add(rect);

    // Tests
    array.remove(rect);
    if (array.getShapeCount() != 0) {
        this->testFailed();
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
    array.setSize(200, 200);

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
