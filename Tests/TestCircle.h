#ifndef TESTCIRCLE_H
#define TESTCIRCLE_H

#include "Test.h"

class TestCircle : protected Test
{
public:
    TestCircle();
    void testConstructorShapeCount();
    void testConstructorShapeCountFive();
    void testPerimeter();
    void testSegmentWidth();
};

#endif
