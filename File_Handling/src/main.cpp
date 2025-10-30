/********* Include statements *********/

#include <iostream>
#include <fstream>
#include "GetPath.hpp"
#include "BasicFileIO.hpp"
#include "FileDirOps.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_BASIC_FILE_IO  "Testing file I/O."
#define MSG_TEST_FILE_DIR_OPS   "Testing file and directory operations."

#define TEST_FILE_PATH  "../test.txt"
#define DEST_FILE_NAME  "destination.txt"

/**************************************/

/********* Private variables **********/

static const std::string filename = getAbsolutePath(TEST_FILE_PATH);

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestBasicFileIO(void)
{
    PrintTestHeader(MSG_TEST_BASIC_FILE_IO);

    writeToFile(filename);
    readFromFile(filename);
    appendToFile(filename);
    readWriteExample(filename);
}

static void TestFileDirOps(void)
{
    PrintTestHeader(MSG_TEST_FILE_DIR_OPS);

    listFiles(".");
    fileOperations(TEST_FILE_PATH, DEST_FILE_NAME);
    showPathInfo(filename);
}

int main()
{
    TestBasicFileIO();
    TestFileDirOps();

    return 0;
}

/**************************************/
