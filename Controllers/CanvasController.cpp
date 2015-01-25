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
    // Proportions for screen areas
    double padding = 10;
    double canvasWidthRelative = 0.8;
    double toolsWidthRelative = 1 - canvasWidthRelative;

    double canvasWidth = window.getWidth()*canvasWidthRelative;
    double canvasHeight = window.getHeight();
    double toolsWidth = window.getWidth()*toolsWidthRelative;
    double toolsHeight = window.getHeight();

    // Create area objects
    Rectangle *canvasArea = new Rectangle(Point(0, 0, 0), canvasWidth, canvasHeight);
    Rectangle *toolsArea = new Rectangle(Point(canvasWidth, 0, 0), toolsWidth, toolsHeight);

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