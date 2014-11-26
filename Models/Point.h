#ifndef POINT_H
#define POINT_H

#include <iostream>

/**
 * Point - a primitive 3D point type. Holds a 3 component vector: x, y, z.
 */
class Point
{
private:
    double x;
    double y;
    double z;
public:
    /**
     * The empty constructor, sets all instance variables to zero.
     */
    Point();
    /**
     * The designated constructor.
     */
    Point(double x, double y, double z);
    /**
     * The convenience constructor for 2D first points.
     */
    Point(double x, double y);
    /**
     * The destructor.
     */
    ~Point();
    // Setters
    /**
     * The x component setter.
     */
    void setX(double x);
    /**
     * The y component setter.
     */
    void setY(double y);
    /**
     * The z component setter.
     */
    void setZ(double z);
    // Getters
    /**
     * The x component getter.
     */
    double getX() const;
    /**
     * The y component getter.
     */
    double getY() const;
    /**
     * The z component getter.
     */
    double getZ() const;
    // Operators
    /**
     * Overloaded == operator, compares two points. They are equal only if their components values are equal.
     */
    bool operator==(const Point &pointForComparison);
    /**
     * Overloaded != operator, compares two points. They are not equal if at least one components value isn't equal.
     */
    bool operator!=(const Point &pointForComparison);
    /**
     * Outputs a string representation of a Point object in the format "Point( x , y , z )".
     */
    friend std::ostream& operator<<(std::ostream &stream, const Point &point);
    /**
     * Inputs a Point object provided in string of the format "Point( x , y , z )".
     */
    friend std::istream& operator>>(std::istream &stream, Point &point);
};

#endif
