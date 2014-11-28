#ifndef WINDOW_H
#define WINDOW_H

#include <string>
// Mac OpenGL libraries
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
// Models
#include "../Models/ShapesArray.h"
#include "../Models/Shape.h"

class Window
{
private:
    // These methods are private to hide constructor and copy functionality
    Window();
    void operator=(Window const &windowRight);
    Window(Window const &windowCopy);

    // Hide implementation details
    class Implementation;
    Implementation *implementation;

public:
    ~Window();
    static Window &getSingleton();
    static Window &getSingleton(int width, int height, std::string title);
    // Public properties
    ShapesArray shapesArray;
    // Setters
    void setWidth(int width);
    void setHeight(int height);
    void setTitle(std::string title);
    void setDisplayLoopActive(bool isActive);
    void setActiveShape(ShapesArray *shape);
    void setMouseButtonState(int state);
    void setMousePosition(Point position);
    // Getters
    int getWidth();
    int getHeight();
    std::string getTitle();
    char *getTitleCString();
    bool isDisplayLoopActive();
    ShapesArray *getActiveShape();
    int getMouseButtonState();
    Point getMousePosition();
    // Getters glut related
    GLuint getGlutProgram();
    GLint getGlutCoordinateAttribute();
    GLint getGlutColorAttribute();

    // Glut wrapper methods
    void glutInitWrapper(int *glutArgcp, char *glutArgv[]);
    void glutDisplayFrame();
    void glutDisplayLoop();
};

void windowDisplay();
void windowKeyboardSpecial(int key, int x, int y);
void windowKeyboard(unsigned char key, int x, int y);
void windowMouseMove(int x, int y);
void windowMouseButton(int button, int state, int x, int y);
void windowMouseDownMove(int x, int y);

#endif
