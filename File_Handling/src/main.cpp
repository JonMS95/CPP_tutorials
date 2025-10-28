/********* Include statements *********/

#include <iostream>

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_BASIC_FILE_IO  "Testing file I/O."

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestBasicFileIO(void)
{
    PrintTestHeader(MSG_TEST_BASIC_FILE_IO);

    // writeToFile(filename);
    // readFromFile(filename);
    // appendToFile(filename);
    // readWriteExample(filename);
}

int main()
{
    TestBasicFileIO();

    return 0;
}

/**************************************/
