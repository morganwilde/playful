#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"

class Shape
{
private:
    int pointCount;
    Point *pointArray;
public:
    // Public properties
    Color color;
    // Constructors & destructors
    Shape();
    ~Shape();
    // Getters
    int getPointCount() const;
    Point *getPointArray() const;
    // Point array methods
    void pushToPointArray(Point point);
    Point popFromPointArray();
    // Analysis
    bool contains(Point point);
    // Operators
    bool operator==(const Shape &shapeForComparison);
    bool operator!=(const Shape &shapeForComparison);
};

#endif
