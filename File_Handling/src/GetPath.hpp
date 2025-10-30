#ifndef GET_PATH_HPP
#define GET_PATH_HPP

/********* Include statements *********/

#include <string>
#include <filesystem>

/**************************************/

/********* Function prototypes ********/

namespace fs = std::filesystem;

std::string getAbsolutePath(const std::string& relativePath);

/**************************************/

#endif

