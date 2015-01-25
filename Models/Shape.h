#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"
#include <vector>

class Shape
{
private:
    int pointCount;
    Point *pointArray;
    std::vector<Point> pointVector;
public:
    // Public properties
    Color color;
    // Constructors & destructors
    Shape();
    ~Shape();
    // Getters
    int getPointCount() const;
    Point *getPointArray() const;
    size_t getVectorSize() const;
    std::vector<Point> getPointVector() const;
    // Point array methods
    void pushToPointArray(Point point);
    void pushToPointVector(Point point);
    Point popFromPointArray();
    // Analysis
    bool contains(Point point);
    // Operators
    bool operator==(const Shape &shapeForComparison);
    bool operator!=(const Shape &shapeForComparison);
};

#endif
