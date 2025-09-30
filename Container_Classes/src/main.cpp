/********* Include statements *********/

#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

#include <stack>
#include <queue>
#include <algorithm>

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER                 "*********************************"
#define MSG_TEST_SEQUENCE_CONTAINERS    "Testing sequence containers."
#define MSG_TEST_CONTAINER_ADAPTORS     "Testing container adaptors."
#define MSG_TEST_ASSOCIATIVE_CONTAINERS "Testing associative containers."
#define MSG_TEST_UNORDERED_CONTAINERS   "Testing unordered containers."

#define PRINT_SEQ_CONT(VAR_NAME)    printSequenceContainer(#VAR_NAME, VAR_NAME)
#define PRINT_CONT_ADAPT(VAR_NAME)  printContainerAdaptor(#VAR_NAME, VAR_NAME)

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

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

    PRINT_SEQ_CONT(dq);

    // Lists: doubly-linked lists. each elemented is linked to both the previous and the following.
    // No random access (it must be traversed). It can be traversed both forward or backwards since
    // each node is doubly-linked.
    std::list<char> dlist = {'x', 'b', 'z'};
    
    dlist.pop_front();
    dlist.pop_back();
    dlist.emplace_front('a'); // Again, emplace_ or push_ methods can be used alongside doubly linked lists (depending on the case). 
    dlist.emplace_back('c');
    PRINT_SEQ_CONT(dlist);

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

template <typename T>
void printContainerAdaptor(const std::string& var_name, const T& var)
{
    std::cout << var_name << " = {";

    T var_copy = var;

    while(!var_copy.empty())
    {
        std::cout << var_copy.top();
        var_copy.pop();
        
        if(!var_copy.empty())
            std::cout << ", ";
    }

    std::cout << "}" << std::endl;
}

void TestContainerAdaptors(void)
{
    // Stack: LIFO queue. Wraps std::deque by default, but can use vector or even list.
    // Only allows operations that make sense for a stack: push, pop, top, empty, size.
    std::stack<int> st_0;

    for(int i = 0; i < 5; i++)  // Push elements to the stack.
        st_0.push(i);

    auto print_int_stack = [](const std::string& st_name, std::stack<int> st) -> void
    {
        std::vector<int> temp_vec;
        
        while(!st.empty())
        {
            temp_vec.emplace_back(st.top());
            st.pop();
        }

        printSequenceContainer(st_name, temp_vec);
    };

    print_int_stack("st_0", st_0);
    
    std::stack<int> st_1 = static_cast<std::stack<int>>(std::deque<int>{5, 6, 7, 8, 9}); // stacks can be initialized from deques.
    
    print_int_stack("st_1", st_1);

    while(!st_1.empty())
        st_1.pop();

    // Queue: FIFO queue. Again, wraps a deque by default. Supports push, pop, front,
    // back, emtpy, size.
    std::queue<int> q_0;
    for(int i = 10; i < 20; i++)
        q_0.push(i);
    
    for(int i = 0; i < q_0.size() / 2; i++)
        q_0.pop();
    
    auto print_int_queue = [](const std::string& q_name, std::queue<int> q) -> void
    {
        std::vector<int> temp_vec;
        
        while(!q.empty())
        {
            temp_vec.emplace_back(q.front());
            q.pop();
        }

        printSequenceContainer(q_name, temp_vec);
    };

    print_int_queue("q_0", q_0);

    std::queue<int> q_1 = static_cast<std::queue<int>>(std::deque{1, 2, 3});    // Queues can also be initialized from deques.
    print_int_queue("q_1", q_1);

    // Priority queue: heap (priority ordering). Wraps std::vector by default and
    // mantains heap property. Always keeps the largest element on top by default.
    // A heap is a special type of binary tree (usually represented as an array)
    // which usually satisfies the heap property:
    // ·Max-heap: every parent node is greater than or equal to its children.
    // ·Min-heap: every parent node is less than or equal to its children.
    // Example:
    //         42
    //       /    \
    //      29     18
    //     /  \   /  \
    //    14  7  18  12
    // This could be stored in an array: {42, 29, 18, 14, 7, 18, 12}
    // If a heap is stored as an array, then:
    // Parent index:    i
    // Left child:      2 * i + 1
    // Right child:     2 * i + 2

    // Let's say we have the following numbers: {10, 3, 25, 8, 15, 2}, which can
    // be represented as a binary tree as follows:
    //     10
    //    /  \
    //   3    25
    //  / \   /
    // 8  15  2
    std::vector<int> tree_values = {10, 3, 25, 8, 15, 2};
    std::priority_queue<int> h_0;
    
    for(int n : tree_values)
        h_0.push(n);
    
    // printSequenceContainer("h_0", static_cast<std::vector<int>>(h_0));
}

int main()
{
    TestSequenceContainers();
    TestContainerAdaptors();

    return 0;
}

/**************************************/
