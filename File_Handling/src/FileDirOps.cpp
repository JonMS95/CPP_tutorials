/********* Include statements *********/

#include <iostream>
#include <filesystem>
#include <fstream>
#include "FileDirOps.hpp"

/**************************************/

/********* Define statements **********/

/**************************************/

/******** Function definitions *********/

// Many operations can be used with filesystem modeule. See the examples below.

void listFiles(const std::string& directory)
{
    std::cout << "Listing files within " << directory << std::endl;

    try
    {
        for(const auto& entry : std::filesystem::directory_iterator(directory))
            std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << std::endl;
    }
    catch(const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void fileOperations(const std::string& src, const std::string& dst)
{
    try
    {
        std::filesystem::path source(src);
        
        std::filesystem::path src_full_path(std::filesystem::absolute(source).parent_path().parent_path() / source.filename().string());
        std::filesystem::path dst_full_path(std::filesystem::absolute(source).parent_path().parent_path() / dst);
        std::cout << dst_full_path.string() << std::endl;
        
        // Make sure that destination file exists.
        std::ofstream ofs(dst_full_path);
        ofs.close();

        std::cout << "Copying from: " << src_full_path << " to: " << dst_full_path << "." << std::endl;
        std::filesystem::copy(src_full_path, dst_full_path, std::filesystem::copy_options::overwrite_existing);

        // Create a renamed path in the same directory as destination
        std::filesystem::path renamed = dst_full_path.parent_path() / "renamed_file.txt";
        std::filesystem::rename(dst_full_path, renamed);

        std::cout << "Renamed file to \"" << renamed.string() << "\"." << std::endl;
        std::cout << "Exists? " << std::boolalpha << std::filesystem::exists(renamed) << std::endl;

        std::filesystem::remove(renamed);
        std::cout << "Removed \"" << renamed.string() << "\"." << std::endl;
    }
    catch(const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    }
}


void showPathInfo(const std::string& relative_path)
{
    try
    {
        std::filesystem::path p = relative_path;
        
        std::cout << "Relative path: " << p << std::endl;
        std::cout << "Absolute path: " << std::filesystem::absolute(p) << std::endl;
        std::cout << "Filename: " << p.filename() << std::endl;
        std::cout << "Extension: " << p.extension() << std::endl;
        std::cout << "Parent path: " << p.parent_path() << std::endl;
    }
    catch(const std::filesystem::filesystem_error e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

/**************************************/
