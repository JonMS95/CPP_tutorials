/********* Include statements *********/

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_SEQUENCE_CONTAINERS    "Testing sequence containers."
#define MSG_TEST_CONTAINER_ADAPTERS     "Testing container adapters."
#define MSG_TEST_ASSOCIATIVE_CONTAINERS "Testing associative containers."
#define MSG_TEST_UNORDERED_CONTAINERS   "Testing unordered containers."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

template <typename T>
void printSequenceContainer(const std::string var_name, const T& var, const int var_size = -1)
{
    std::cout << var_name << " = {";

    int idx = 0;

    // Works even if container has no .size() (like forward_list).
    const int max_size = std::distance(var.begin(), var.end());

    for(const auto& v : var)
    {
        std::cout << v;
        if(idx++ < (max_size - 1))
            std::cout << ", ";
    }

    std::cout << "}" << std::endl;
}

void TestSequenceContainers(void)
{
    PrintTestHeader(MSG_TEST_SEQUENCE_CONTAINERS);

    // Arrays: fixed size collection. Stored on the stack. Behaves like C arrays, but safer.
    std::array<int, 5> arr = {4, 5, 6, 7, 8};

    arr.at(4) += 10;

    printSequenceContainer(("std::array<int, " + std::to_string(arr.size()) + "> arr"), arr);

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

    // Double queues: like vectors but optimized for insert / remove at both ends.
    std::deque<int> dq = {100, 2, 300};

    dq.pop_back();
    dq.pop_front();

    dq.emplace_back(3); // Same as with vectors, emplace_ or push_ can be used preferrably depending on the case.
    dq.emplace_front(1);

    printSequenceContainer("dq", dq);

    // Lists: doubly-linked lists. each elemented is linked to both the previous and the following.
    // No random access (it must be traversed). It can be traversed both forward or backwards since
    // each node is doubly-linked.
    std::list<char> dlist = {'x', 'b', 'z'};
    
    dlist.pop_front();
    dlist.pop_back();
    dlist.emplace_front('a'); // Again, emplace_ or push_ methods can be used alongside doubly linked lists (depending on the case). 
    dlist.emplace_back('c');
    printSequenceContainer("dlist", dlist);

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

    printSequenceContainer("flist", flist);
}

int main()
{
    TestSequenceContainers();

    return 0;
}

/**************************************/
