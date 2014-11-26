#include "Logger.h"

Logger::Logger(std::string logFilename)
{
    this->logFilename = logFilename;
    this->logFile.open(this->logFilename, std::ios::app);
    this->stream.clear();
}

Logger::~Logger()
{
    this->logFile.close();
}

void Logger::log()
{
    this->logFile << this->stream.str();
    std::cout << this->stream.str();
    this->stream.clear();
}
