/********* Include statements *********/

#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

//#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

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

#define PRINT_SEQ_CONT(VAR_NAME)    printSequenceContainer(#VAR_NAME, VAR_NAME)

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

void TestContainerAdaptors(void)
{
    PrintTestHeader(MSG_TEST_CONTAINER_ADAPTORS);

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
   
    auto print_int_heap = [](const std::string& h_name, std::priority_queue<int> h) -> void
    {
        std::vector<int> temp_vec;
        
        while(!h.empty())
        {
            temp_vec.emplace_back(h.top());
            h.pop();
        }

        printSequenceContainer(h_name, temp_vec);
    };

    printSequenceContainer("vector_before_h_0", tree_values_0);
    print_int_heap("h_0", h_0);

    std::vector<int> h_1 = {10, 20, 5, 30, 15};

    printSequenceContainer("vector_before_h_1", h_1);

    std::make_heap(h_1.begin(), h_1.end()); // A heap can also be created directly from a vector.

    PRINT_SEQ_CONT(h_1);

    // Note that satisfying heap condition (root node is greater/lower/whatever than its children nodes) does not imply it's ordered in any way.
    // sort_heap can be used to do so, but the heap structure will be destroyed.

    std::sort_heap(h_1.begin(), h_1.end());
    
    printSequenceContainer("h_1 after sorting (destroyed heap)", h_1);
}

void TestAssociativeContainers(void)
{
    PrintTestHeader(MSG_TEST_ASSOCIATIVE_CONTAINERS);

    // Maps: balanced binary trees under the hood. Keys are immutable. Collection of key-value std::pair elements.
    // Does not allow duplicate keys. Can be defined directly as follows. Basic operations include: insert ([]),
    // count, find, at, size.
    std::map<std::string, unsigned int> name_2_age_map = 
    {
        {"Alice"    , 23},
        {"Bob"      , 25},
        {"Charlie"  , 30},
    };

    auto print_map = [](const std::string& map_name, auto input_map) -> void
    {
        size_t input_map_size = input_map.size();
        size_t idx = 0;

        std::cout << map_name << " = { ";
        
        for(auto it = input_map.begin(); it != input_map.end(); it++)
        {
            std::cout << "{" << it->first << ", " << it->second << "}";

            if(idx++ < (input_map_size - 1))
                std::cout << ", ";
        }

        std::cout << " }" << std::endl;
    };

    print_map("name_2_age_map", name_2_age_map);   

    std::map<int, int> histogram_map;
    std::vector<int> hist_values = {1, 23, 1, 45, 33, 67, 89, 33, 1};

    for(int n : hist_values)        // Values can be added one by one too.
        ++histogram_map[n];
    
    if(histogram_map.count(33))     // You can count how many keys with a given value (although it's always 1 or 0 in single key maps).
        histogram_map.at(33) = 33;  // Maps can also be accessed by using .at() method alongside a valid key. It will return an out of bounds exception if the target key does not exist.

    print_map("histogram_map", histogram_map);

    // Sets: again, a balanced binary tree. It's an ordered container that stores unique elements of a specified type.
    // It's automatically and duplicates are not allowed. Basic operations include: insert, erasem findm count, size.
    std::vector<int> set_values = hist_values;
    std::set<int> set_0;   
 
    for(int n : set_values)
        set_0.insert(n);

    auto print_set = [](const std::string& set_name, auto input_set) -> void
    {
        size_t input_set_size = input_set.size();
        size_t idx = 0;

        std::cout << set_name << " = { ";
        
        for(auto s : input_set)
        {
            std::cout << s;
            
            if(idx++ < (input_set_size - 1))
                std::cout << ", ";
        }

        std::cout << " }" << std::endl;
    };

    print_set("set_0", set_0);

    std::set<std::string> set_1 = {"Ein", "Zwei", "Drei", "Vier"};  // Sets can be defined and declared in a single statements too, same as if they were a mere vector.
    
    set_1.erase("Drei");    // Erase elements by using .erase() method alongside the element to be removed.
    
    if(!set_1.count("Acht"))
        set_1.insert("Acht");

    print_set("set_1", set_1);

    // Multimaps: same as maps, but allowing multiple values for each key. Different from maps, multimaps have no []
    // operator overloading (use .insert() instead). When it comes to retrieval, .at(method) cannot be used either,
    // but three alternatives exist in exchange:
    // ·.equal_range(): returns all matches.
    // ·.find(): returns first occurrence.
    std::multimap<int, std::string> age_2_name_map =
    {
        {30 ,   "Jon"   },
        {29 ,   "Ander" },
        {30,    "Marta" },
        {28,    "Cyrin" },
        {25,    "Leire" },
        {30,    "Juan"  },
        {25,    "Manu"  },
    };

    auto print_multimap = [](const std::string& multimap_name, const auto& input_multimap) -> void
    {
        using MapType   = std::decay_t<decltype(input_multimap)>;
        using KeyType   = typename MapType::key_type;
        using ValueType = typename MapType::mapped_type;

        std::set<KeyType> multimap_keys;
        for (auto it = input_multimap.begin(); it != input_multimap.end(); ++it)
            multimap_keys.insert(it->first);

        std::cout << multimap_name << " = " << std::endl << "{ " << std::endl;

        std::vector<ValueType> key_values;

        for (auto key : multimap_keys)
        {
            auto key_range = input_multimap.equal_range(key);
            key_values.clear();

            for (auto it = key_range.first; it != key_range.second; ++it)
                key_values.emplace_back(it->second);

            std::ostringstream oss;
            oss << key; // requires operator<< for KeyType
            printSequenceContainer(oss.str(), key_values);
        }

        std::cout << " }" << std::endl;
    };

    print_map("age_2_name_map", age_2_name_map);
    print_multimap("grouped_age_2_name_map", age_2_name_map);

    // Multisets: sames as sets, store elements in ascending order. It allows duplicated elements.
    // Allows insert, erase, count, find, lower/upper_bound, equal_range.
    std::multiset<int> m_set_0;
    m_set_0.insert(5);
    m_set_0.insert(1);
    m_set_0.insert(5);
    m_set_0.insert(3);
    m_set_0.insert(2);
    m_set_0.insert(2);

    print_set("m_set_0", m_set_0);
}

