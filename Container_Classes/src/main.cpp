/********* Include statements *********/

#include <iostream>
#include "SequenceContainers.hpp"
#include "ContainerAdaptors.hpp"
#include "AssociativeContainers.hpp"

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_SEQUENCE_CONTAINERS    "Testing sequence containers."
#define MSG_TEST_CONTAINER_ADAPTORS     "Testing container adaptors."
#define MSG_TEST_ASSOCIATIVE_CONTAINERS "Testing associative containers."
#define MSG_TEST_UNORDERED_CONTAINERS   "Testing unordered containers."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestSequenceContainers(void)
{
    PrintTestHeader(MSG_TEST_SEQUENCE_CONTAINERS);

    sequenceContainersArrays();
    sequenceContainersVectors();
    sequenceContainersDoubleQueues();
    sequenceContainersDoublyLinkedLists();
    sequenceContainersSinglyLinkedLists();
}

void TestContainerAdaptors(void)
{
    PrintTestHeader(MSG_TEST_CONTAINER_ADAPTORS);

    containerAdaptorsStacks();
    containerAdaptorsQueues();
    containerAdaptorsHeaps();
}

void TestAssociativeContainers(void)
{
    PrintTestHeader(MSG_TEST_ASSOCIATIVE_CONTAINERS);

    associativeContainersMaps();
    associativeContainersSets();
    associativeContainersMultimaps();
    associativeContainersMultisets();
}

void TestUnorderedContainers(void)
{
    PrintTestHeader(MSG_TEST_UNORDERED_CONTAINERS);

    
}

int main()
{
    TestSequenceContainers();
    TestContainerAdaptors();
    TestAssociativeContainers();

    return 0;
}

/**************************************/
