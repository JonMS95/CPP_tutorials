#ifndef FILE_DIR_OPS_HPP
#define FILE_DIR_OPS_HPP

/********* Include statements *********/

#include <string>

/**************************************/

/******** Function prototypes *********/

void listFiles(const std::string& directory);
void fileOperations(const std::string& src, const std::string& dst);
void showPathInfo(const std::string& relative_path);

/**************************************/

#endif