void TestUnorderedContainers(void)
{
    PrintTestHeader(MSG_TEST_UNORDERED_CONTAINERS);

    // Unordered sets: same as common sets, but with faster access ( O(1) vs O(log(n)) ).
    // Elements within are not ordered.
    std::unordered_set<int> u_s_0 ={1, 2, 5};
    u_s_0.insert(1);
    u_s_0.insert(7);
    u_s_0.insert(8);
    u_s_0.insert(2);

    auto print_set = [](const std::string& set_name, auto input_set) -> void
    {
        size_t input_set_size = input_set.size();
        size_t idx = 0;

        std::cout << set_name << " = { ";
        
        for(auto s : input_set)
        {
            std::cout << s;
            
            if(idx++ < (input_set_size - 1))
                std::cout << ", ";
        }

        std::cout << " }" << std::endl;
    };
    
    print_set("u_s_0", u_s_0);
    
    // Unordered map: same as common maps, but with faster access ( O(1) vs O(log(n)) ). Standard library provides std::hash for
    // basic types like int, std::tring and so on. For other types (such as std::pair) there's no built-in hash
    // function, so a custom one has to be defined in such cases.
    std::unordered_map<int, std::string> u_map_0 =
    {
        {1  ,   "Uno"   },
        {4  ,   "Quatre"},
        {3  ,   "Hiru"  },
        {2  ,   "Zwei"  },
    };

    auto print_map = [](const std::string& map_name, auto input_map) -> void
    {
        size_t input_map_size = input_map.size();
        size_t idx = 0;

        std::cout << map_name << " = { ";
        
        for(auto it = input_map.begin(); it != input_map.end(); it++)
        {
            std::cout << "{" << it->first << ", " << it->second << "}";

            if(idx++ < (input_map_size - 1))
                std::cout << ", ";
        }

        std::cout << " }" << std::endl;
    };

    print_map("u_map_0", u_map_0);

    auto custom_hash = [](const std::pair<int,int>& p)
    {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    };  // A custom function is required in this case since no built-in has exists for std::pair<int, int>-like keys.

    std::unordered_map<std::pair<int, int>, std::string, decltype(custom_hash)> u_map_1(0, custom_hash); // Should tell initial size (0) since no constructor with just the hash function exists.

    u_map_1.insert({{1, 2}, "A"});
    u_map_1.insert({{3, 4}, "B"});
    u_map_1.insert({{5, 6}, "C"});

    // Unordered multiset: same as multiset, but faster access with unordered elements.
    std::unordered_multiset<int> u_ms_0 = {2, 2, 6, 4, 3, 4, 1, 4, 7, 9};
    print_set("u_ms_0", u_ms_0);

    // Unordered_multimap: same as multimap, but faster access with unordered elements.
    std::unordered_multimap<int, std::string> u_mm_0 =
    {
        {1, "Monday"    },
        {2, "Tuesday"   },
        {1, "Montag"    },
        {3, "Wednesday" },
        {3, "Mittwoch"  },
        {2, "Dienstag"  },
        {4, "Donnerstag"},
        {5, "Freitag"   },
        {6, "Samstag"   },
        {7, "Sonntag"   },
    };
    
    auto print_multimap = [](const std::string& multimap_name, const auto& input_multimap) -> void
    {
        using MapType   = std::decay_t<decltype(input_multimap)>;
        using KeyType   = typename MapType::key_type;
        using ValueType = typename MapType::mapped_type;

        std::set<KeyType> multimap_keys;
        for (auto it = input_multimap.begin(); it != input_multimap.end(); ++it)
            multimap_keys.insert(it->first);

        std::cout << multimap_name << " = " << std::endl << "{ " << std::endl;

        std::vector<ValueType> key_values;

        for (auto key : multimap_keys)
        {
            auto key_range = input_multimap.equal_range(key);
            key_values.clear();

            for (auto it = key_range.first; it != key_range.second; ++it)
                key_values.emplace_back(it->second);

            std::ostringstream oss;
            oss << key; // requires operator<< for KeyType
            printSequenceContainer(oss.str(), key_values);
        }

        std::cout << " }" << std::endl;
    };

    print_multimap("u_mm_0", u_mm_0);
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
