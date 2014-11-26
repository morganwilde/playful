#ifndef TESTSHAPESARRAY_H
#define TESTSHAPESARRAY_H

#include "Test.h"

class TestShapesArray : protected Test
{
public:
    TestShapesArray();
    void testConstructor();
    void testShapeCount();
    void testShapeAdd();
    void testShapesArrayAdd();
    void testVertexCount();
    void testVertexArray();
};

#endif
