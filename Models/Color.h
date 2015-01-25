#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color
{
private:
    double red;
    double green;
    double blue;
    double alpha;
    double colorArray[4];
public:
    Color();
    Color(double red, double green, double blue, double alpha);
    ~Color();
    // Setters
    void setRed(double red);
    void setGreen(double green);
    void setBlue(double blue);
    void setAlpha(double alpha);
    // Functional setters
    Color withAlpha(double alpha);
    Color withHue(double hue);
    // Getters
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    double getAlpha() const;
    double *getColorArray();
    // Operators
    friend std::ostream& operator<<(std::ostream &stream, const Color &color);
    // Class methods
    static Color redColor();
    static Color greenColor();
    static Color blueColor();
    static Color whiteColor();
    static Color grayColor();
    static Color blackColor();
};

#endif
