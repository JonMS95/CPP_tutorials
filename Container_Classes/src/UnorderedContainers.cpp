/********* Include statements *********/

#include <unordered_map>
#include <unordered_set>
#include "AssociativeContainers.hpp"

/**************************************/

/****** Private inline functions ******/

static inline void printUnorderedMap(const std::string& unordered_map_name, auto input_unordered_map)
{
    printMap(unordered_map_name, input_unordered_map);
}

static inline void printUnorderedSet(const std::string unordered_set_name, auto input_unordered_set)
{
    printSet(unordered_set_name, input_unordered_set);
}

static inline void printUnorderedMultimap(const std::string unordered_multimap_name, auto input_unordered_multimap)
{
    printMultimap(unordered_multimap_name, input_unordered_multimap);
}

/**************************************/

/******** Function definitions ********/

void unorderedContainersSets(void)
{
    // Unordered sets: same as common sets, but with faster access ( O(1) vs O(log(n)) ).
    // Elements within are not ordered.
    std::unordered_set<int> u_s_0 ={1, 2, 5};
    u_s_0.insert(1);
    u_s_0.insert(7);
    u_s_0.insert(8);
    u_s_0.insert(2);
    
    printUnorderedSet("u_s_0", u_s_0);
}

void unorderedContainersMaps(void)
{
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

    printUnorderedMap("u_map_0", u_map_0);

    auto custom_hash = [](const std::pair<int,int>& p)
    {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    };  // A custom function is required in this case since no built-in has exists for std::pair<int, int>-like keys.

    std::unordered_map<std::pair<int, int>, std::string, decltype(custom_hash)> u_map_1(0, custom_hash); // Should tell initial size (0) since no constructor with just the hash function exists.

    u_map_1.insert({{1, 2}, "A"});
    u_map_1.insert({{3, 4}, "B"});
    u_map_1.insert({{5, 6}, "C"});

    // Not going to print the one above just not over-complicate things.
    // printUnorderedMap("u_map_1", u_map_1);
}

void unorderedContainersMultisets(void)
{
    // Unordered multiset: same as multiset, but faster access with unordered elements.
    std::unordered_multiset<int> u_ms_0 = {2, 2, 6, 4, 3, 4, 1, 4, 7, 9};
    printUnorderedSet("u_ms_0", u_ms_0);
}

void unorderedContainersMultimaps(void)
{
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

    printUnorderedMultimap("u_mm_0", u_mm_0);
}

/**************************************/
