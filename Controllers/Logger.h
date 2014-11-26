#include <fstream>
#include <iostream>
#include <sstream>

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
private:
    std::string logFilename;
    bool logDisplay;
    bool coutDisplay;
public:
    Logger(std::string);
    ~Logger();
    std::ostringstream stream;
    std::ofstream logFile;
    void log();
};

#endif
