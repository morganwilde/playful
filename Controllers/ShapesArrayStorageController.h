#ifndef SHAPESARRAYSTORAGECONTROLLER_H
#define SHAPESARRAYSTORAGECONTROLLER_H

#include <string>
#include "../Models/ShapesArray.h"

class ShapesArrayStorageController
{
private:
    std::string name;
    static int shapeID;
public:
    ShapesArrayStorageController(std::string storageName);
    ~ShapesArrayStorageController();
    void clear();
    void store(ShapesArray *shapesArray);
    void store(ShapesArray *shapesArray, int parentID);
    void loadInto(ShapesArray *shapesArray);
};

#endif