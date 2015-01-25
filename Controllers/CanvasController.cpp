#include "CanvasController.h"

CanvasController::CanvasController(int width, int height, std::string title)
    : window(Window::getSingleton(width, height, title))
{
}
CanvasController::~CanvasController()
{
}

void CanvasController::arguments(int *argumentCount, char *argumentValues[])
{
    window.glutInitWrapper(argumentCount, argumentValues);
}

void CanvasController::show()
{
    window.glutDisplayLoop();
}

void CanvasController::setup()
{
    // Padding is between each one of the two areas and the window
    double padding = 10;
    // Proportions for screen areas
    double canvasWidthRelative = 0.8;
    double toolsWidthRelative = 1 - canvasWidthRelative;

    double canvasWidth = window.getWidth()*canvasWidthRelative - 2*padding + padding/2;
    double canvasHeight = window.getHeight() - 2*padding;
    double toolsWidth = window.getWidth()*toolsWidthRelative - 2*padding + padding/2;
    double toolsHeight = window.getHeight() - 2*padding;

    // Create area objects
    Rectangle *canvasArea = new Rectangle(Point(padding, padding, 0), canvasWidth, canvasHeight);
    Rectangle *toolsArea = new Rectangle(Point(canvasWidth + 2*padding, padding, 0), toolsWidth, toolsHeight);

    // Color them
    canvasArea->setColor(Color(1, 0, 0, 1));
    toolsArea->setColor(Color(0, 1, 0, 1));

    // Add to hierarchy
    appendShape(canvasArea);
    appendShape(toolsArea);
}

void CanvasController::appendShape(ShapesArray *shape)
{
    window.shapesArray.add(shape);
}