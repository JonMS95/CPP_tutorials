/********* Include statements *********/

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
#include "ContainerAdaptors.hpp"
#include "SequenceContainers.hpp"

/**************************************/

/**** Private function prototypes *****/

static void printIntContainerAdaptor(const std::string& var_name, auto var, std::function<int(decltype(var)&)> var_fn);

/**************************************/

/******** Function definitions ********/

// The function below may have been a template, and try to adapt to more types, but it's simply not worth
// it as the aim is to brush up on container adaptor types. 
// std::function syntax: std::function< rtype (atype...)> name(), where:
// ·name:   name of the wrapper.
// ·atype:  input argument types.
// ·rtype:  return type.
static void printIntContainerAdaptor(const std::string& var_name, auto var, std::function<int(decltype(var)&)> var_fn)
{
    std::vector<int> temp_vec;
    
    while (!var.empty())
    {
        temp_vec.emplace_back(var_fn(var));
        var.pop();
    }

    printSequenceContainer(var_name, temp_vec);
}

void containerAdaptorsStacks(void)
{
    // Stack: LIFO queue. Wraps std::deque by default, but can use vector or even list.
    // Only allows operations that make sense for a stack: push, pop, top, empty, size.
    std::stack<int> st_0;

    for(int i = 0; i < 5; i++)  // Push elements to the stack.
        st_0.push(i);

    auto st_fn = [](auto& st){return st.top();};

    printIntContainerAdaptor("st_0", st_0, st_fn);
    
    std::stack<int> st_1 = static_cast<std::stack<int>>(std::deque<int>{5, 6, 7, 8, 9}); // stacks can be initialized from deques.
    
    printIntContainerAdaptor("st_1", st_1, st_fn);

    while(!st_1.empty())
        st_1.pop();
}

void containerAdaptorsQueues(void)
{
    // Queue: FIFO queue. Again, wraps a deque by default. Supports push, pop, front,
    // back, emtpy, size.
    std::queue<int> q_0;
    for(int i = 10; i < 20; i++)
        q_0.push(i);
    
    for(int i = 0; i < q_0.size() / 2; i++)
        q_0.pop();

    auto q_fn = [](auto& q){return q.front();};

    printIntContainerAdaptor("q_0", q_0, q_fn);

    std::queue<int> q_1 = static_cast<std::queue<int>>(std::deque{1, 2, 3});    // Queues can also be initialized from deques.
    
    printIntContainerAdaptor("q_1", q_1, q_fn);
}

void containerAdaptorsHeaps(void)
{
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
    std::vector<int> tree_values_0 = {10, 3, 25, 8, 15, 2};
    std::priority_queue<int> h_0;
    
    for(int n : tree_values_0)
        h_0.push(n);

    // After having inserted every value in the heap, the heap will remain as follows.
    //     25
    //    /  \
    //  15    10
    //  / \   /
    // 8  3  2

    printSequenceContainer("vector_before_h_0", tree_values_0);
    
    auto h_fn = [](auto& h){return h.top();};
    
    printIntContainerAdaptor("h_0", h_0, h_fn);

    std::vector<int> h_1 = {10, 20, 5, 30, 15};

    printSequenceContainer("vector_before_h_1", h_1);

    std::make_heap(h_1.begin(), h_1.end()); // A heap can also be created directly from a vector.

    PRINT_SEQ_CONT(h_1);

    // Note that satisfying heap condition (root node is greater/lower/whatever than its children nodes) does not imply it's ordered in any way.
    // sort_heap can be used to do so, but the heap structure will be destroyed.

    std::sort_heap(h_1.begin(), h_1.end());
    
    printSequenceContainer("h_1 after sorting (destroyed heap)", h_1);
}

/**************************************/
