#include "ShapesArrayStorageController.h"
#include <iostream>
#include <sstream>
#include <fstream>

int ShapesArrayStorageController::shapeID = 0;

ShapesArrayStorageController::ShapesArrayStorageController(std::string storageName)
    : name(storageName)
{
	ShapesArrayStorageController::shapeID = 0;
}
ShapesArrayStorageController::~ShapesArrayStorageController()
{

}

void ShapesArrayStorageController::clear()
{
	std::ofstream storageFile;
	storageFile.open(name + ".playful");
	storageFile << "";
	storageFile.close();
}

void ShapesArrayStorageController::store(ShapesArray *shapesArray)
{
	store(shapesArray, 1);
}

void ShapesArrayStorageController::store(ShapesArray *shapesArray, int parentID)
{
	std::ofstream storageFile;
	storageFile.open(name + ".playful", std::ios_base::app);

	// Iterate over all composites
    for (int i = 0; i < shapesArray->getCompositeCount(); i++) {
    	ShapesArray *childShapesArray = shapesArray->getCompositeArray()[i];
    	
    	for (int j = 0; j < parentID; j++) {
    		storageFile << "-";
    	}

    	storageFile << " ";
    	storageFile << *childShapesArray;
    	storageFile << std::endl;

    	if (shapesArray->getCompositeCount() > 0) {
    		store(childShapesArray, parentID + 1);
    	}
    }

	// Iterate over all primitives
    for (int i = 0; i < shapesArray->getShapeCount(); i++) {
        ShapeTriangle *triangle = (ShapeTriangle *)shapesArray->getShapeArray()[i];
        //storageFile << "ShapeTriangle" << std::endl;
    }

	storageFile.close();
}

void ShapesArrayStorageController::loadInto(ShapesArray *shapesArray)
{
	std::ifstream storageFile;
	storageFile.open(name + ".playful");

	std::string line;
	std::cout << "Loader" << std::endl;
	int level = 0;
	while (std::getline(storageFile, line)) {
	    std::istringstream iss(line);
	    /*
	    for(char& c : str) {
	    	std::cout << "char" << std::endl;
	    }
	    */
	    std::cout << line << std::endl;
	    /*
	    int a, b;
	    if (!(iss >> a >> b)) { break; } // error
*/
	    // process pair (a,b)
	}

	storageFile.close();
}