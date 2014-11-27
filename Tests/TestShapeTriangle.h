#ifndef TESTSHAPETRIANGLE_H
#define TESTSHAPETRIANGLE_H

#include "Test.h"

class TestShapeTriangle : protected Test
{
public:
    TestShapeTriangle();
    void testConstructor();
    void testPointCount();
    void testPoints();
    void testMatrix();
    void testDeterminant2D();
    void testDeterminant3D();
};

#endif
