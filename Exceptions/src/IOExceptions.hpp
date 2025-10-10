#ifndef IO_EXCEPTIONS_HPP
#define IO_EXCEPTIONS_HPP

/********* Include statements *********/

#include <string>

/**************************************/

/********* Define statements *********/

#define DEFAULT_FILE_NAME   "non_existent.txt"

/**************************************/

/******** Function prototypes *********/

unsigned long printFileContent(const std::string& file_path = DEFAULT_FILE_NAME);

/**************************************/

#endif
