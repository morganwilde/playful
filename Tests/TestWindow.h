#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "Test.h"

class TestWindow : protected Test
{
public:
    TestWindow();
    void testWindowSingletonCreation();
    void testConstructor();
    void testSetterWidth();
    void testSetterHeight();
    void testSetterTitle();
    void testSetterTitleCString();
    void testSetterDisplayLoop();
    void testSetterGlutArguments();
};

#endif
