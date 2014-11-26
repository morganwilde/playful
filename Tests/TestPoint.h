#ifndef TESTPOINT_H
#define TESTPOINT_H

#include "Test.h"

class TestPoint : protected Test
{
public:
    TestPoint();
    void testConstructor();
    void testSetterX();
    void testSetterY();
    void testSetterZ();
    void testGetterX();
    void testGetterY();
    void testGetterZ();
    void testOperatorEqualEqual();
    void testOperatorNotEqual();
};

#endif
