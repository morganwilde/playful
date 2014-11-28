#include "ShapesArray.h"

ShapesArray::ShapesArray()
{
    setSespondsToMouseButtonDown(false);
    deactivate();
    this->shapeCount = 0;
    this->array = (Shape **)malloc(this->shapeCount * sizeof(Shape *));
    this->compositeCount = 0;
    this->compositeArray = (ShapesArray **)malloc(this->compositeCount * sizeof(ShapesArray *));
}

ShapesArray::~ShapesArray()
{
    try {
        for (int i = 0; i < this->shapeCount; i++) {
            free(this->array[i]);
        }
        free(this->array);
        this->array = NULL;
    } catch(...) {
        std::cout << "Trying to free ShapesArray failed!" << std::endl;
    }
}

void ShapesArray::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
}
void ShapesArray::setColor(Color color)
{
    this->color = color;
    for (int i = 0; i < getShapeCount(); i++) {
        getShapeArray()[i]->color = getColor();
    }
    
}
void ShapesArray::setSespondsToMouseButtonDown(bool responds)
{
    this->respondsToMouseButtonDown = responds;
}

// Getters
int ShapesArray::getWidth()
{
    return this->width;
}
int ShapesArray::getHeight()
{
    return this->height;
}

int ShapesArray::getShapeCount()
{
    return this->shapeCount;
}

int ShapesArray::getCompositeCount()
{
    return this->compositeCount;
}

Shape **ShapesArray::getShapeArray()
{
    return this->array;
}

ShapesArray **ShapesArray::getCompositeArray()
{
    return this->compositeArray;
}

GLfloat *ShapesArray::getVertexArray()
{
    int count = 0;
    GLfloat *vertexArray = (GLfloat *)malloc(count * sizeof(GLfloat));

    // Draw from Shape array

    for (int i = 0; i < this->getShapeCount(); i++) {
        Shape *shape = this->getShapeArray()[i];
        Point *points = shape->getPointArray();
        for (int j = 0; j < shape->getPointCount(); j++) {
            Point point = points[j];
            count += 3;
            // Translate values
            //std::cout << point << std::endl;
            GLfloat x = (GLfloat)(point.getX() / (this->width/2.0)) - 1;
            GLfloat y = (GLfloat)(point.getY() / (this->height/2.0)) - 1;
            GLfloat z = (GLfloat)(point.getZ());
            vertexArray = (GLfloat *)realloc(vertexArray, count * sizeof(GLfloat));
            vertexArray[count - 3] = x;
            vertexArray[count - 2] = y;
            vertexArray[count - 1] = z;
        }
    }

    this->vertexCount = count;

    // Draw from Composite array

    for (int i = 0; i < this->getCompositeCount(); i++) {
        ShapesArray *composite = this->getCompositeArray()[i];
        GLfloat *vertexSubArray = composite->getVertexArray();
        int vertexSubArrayCount = composite->getVertexCount();

        // Append these vertices to the primary array
        int countFrom = this->vertexCount;
        this->vertexCount += vertexSubArrayCount;
        vertexArray = (GLfloat *)realloc(vertexArray, this->vertexCount * sizeof(GLfloat));
        for (int v = 0; v < vertexSubArrayCount; v++) {
            vertexArray[countFrom + v] = vertexSubArray[v];
        }
    }

    /*
    for (int i = 0; i < this->vertexCount; i++) {
        std::cout << vertexArray[i] << ",";
    }
    std::cout << std::endl;
    */

    return vertexArray;
}

GLfloat *ShapesArray::getColorArray()
{
    int count = 0;
    GLfloat *colorArray = (GLfloat *)malloc(count * sizeof(GLfloat));

    // Color from Shape array

    for (int i = 0; i < this->getShapeCount(); i++) {
        Shape *shape = this->getShapeArray()[i];
        Point *points = shape->getPointArray();
        for (int j = 0; j < shape->getPointCount(); j++) {
            count += 4;
            //std::cout << shape->color << std::endl;

            Color chosenColor;
            if (isActive()) {
                chosenColor = Color(1, 0, 1, 1);
            } else {
                chosenColor = shape->color;
            }

            colorArray = (GLfloat *)realloc(colorArray, count * sizeof(GLfloat));
            colorArray[count - 4] = (GLfloat)chosenColor.getRed();
            colorArray[count - 3] = (GLfloat)chosenColor.getGreen();
            colorArray[count - 2] = (GLfloat)chosenColor.getBlue();
            colorArray[count - 1] = (GLfloat)chosenColor.getAlpha();
        }
    }

    // Color from Composite array

    for (int i = 0; i < this->getCompositeCount(); i++) {
        ShapesArray *composite = this->getCompositeArray()[i];
        GLfloat *colorSubArray = composite->getColorArray();
        int colorSubArrayCount = (composite->getVertexCount() / 3) * 4;

        // Append these colors to the primary array
        int countFrom = count;
        count += colorSubArrayCount;
        colorArray = (GLfloat *)realloc(colorArray, count * sizeof(GLfloat));
        for (int c = 0; c < colorSubArrayCount; c++) {
            colorArray[countFrom + c] = colorSubArray[c];
        }
    }

    return colorArray;
}

