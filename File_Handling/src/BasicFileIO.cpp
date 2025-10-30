/********* Include statements *********/

#include <iostream>
#include <fstream>
#include "BasicFileIO.hpp"

/**************************************/

/********* Define statements **********/

#define FILE_OPEN_CHECK(file_path)                                          \
do                                                                          \
{                                                                           \
    if(!file_path.is_open())                                                \
    {                                                                       \
        std::cerr << "Error: could not open " << #file_path << std::endl;   \
        return;                                                             \
    }                                                                       \
}while(0)

/**************************************/

/******** Function definitions *********/

// Write/output to a file creating an ofstream type object (in case you wonder, ofstream stands for "output file stream").
// Use << operator to write to the ofstream object in question.

void writeToFile(const std::string& filename)
{
    std::ofstream file(filename);

    FILE_OPEN_CHECK(file);

    file << "Hello, file!\r\n";
    file << "This is a second line\r\n";

    file.close();
    std::cout << "Data written to " << filename << std::endl;
}

// Use ifstream (input file stream) objects to read from a file. Use getline to read line by line.

void readFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    FILE_OPEN_CHECK(file);

    std::string line;

    while(std::getline(file, line))
        std::cout << line << std::endl;

    file.close();
}

// ofstream constructors allows bit flags too. std::ios::app enables file appending so that the file in question is not
// overwritten as it happens when using writeToFile function defined above.

void appendToFile(const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);

    FILE_OPEN_CHECK(file);

    file << "Appended line." << std::endl;

    std::cout << "Line appended." << std::endl;
}

// Additional flags include "in" and "out". Also, generic file streams(either input, output or both) exist. Those can be
// used in combination with fstream type objects to both read and write from/to a file.

void readWriteExample(const std::string& filename)
{
    std::fstream file(filename, std::ios::in | std::ios::out);

    FILE_OPEN_CHECK(file);

    std::string content;
    std::getline(file, content);
    std::cout << "First line: " << content << std::endl;

    file.clear();
    file.seekp(0, std::ios::end);
    file << "Extra line added!\r\n";
}

/**************************************/
