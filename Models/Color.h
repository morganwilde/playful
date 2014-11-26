#ifndef COLOR_H
#define COLOR_H

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
    // Getters
    double getRed();
    double getGreen();
    double getBlue();
    double getAlpha();
    double *getColorArray();
};

#endif
