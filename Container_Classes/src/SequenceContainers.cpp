/********* Include statements *********/

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include "SequenceContainers.hpp"

/**************************************/

/******** Function definitions ********/

void sequenceContainersArrays(void)
{
    // Arrays: fixed size collection. Stored on the stack. Behaves like C arrays, but safer.
    std::array<int, 5> arr = {4, 5, 6, 7, 8};

    arr.at(4) += 10;

    printSequenceContainer(("std::array<int, " + std::to_string(arr.size()) + "> arr"), arr);
}

void sequenceContainersVectors(void)
{
    // Vectors: same as arrays, but having the possibility to grow / shrink dynamically.
    std::vector<float> vec_0(3, 0); // 3 elements, being each element equal to 0.

    for(int i = 0; i < vec_0.size(); i++)
        vec_0[i] = i * i / 2;
    
    for(int i = 3; i < 6; i++)
        vec_0.emplace_back(i * 0.5f); // Use emplace back when working with basic data types (int, float, char, ...).
    // Note that elements have been added to the vector despite having being defined as size 3 before.

    printSequenceContainer("std::vector<float> vec_0", vec_0);

    // In contrast with emplace_back, push_back calls target class constructor. This way, constructor of the target
    // will be called whenever elements of a given class are meant to be introduced in a vector.
    std::vector<std::array<int, 3>> vec_1;
    for(int i = 0; i < 3; i++)
        vec_1.push_back({(i + 1) * 2, (i + 2) * 2, (i + 3) * 2});

    for(int i = 0; i < vec_1.size(); i++)
        printSequenceContainer(("vec_1[" + std::to_string(i) + "]"), vec_1[i]);
}

void sequenceContainersDoubleQueues(void)
{
    // Double queues: like vectors but optimized for insert / remove at both ends.
    std::deque<int> dq = {100, 2, 300};

    dq.pop_back();
    dq.pop_front();

    dq.emplace_back(3); // Same as with vectors, emplace_ or push_ can be used preferrably depending on the case.
    dq.emplace_front(1);

    PRINT_SEQ_CONT(dq);
}

void sequenceContainersDoublyLinkedLists(void)
{
    // Lists: doubly-linked lists. each elemented is linked to both the previous and the following.
    // No random access (it must be traversed). It can be traversed both forward or backwards since
    // each node is doubly-linked.
    std::list<char> dlist = {'x', 'b', 'z'};
    
    dlist.pop_front();
    dlist.pop_back();
    dlist.emplace_front('a'); // Again, emplace_ or push_ methods can be used alongside doubly linked lists (depending on the case). 
    dlist.emplace_back('c');
    PRINT_SEQ_CONT(dlist);
}

void sequenceContainersSinglyLinkedLists(void)
{
    // Forward lists: singly-linked lists. Can only be traversed in a single direction (forward).
    // A bit lighter than doubly-linked lists (just a single pointer vs two). Memory efficient.
    // Fun fact: forwrd lists have no .size() method, thus size has to be manually calculated by
    // forward iterating the list.
    std::forward_list<std::string> flist =
    {
        "Montag"    ,
        "Dienstag"  ,
        "Mittwoch"  ,
        "Donnerstag",
        "Freitag"   ,
        "Samstag"   ,
        "Sonntag"   ,
    };

    flist.pop_front();
    flist.push_front("Monday");
    flist.remove("Sonntag");
    flist.insert_after(std::find(flist.begin(), flist.end(), "Samstag"), "Domingo");

    PRINT_SEQ_CONT(flist);
}

/**************************************/
