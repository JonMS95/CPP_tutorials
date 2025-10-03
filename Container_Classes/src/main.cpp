/********* Include statements *********/

#include <iostream>
#include "SequenceContainers.hpp"
#include "ContainerAdaptors.hpp"
#include "AssociativeContainers.hpp"
#include "UnorderedContainers.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_SEQUENCE_CONTAINERS    "Testing sequence containers."
#define MSG_TEST_CONTAINER_ADAPTORS     "Testing container adaptors."
#define MSG_TEST_ASSOCIATIVE_CONTAINERS "Testing associative containers."
#define MSG_TEST_UNORDERED_CONTAINERS   "Testing unordered containers."

/**************************************/

/**** Private function prototypes *****/

static void PrintTestHeader(const char* header);
static void TestSequenceContainers(void);
static void TestContainerAdaptors(void);
static void TestAssociativeContainers(void);
static void TestUnorderedContainers(void);

/**************************************/

/******** Function definitions ********/

static void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

static void TestSequenceContainers(void)
{
    PrintTestHeader(MSG_TEST_SEQUENCE_CONTAINERS);

    sequenceContainersArrays();
    sequenceContainersVectors();
    sequenceContainersDoubleQueues();
    sequenceContainersDoublyLinkedLists();
    sequenceContainersSinglyLinkedLists();
}

static void TestContainerAdaptors(void)
{
    PrintTestHeader(MSG_TEST_CONTAINER_ADAPTORS);

    containerAdaptorsStacks();
    containerAdaptorsQueues();
    containerAdaptorsHeaps();
}

static void TestAssociativeContainers(void)
{
    PrintTestHeader(MSG_TEST_ASSOCIATIVE_CONTAINERS);

    associativeContainersMaps();
    associativeContainersSets();
    associativeContainersMultimaps();
    associativeContainersMultisets();
}

static void TestUnorderedContainers(void)
{
    PrintTestHeader(MSG_TEST_UNORDERED_CONTAINERS);

    unorderedContainersSets();
    unorderedContainersMaps();
    unorderedContainersMultisets();
    unorderedContainersMultimaps();
}

int main()
{
    TestSequenceContainers();
    TestContainerAdaptors();
    TestAssociativeContainers();
    TestUnorderedContainers();

    return 0;
}

/**************************************/
