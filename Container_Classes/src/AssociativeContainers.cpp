/********* Include statements *********/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "SequenceContainers.hpp"
#include "AssociativeContainers.hpp"

/**************************************/

/******** Function definitions ********/

void associativeContainersMaps(void)
{
    // Maps: balanced binary trees under the hood. Keys are immutable. Collection of key-value std::pair elements.
    // Does not allow duplicate keys. Can be defined directly as follows. Basic operations include: insert ([]),
    // count, find, at, size.
    std::map<std::string, unsigned int> name_2_age_map = 
    {
        {"Alice"    , 23},
        {"Bob"      , 25},
        {"Charlie"  , 30},
    };

    printMap("name_2_age_map", name_2_age_map);   

    std::map<int, int> histogram_map;
    std::vector<int> hist_values = {1, 23, 1, 45, 33, 67, 89, 33, 1};

    for(int n : hist_values)        // Values can be added one by one too.
        ++histogram_map[n];
    
    if(histogram_map.count(33))     // You can count how many keys with a given value (although it's always 1 or 0 in single key maps).
        histogram_map.at(33) = 33;  // Maps can also be accessed by using .at() method alongside a valid key. It will return an out of bounds exception if the target key does not exist.

    printMap("histogram_map", histogram_map);
}

void associativeContainersSets(void)
{
    // Sets: again, a balanced binary tree. It's an ordered container that stores unique elements of a specified type.
    // It's automatically and duplicates are not allowed. Basic operations include: insert, erasem findm count, size.
    std::vector<int> set_values = {25, 33, 1, 2, 45, 67, 99, 33, 2};
    std::set<int> set_0;   
 
    for(int n : set_values)
        set_0.insert(n);

    printSet("set_0", set_0);

    std::set<std::string> set_1 = {"Ein", "Zwei", "Drei", "Vier"};  // Sets can be defined and declared in a single statements too, same as if they were a mere vector.
    
    set_1.erase("Drei");    // Erase elements by using .erase() method alongside the element to be removed.
    
    if(!set_1.count("Acht"))
        set_1.insert("Acht");

    printSet("set_1", set_1);
}

void associativeContainersMultimaps(void)
{
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

    printMap("age_2_name_map", age_2_name_map);
    printMultimap("grouped_age_2_name_map", age_2_name_map);
}

void associativeContainersMultisets(void)
{
    // Multisets: sames as sets, store elements in ascending order. It allows duplicated elements.
    // Allows insert, erase, count, find, lower/upper_bound, equal_range.
    std::multiset<int> m_set_0;
    m_set_0.insert(5);
    m_set_0.insert(1);
    m_set_0.insert(5);
    m_set_0.insert(3);
    m_set_0.insert(2);
    m_set_0.insert(2);

    printSet("m_set_0", m_set_0);
}

/**************************************/