int ShapesArray::getVertexCount()
{
    return this->vertexCount;
}

Color ShapesArray::getColor()
{
    return this->color;
}

bool ShapesArray::getRespondsToMouseButtonDown()
{
    return this->respondsToMouseButtonDown;
}

ShapeTriangle *ShapesArray::shapeContaining(Point point)
{
    ShapeTriangle *triangle = nullptr;

    for (int i = 0; i < this->getCompositeCount(); i++) {
        ShapeTriangle *tester = this->getCompositeArray()[i]->shapeContaining(point);
        if (tester != nullptr) {
            triangle = tester;
        }
    }

    if (triangle == nullptr) {
        for (int i = 0; i < this->shapeCount; i++) {
            ShapeTriangle *tester = (ShapeTriangle *)this->getShapeArray()[i];
            if (tester->pointContained(point)) {
                triangle = tester;
            }
        }
    }

    return triangle;
}

ShapesArray *ShapesArray::compositeResponder(ShapeTriangle *triangle)
{
    ShapesArray *composite = nullptr;
    for (int i = 0; i < this->getCompositeCount(); i++) {
        ShapesArray *tester = this->getCompositeArray()[i];
        for (int s = 0; s < tester->getShapeCount(); s++) {
            if (tester->getShapeArray()[s] == triangle) {
                if (tester->getRespondsToMouseButtonDown()) {
                    composite = tester;
                }
            }
        }
    }

    return composite;
}

void ShapesArray::activate()
{
    this->active = true;
}
void ShapesArray::deactivate()
{
    this->active = false;
}
bool ShapesArray::isActive()
{
    return this->active;
}

// Array managers
void ShapesArray::add(Shape *shape)
{
    this->shapeCount++;
    this->array = (Shape **)realloc(this->array, this->shapeCount * sizeof(Shape *));
    this->array[this->shapeCount - 1] = shape;
}
void ShapesArray::add(ShapesArray *shapesArray)
{
    shapesArray->setSize(this->width, this->height);
    // Update shapesArray
    this->compositeCount++;
    this->compositeArray = (ShapesArray **)realloc(this->compositeArray, this->compositeCount * sizeof(ShapesArray *));
    this->compositeArray[this->compositeCount - 1] = shapesArray;
}
void ShapesArray::remove(Shape *shape)
{
    int shapeIndex = 0;
    bool shapeFound = false;
    // Search for it
    for (int i = 0; i < getShapeCount(); i++) {
        Shape *shapeInArray = getShapeArray()[i];
        if (shapeInArray == shape) {
            shapeFound = true;
            shapeIndex = i;
        }
    }
    // If found
    if (shapeFound) {
        // If found, shift the array left
        for (int i = shapeIndex; i < getShapeCount(); i++) {
            this->array[i] = this->array[i + 1];
        }
        // Adjust array capacity
        this->shapeCount--;
        this->array = (Shape **)realloc(this->array, this->shapeCount * sizeof(Shape *));
        // Free the shape
        free(shape);
    }
}
void ShapesArray::remove(ShapesArray *shapesArray)
{
    bool compositeFound = false;
    int compositeIndex = 0;
    // Search for it
    for (int i = 0; i < getCompositeCount(); i++) {
        ShapesArray *compositeInArray = getCompositeArray()[i];
        if (compositeInArray == shapesArray) {
            compositeFound = true;
            compositeIndex = i;
        }
    }
    // If found
    if (compositeFound) {
        // Shift the array left
        for (int i = compositeIndex; i < getCompositeCount(); i++) {
            this->compositeArray[i] = this->compositeArray[i + 1];
        }
        // Adjust array capacity
        this->compositeCount--;
        this->compositeArray = (ShapesArray **)realloc(this->compositeArray, this->compositeCount * sizeof(ShapesArray *));
        free(shapesArray);
    }
}