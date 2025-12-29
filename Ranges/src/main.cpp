/********* Include statements *********/

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "BasicRanges.hpp"
#include "Views.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER         "*********************************"
#define MSG_TEST_BASIC_RANGES   "Testing basic ranges."
#define MSG_TEST_VIEWS          "Testing views."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestBasicRanges(void);
static void TestViews(void);

/**************************************/

/********** Global variables **********/

const std::vector<int> vec_int{9, 4, 3, 3, 9, 5, 5, 9, 2, 10};
const std::list<std::string> list_str{"Hello", "world", "of", "ranges"};
const std::string str = "abc";

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestBasicRanges(void)
{
    PrintTestHeader(MSG_TEST_BASIC_RANGES);

    range_basics::iterateVector(vec_int);
    range_basics::iterateList(list_str);
    range_basics::iterateString(str);
    range_basics::iterateTemporaryRange();
}

static void TestViews(void)
{
    PrintTestHeader(MSG_TEST_VIEWS);

    const std::vector<int> even_numbers = views::getEvenNumbers(vec_int);
    range_basics::iterateVector(even_numbers);
    
    const std::string uppercase_str = views::toUppercase(str);
    range_basics::iterateString(uppercase_str);

    const std::vector<int> doubled_odd_numbers = views::getDoubledOddNumbers(vec_int);
    range_basics::iterateVector(doubled_odd_numbers);
}


int main()
{
    TestBasicRanges();
    TestViews();

    return 0;
}

/**************************************/
