#ifndef CANVAS_H
#define CANVAS_H

// Dependencies
#include "Window.h"
#include "../Models/Rectangle.h"

class CanvasController
{
private:
    Window &window;
public:
    CanvasController(int width, int height, std::string title);
    ~CanvasController();
    // Glut wrapper methods
    void arguments(int *argumentCount, char *argumentValues[]);
    void show();
    // Methods
    void setup();
    // Visual hierarchy
    void appendShape(ShapesArray *shape);
};

#endif