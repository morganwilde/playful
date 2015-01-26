#ifndef SHAPESARRAYSTORAGE_H
#define SHAPESARRAYSTORAGE_H

#include <string>

class ShapesArrayStorage
{
private:
    std::string name;
public:
    ShapesArrayStorage(std::string storageName);
    ~ShapesArrayStorage();
};

#endif