#ifndef TESTSHAPE_H
#define TESTSHAPE_H

#include "Test.h"

class TestShape : protected Test
{
public:
    TestShape();
    void testConstructor();
    void testPointCount();
    void testPushToPointArray();
    void testPopFromPointArray();
};

#endif
