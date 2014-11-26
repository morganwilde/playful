#ifndef TESTRECTANGLE_H
#define TESTRECTANGLE_H

#include "Test.h"

class TestRectangle : protected Test
{
public:
    TestRectangle();
    void testConstructorShapeCount();
    void testConstructorTrianglePoints();
};

#endif
