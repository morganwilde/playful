#include "Window.h"
#include "Logger.h"
#include <unistd.h>

/*
 * Hidden implementation [start]
 */

class Window::Implementation {
    friend class Window;
    // Properties
    int width;
    int height;
    std::string title;
    char *titleCString;
    Shape *activeShape;

    // Glut related properties
    bool glutInitialised;
    int *glutArgcp;
    char **glutArgv;
    GLuint glutProgram;
    GLint glutCoordinateAttribute;
    GLint glutColorAttribute;

    // Flags
    bool displayLoopActive;

    // Setters glut related
    void setGlutArguments(int *glutArgcp, char **glutArgv);
    void setGlutCoordinateAttribute(const char *name);
    void setGlutColorAttribute(const char *name);

    // Getters glut related
    int *getGlutArgumentsArgcp();
    char **getGlutArgumentsArgv();
};

// Setters glut related
void Window::Implementation::setGlutArguments(int *glutArgcp, char **glutArgv)
{
    this->glutArgcp = glutArgcp;
    this->glutArgv  = glutArgv;
}
void Window::Implementation::setGlutCoordinateAttribute(const char *name)
{
    this->glutCoordinateAttribute = glGetAttribLocation(this->glutProgram, name);
}
void Window::Implementation::setGlutColorAttribute(const char *name)
{
    this->glutColorAttribute = glGetAttribLocation(this->glutProgram, name);
}

// Getters glut related
int *Window::Implementation::getGlutArgumentsArgcp()
{
    return this->glutArgcp;
}
char **Window::Implementation::getGlutArgumentsArgv()
{
    return this->glutArgv;
}

/*
 * Hidden implementation [end]
 */

Window::Window() : implementation(new Window::Implementation())
{
    // Bare constructor
    #ifdef DEBUG
    Logger logger("log.out");
    logger.stream << "Window created   -> " << this << std::endl;
    logger.log();
    #endif
}

Window::Window(Window const &windowCopy)
{
    // Copy constructor
    #ifdef DEBUG
    Logger logger("log.out");
    logger.stream << "Window copied    -> " << this << " <- from " << &windowCopy << std::endl;
    logger.log();
    #endif
}

void Window::operator=(Window const &windowRight)
{
    // Assignment constructor
    #ifdef DEBUG
    Logger logger("log.out");
    logger.stream << "Window assigned  -> " << this << " <- from " << &windowRight << std::endl;
    logger.log();
    #endif
}

Window::~Window()
{
    #ifdef DEBUG
    Logger logger("log.out");
    logger.stream << "Window destroyed -> " << this << std::endl;
    logger.log();
    #endif
    // Clean up
    free(this->getTitleCString());
    delete implementation;
}

// Singleton creator/getter
Window &Window::getSingleton()
{
    static Window singleton;
    return singleton;
}

Window &Window::getSingleton(int width, int height, std::string title)
{
    Window &window = Window::getSingleton();
    
    window.setWidth(width);
    window.setHeight(height);
    window.setTitle(title);

    return window;
}

// Setters
void Window::setWidth(int width)
{
    this->implementation->width = width;
    this->shapesArray.setSize(this->getWidth(), this->getHeight());
}
void Window::setHeight(int height)
{
    this->implementation->height = height;
    this->shapesArray.setSize(this->getWidth(), this->getHeight());
}
void Window::setTitle(std::string title)
{
    // C++ string title
    this->implementation->title = title;
    // C string title
    const char *temp = title.c_str();
    const int size = title.size() + 1;
    // allocate room for it
    if (!this->implementation->titleCString) {
        this->implementation->titleCString = (char *)malloc(sizeof(char) * size);
    } else {
        this->implementation->titleCString = (char *)realloc(this->implementation->titleCString, sizeof(char) * size);
    }
    // copy char by char
    for (int i = 0; i < size; i++) {
        this->implementation->titleCString[i] = temp[i];
    }
}
void Window::setDisplayLoopActive(bool isActive)
{
    this->implementation->displayLoopActive = isActive;
}


// Getters
int Window::getWidth()
{
    return this->implementation->width;
}
int Window::getHeight()
{
    return this->implementation->height;
}
std::string Window::getTitle()
{
    return this->implementation->title;
}
char *Window::getTitleCString()
{
    return this->implementation->titleCString;
}
bool Window::isDisplayLoopActive()
{
    return this->implementation->displayLoopActive;
}
// Getters glut related
GLuint Window::getGlutProgram()
{
    return this->implementation->glutProgram;
}
GLint Window::getGlutCoordinateAttribute()
{
    return this->implementation->glutCoordinateAttribute;
}
GLint Window::getGlutColorAttribute()
{
    return this->implementation->glutColorAttribute;
}

