#ifndef SHAPESARRAY_H
#define SHAPESARRAY_H

#include "Shape.h"
#include "ShapeTriangle.h"
#include <OpenGL/gl.h>
#include <string> 
#include <sstream>

class ShapesArray
{
private:
    // Shapes made out of Points
    int shapeCount;
    Shape **array;
    // Shapes made out of other Shapes
    int compositeCount;
    ShapesArray **compositeArray;
    ShapesArray *parentArray;
    // Vertices derived from shapes and composites arrays
    int vertexCount;
    // Window size
    int width;
    int height;
    Color color;
    bool active;
    // First responder to mouse button down events
    bool respondsToMouseButtonDown;
public:
    ShapesArray();
    ~ShapesArray();
    // Setters
    void setSize(int width, int height);
    void setColor(Color color);
    void setRespondsToMouseButtonDown(bool responds);
    // Getters
    int getWidth();
    int getHeight();
    virtual std::string getShapesArrayType() const;
    int getShapeCount();
    Shape **getShapeArray();
    int getCompositeCount();
    ShapesArray **getCompositeArray();
    GLfloat *getVertexArray();
    GLfloat *getColorArray();
    int getVertexCount();
    Color getColor();
    bool getRespondsToMouseButtonDown();
    // Convenience methods
    ShapesArray *shapeContaining(Point point);
    ShapesArray *compositeResponder();
    void activate();
    void deactivate();
    bool isActive();
    // Array managers
    void add(Shape *shape);
    void add(ShapesArray *shapesArray);
    void remove(Shape *shape);
    void remove(ShapesArray *shapesArray);
    // Position adjustion
    void translateBy(double x, double y);
    // Operators
    friend std::ofstream& operator<<(std::ofstream &stream, const ShapesArray &shapesArray);
};

#endif
