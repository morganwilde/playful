#include "ShapesArray.h"

ShapesArray::ShapesArray()
{
    this->shapeCount = 0;
    this->array = (Shape **)malloc(this->shapeCount * sizeof(Shape *));
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

int ShapesArray::getShapeCount()
{
    return this->shapeCount;
}

Shape **ShapesArray::getShapeArray()
{
    return this->array;
}

GLfloat *ShapesArray::getVertexArray()
{
    int count = 0;
    GLfloat *vertexArray = (GLfloat *)malloc(count * sizeof(GLfloat));

    for (int i = 0; i < this->getShapeCount(); i++) {
        Shape *shape = this->getShapeArray()[i];
        Point *points = shape->getPointArray();
        for (int j = 0; j < shape->getPointCount(); j++) {
            Point point = points[j];
            //std::cout << point << std::endl;
            count += 3;
            // Translate values
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
    /*
    for (int i = 0; i < count; i++) {
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

    for (int i = 0; i < this->getShapeCount(); i++) {
        Shape *shape = this->getShapeArray()[i];
        Point *points = shape->getPointArray();
        for (int j = 0; j < shape->getPointCount(); j++) {
            count += 4;
            colorArray = (GLfloat *)realloc(colorArray, count * sizeof(GLfloat));
            colorArray[count - 4] = (GLfloat)shape->color.getRed();
            colorArray[count - 3] = (GLfloat)shape->color.getGreen();
            colorArray[count - 2] = (GLfloat)shape->color.getBlue();
            colorArray[count - 1] = (GLfloat)shape->color.getAlpha();
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

Shape *ShapesArray::shapeContaining(Point point)
{
    Shape *shape = nullptr;

    for (int i = 0; i < this->shapeCount; i++) {
        Shape *tester = this->getShapeArray()[0];
        if (tester->contains(point)) {
            shape = tester;
        }
    }

    return shape;
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
    for (int i = 0; i < shapesArray->getShapeCount(); i++) {
        add(shapesArray->getShapeArray()[i]);
    }
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
    for (int i = 0; i < shapesArray->getShapeCount(); i++) {
        remove(shapesArray->getShapeArray()[i]);
    }
}