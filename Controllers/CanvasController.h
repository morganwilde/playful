#ifndef CANVAS_H
#define CANVAS_H

// Dependencies
#include "Window.h"
#include "../Models/Rectangle.h"

class CanvasController
{
private:
    Window &window;
    Rectangle *backgroundArea;
    Rectangle *canvasArea;
    Rectangle *toolsArea;
public:
    CanvasController(int width, int height, std::string title);
    ~CanvasController();
    // Getters
    Rectangle *getCanvasArea();
    Rectangle *getToolsArea();
    // Glut wrapper methods
    void arguments(int *argumentCount, char *argumentValues[]);
    void show();
    // Methods
    void setup();
    // Visual hierarchy
    void appendShape(ShapesArray *shape);
    void saveToStorage(std::string storageName);
    void loadFromStorage(std::string storageName);
};

#endif