// Glut wrapper methods
void Window::glutInitWrapper(int *glutArgcp, char *glutArgv[])
{
    if (!this->implementation->glutInitialised) {
        // Save object state
        this->implementation->setGlutArguments(glutArgcp, glutArgv);
        this->implementation->glutInitialised = true;
        this->setDisplayLoopActive(true);
        
        // Initialise glut
        glutInit(glutArgcp, glutArgv);
        glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
        glutInitWindowSize(this->getWidth(), this->getHeight());
        glutCreateWindow(this->getTitleCString());

        // Assign callback functions
        glutDisplayFunc(windowDisplay);
        glutKeyboardFunc(windowKeyboard);
        glutSpecialFunc(windowKeyboardSpecial);
        glutMouseFunc(windowMouseButton);
        glutMotionFunc(windowMouseDownMove);
        glutPassiveMotionFunc(windowMouseMove);

        // == TEMP ==
        // Initialise resources
        GLint linkError = GL_FALSE;
        this->implementation->glutProgram = glCreateProgram();

        // Shaders
        GLuint vs = glCreateShader(GL_VERTEX_SHADER);
        GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
        // Vertex shader
        const char *vsSource =
            "#version 120\n"
            "attribute vec3 coord3d;\n"
            "attribute vec4 colorrgba;\n"
            "varying vec4 fragmentColor;\n"
            "void main(void) {\n"
            "    gl_Position = vec4(coord3d, 1.0);\n"
            "    fragmentColor = colorrgba;\n"
            "}";
        // Fragment shader
        const char *fsSource =
            "#version 120\n"
            "varying vec4 fragmentColor;\n"
            "void main(void) {\n"
            "    gl_FragColor = fragmentColor;\n"
            "}";

        glShaderSource(vs, 1, &vsSource, NULL);
        glShaderSource(fs, 1, &fsSource, NULL);
        glCompileShader(vs);
        glCompileShader(fs);
        GLint compileError = GL_FALSE;
        glGetShaderiv(vs, GL_COMPILE_STATUS, &compileError);
        //std::cout << "vs: " << vs << " compile: " << compileError << std::endl;
        glGetShaderiv(fs, GL_COMPILE_STATUS, &compileError);
        //std::cout << "fs: " << fs << " compile: " << compileError << std::endl;

        // Link resources
        glAttachShader(this->getGlutProgram(), vs);
        glAttachShader(this->getGlutProgram(), fs);
        glLinkProgram(this->getGlutProgram());
        glGetProgramiv(this->getGlutProgram(), GL_LINK_STATUS, &linkError);
        glGetProgramiv(this->getGlutProgram(), GL_ATTACHED_SHADERS, &linkError);
        //std::cout << "active attributes: " << linkError << std::endl;

        this->implementation->setGlutCoordinateAttribute("coord3d");
        this->implementation->setGlutColorAttribute("colorrgba");
        // /= TEMP ==
    }
}
void Window::glutDisplayFrame()
{
    glutCheckLoop();
}

#include "../Models/Circle.h"

void Window::glutDisplayLoop()
{
    int segmentsFrom = 0;
    int segmentsTo = 100;
    bool forward = true;
    int segments = segmentsFrom;
    while (this->isDisplayLoopActive()) {
        Circle *circle = new Circle(Point(400, 300), 200, segments);
        circle->setColor(Color(0.5, 0.5, 0.5, 1));
        this->shapesArray.add(circle);
    
        this->glutDisplayFrame();

        this->shapesArray.remove(circle);

        if (segments < segmentsTo && forward) {
            segments++;
            if (segments == segmentsTo) {
                forward = !forward;
            }
        } else if (segments > segmentsFrom && !forward) {
            segments--;
            if (segments == segmentsFrom) {
                forward = !forward;
            }
        }
    }
}

// Functions that need to declared outside of the Window object scope
void windowDisplay()
{
    // Clear background to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Use program
    Window &window = Window::getSingleton();
    glUseProgram(window.getGlutProgram());

    // Temp
    glEnableVertexAttribArray(window.getGlutCoordinateAttribute());
    GLfloat *vertexArray = window.shapesArray.getVertexArray();
    int components = 3;
    int points = window.shapesArray.getVertexCount() / components;

    glVertexAttribPointer(
        window.getGlutCoordinateAttribute(),
        components, // TODO change this to a dynamic getter
        GL_FLOAT,
        GL_FALSE,
        0,
        vertexArray
        //vertices
    );
    // /Temp

    // Color
    glEnableVertexAttribArray(window.getGlutColorAttribute());
    GLfloat *colorArray = window.shapesArray.getColorArray();
    int componentsColor = 4;

    glVertexAttribPointer(
        window.getGlutColorAttribute(),
        componentsColor,
        GL_FLOAT,
        GL_FALSE,
        0,
        colorArray
    );
    // /Color
    glDrawArrays(GL_TRIANGLES, 0, points);
    free(vertexArray);
    free(colorArray);
    glDisableVertexAttribArray(window.getGlutColorAttribute());
    glDisableVertexAttribArray(window.getGlutCoordinateAttribute());

    // Display result
    glutSwapBuffers();
    usleep(300000);
    glutPostRedisplay();
}

void windowKeyboard(unsigned char key, int x, int y)
{
    Window &window = Window::getSingleton();

    // Interpret the key
    switch (key) {
        case 27: // Escape
            window.setDisplayLoopActive(false);
            break;
        default: std::cout << (int)key << std::endl;
    }
}

void windowKeyboardSpecial(int key, int x, int y)
{
    Window &window = Window::getSingleton();

    // Interpret the key
    switch (key) {
        default: std::cout << key << std::endl;
    }
}

void windowMouseMove(int x, int y)
{
    //std::cout << x << ", " << y << std::endl;
}

void windowMouseButton(int button, int state, int x, int y)
{
    Window &window = Window::getSingleton();
    Shape *shape = window.shapesArray.shapeContaining(Point(x, y, 0));
    //std::cout << shape << std::endl;
    //std::cout << button << ":" << state << " " << x << ", " << y << std::endl;
}

void windowMouseDownMove(int x, int y)
{
    //std::cout << x << ", " << y << std::endl;
}
