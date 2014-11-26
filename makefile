CC = g++
FLAG_DEBUG = -DDEBUG
CFLAGS = -Wno-deprecated-declarations
LFLAGS = -framework GLUT -framework OpenGL -framework Cocoa \
-I/usr/local/include -I/opt/X11/include -I/opt/X11/lib

PARTS = Controllers/Window.cpp \
Models/Point.cpp \
Models/Shape.cpp \
Models/ShapeTriangle.cpp \
Models/ShapeRectangle.cpp \
Models/ShapesArray.cpp \
Models/ShapeAnalyser.cpp \
Models/Color.cpp \
Controllers/Logger.cpp

TESTS = Tests/Test.cpp \
Tests/TestWindow.cpp \
Tests/TestPoint.cpp \
Tests/TestShape.cpp \
Tests/TestShapeTriangle.cpp \
Tests/TestShapesArray.cpp \
Tests/TestShapeAnalyser.cpp

all: main.cpp
	$(CC) $(FLAG_DEBUG) $(CFLAGS) $(PARTS) main.cpp -o main $(LFLAGS)
	./main
	rm main

test: test.cpp
	$(CC) $(CFLAGS) $(PARTS) $(TESTS) test.cpp -o test $(LFLAGS)
	./test
	rm test

comp: main.cpp
	$(CC) $(FLAG_DEBUG) $(CFLAGS) $(PARTS) main.cpp -o main $(LFLAGS)