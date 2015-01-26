#include "CanvasController.h"
#include "ShapesArrayStorageController.h"

CanvasController::CanvasController(int width, int height, std::string title)
    : window(Window::getSingleton(width, height, title))
{
}
CanvasController::~CanvasController()
{
}

// Getters
Rectangle *CanvasController::getCanvasArea()
{
    return canvasArea;
}
Rectangle *CanvasController::getToolsArea()
{
    return toolsArea;
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
    backgroundArea = new Rectangle(Point(0, 0, 0), window.getWidth(), window.getHeight());
    canvasArea = new Rectangle(Point(padding, padding, 0), canvasWidth, canvasHeight);
    toolsArea = new Rectangle(Point(canvasWidth + 2*padding, padding, 0), toolsWidth, toolsHeight);

    // Responders
    canvasArea->setRespondsToMouseButtonDown(false);

    // Color them
    backgroundArea->setColor(Color::grayColor().withHue(0.75));
    canvasArea->setColor(Color::whiteColor());
    toolsArea->setColor(Color::whiteColor().withAlpha(0.5));

    // Add to hierarchy
    appendShape(backgroundArea);
    appendShape(canvasArea);
    appendShape(toolsArea);
}

void CanvasController::appendShape(ShapesArray *shape)
{
    window.shapesArray.add(shape);
}

void CanvasController::saveToStorage(std::string storageName)
{
    ShapesArrayStorageController storage = ShapesArrayStorageController(storageName);
    storage.clear();
    storage.store(&window.shapesArray);
}

void CanvasController::loadFromStorage(std::string storageName)
{
    ShapesArrayStorageController storage = ShapesArrayStorageController(storageName);
    storage.loadInto(&window.shapesArray);
}