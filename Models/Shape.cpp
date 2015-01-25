#include "Shape.h"
#include <cstdlib>

Shape::Shape()
{
    this->pointCount = 0;
    this->pointArray = (Point *)malloc(this->pointCount * sizeof(Point));
}

Shape::~Shape()
{
    try {
        free(this->pointArray);
        this->pointArray = NULL;
    } catch(...) {
        std::cout << "Trying to free Shape failed!" << std::endl;
    }
}

int Shape::getPointCount() const
{
    return this->pointCount;
}

size_t Shape::getVectorSize() const
{
    return getPointVector().size();
}

Point *Shape::getPointArray() const
{
    return this->pointArray;
}

std::vector<Point> Shape::getPointVector() const
{
    return this->pointVector;
}

void Shape::pushToPointArray(Point point)
{
    this->pointCount++;
    this->pointArray = (Point *)realloc(this->pointArray, sizeof(Point) * this->pointCount);
    this->pointArray[this->pointCount - 1] = point;

    pushToPointVector(point);
}

void Shape::pushToPointVector(Point point)
{
    pointVector.push_back(point);
}

Point Shape::popFromPointArray()
{
    Point point = this->pointArray[this->pointCount - 1];
    this->pointCount--;
    this->pointArray = (Point *)realloc(this->pointArray, sizeof(Point) * this->pointCount);
    return point;
}

// Analysis
bool Shape::contains(Point point)
{
    bool containsPoint = false;
    int secondToLastPoint = this->pointCount - 1;
    Point p1;
    Point p2;
    int verticalHits = 0;
    int horizontalHits = 0;

    for (int i = 0; i < secondToLastPoint; i++) {
        // Define a function with this slope and test if the result with one component is greate or smaller than the coordinates of this point
        p1 = this->getPointArray()[i];
        p2 = this->getPointArray()[i + 1];
    }
    return containsPoint;
}

bool Shape::operator==(const Shape &shapeForComparison)
{
    bool equal = true;
    if (this->getPointCount() != shapeForComparison.getPointCount()) {
        equal = false;
    } else {
        for (int i = 0; i < this->getPointCount(); i++) {
            if (this->getPointArray()[i] != shapeForComparison.getPointArray()[i]) {
                equal = false;
            }
        }
    }
    return equal;
}

bool Shape::operator!=(const Shape &shapeForComparison)
{
    return !(*this == shapeForComparison);
}
