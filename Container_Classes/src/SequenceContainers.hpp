#ifndef SEQUENCE_CONTAINERS_HPP
#define SEQUENCE_CONTAINERS_HPP

/********* Include statements *********/

#include <iostream>
#include <string>

/**************************************/

/********** Define statements *********/

#define PRINT_SEQ_CONT(VAR_NAME)    printSequenceContainer(#VAR_NAME, VAR_NAME)

/**************************************/

/******** Temaplate functions *********/

template <typename T>
void printSequenceContainer(const std::string var_name, const T& var)
{
    std::cout << var_name << " = {";

    int idx = 0;

    // Works even if container has no .size() (like forward_list).
    const int var_size = std::distance(var.begin(), var.end());

    for(const auto& v : var)
    {
        std::cout << v;
        if(idx++ < (var_size - 1))
            std::cout << ", ";
    }

    std::cout << "}" << std::endl;
}

/**************************************/

/******** Function prototypes *********/

template <typename T>
void printSequenceContainer(const std::string var_name, const T& var);
void sequenceContainersArrays(void);
void sequenceContainersVectors(void);
void sequenceContainersDoubleQueues(void);
void sequenceContainersDoublyLinkedLists(void);
void sequenceContainersSinglyLinkedLists(void);

/**************************************/

#endif
