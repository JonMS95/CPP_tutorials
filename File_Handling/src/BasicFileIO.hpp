#ifndef BASIC_FILE_IO_HPP
#define BASIC_FILE_IO_HPP

/********* Include statements *********/

#include <string>

/**************************************/

/******** Function prototypes *********/

void writeToFile(const std::string& filename);
void readFromFile(const std::string& filename);
void appendToFile(const std::string& filename);
void readWriteExample(const std::string& filename);

/**************************************/

#endif
