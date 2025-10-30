/********* Include statements *********/

#include "GetPath.hpp"

/**************************************/

/******** Function definitions ********/

// relativePath: e.g., "../test.txt"
std::string getAbsolutePath(const std::string& relativePath)
{
    fs::path sourceDir = fs::path(__FILE__).parent_path(); // source file's directory
    fs::path absPath = fs::absolute(sourceDir / relativePath);

    if (!fs::exists(absPath))
        throw std::runtime_error("File not found: " + absPath.string());

    return absPath.string();
}

/**************************************/
