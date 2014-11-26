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
};

#endif
