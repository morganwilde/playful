#include "TestWindow.h"
#include "../Controllers/Window.h"

TestWindow::TestWindow()
{
    this->testingClassName = "Window";
    this->init();
}

void TestWindow::testWindowSingletonCreation()
{
    this->testInit(__func__);
    Window &window1 = Window::getSingleton();
    Window &window2 = Window::getSingleton();
    if (&window1 != &window2) {
        this->testFailed();
    }
    this->testInterpret();
}
void TestWindow::testConstructor()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton(100, 200, "Test");
    if (window.getWidth() != 100) {
        this->testFailed();
    }
    if (window.getHeight() != 200) {
        this->testFailed();
    }
    if (window.getTitle() != "Test") {
        this->testFailed();
    }
    this->testInterpret();
}

void TestWindow::testSetterWidth()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton();
    window.setWidth(111);
    if (window.getWidth() != 111) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestWindow::testSetterHeight()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton();
    window.setHeight(111);
    if (window.getHeight() != 111) {
        this->testFailed();
    }
    this->testInterpret();
}

void TestWindow::testSetterTitle()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton();
    window.setTitle("New Title!");
    if (window.getTitle() != "New Title!") {
        this->testFailed();
    }
    this->testInterpret();
}

void TestWindow::testSetterTitleCString()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton();
    const char title[] = "New Title!";
    window.setTitle(title);
    int length = window.getTitle().length();
    char *titleCString = window.getTitleCString();
    for (int i = 0; i < length; i++) {
        if (titleCString[i] != title[i]) {
            this->testFailed();
        }
    }
    this->testInterpret();
}
void TestWindow::testSetterDisplayLoop()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton();
    window.setDisplayLoopActive(false);
    if (window.isDisplayLoopActive() != false) {
        this->testFailed();
    }
    window.setDisplayLoopActive(true);
    if (window.isDisplayLoopActive() != true) {
        this->testFailed();
    }
    this->testInterpret();
}
/*
void TestWindow::testSetterGlutArguments()
{
    this->testInit(__func__);
    Window &window = Window::getSingleton();

    // Setup the data for testing
    int argc = 1;
    std::string argument1 = "./main";
    char **argv = (char **)malloc(sizeof(char) * argc);
    argv[0] = (char *)malloc(sizeof(char) * argument1.length());
    for (int i = 0; i < argument1.length(); i++) {
        argv[0][i] = argument1[i];
    }

    // Do the test
    window.setGlutArguments(&argc, argv);
    int *glutArgcp = window.getGlutArgumentsArgcp();
    char **glutArgv = window.getGlutArgumentsArgv();
    if (*glutArgcp != argc) {
        this->testFailed();
    }
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < argument1.length(); j++) {
            if (glutArgv[i][j] != argv[i][j]) {
                this->testFailed();
            }
        }
    }

    this->testInterpret();
}
*/
