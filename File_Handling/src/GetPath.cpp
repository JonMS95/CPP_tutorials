/********* Include statements *********/

#include "GetPath.hpp"

/**************************************/

/******** Function definitions ********/

std::string getAbsolutePath(const std::string& relativePath)
{
    fs::path current = fs::current_path();
    fs::path targetFile = relativePath;

    // Walk up the directory tree until the file is found or we reach the root
    while (!fs::exists(current / targetFile)) {
        if (current.has_parent_path())
            current = current.parent_path();
        else
            throw std::runtime_error("File not found in any parent directory: " + relativePath);
    }

    fs::path absPath = fs::absolute(current / targetFile);
    return absPath.string();
}

/**************************************/
