#ifndef ASSOCIATIVE_CONTAINERS_HPP
#define ASSOCIATIVE_CONTAINERS_HPP

/********* Include statements *********/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include "SequenceContainers.hpp"

/**************************************/

/******** Function prototypes *********/

void printMap(const std::string& map_name, auto input_map)
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

void printSet(const std::string& set_name, auto input_set)
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
}

void printMultimap(const std::string& multimap_name, auto input_multimap)
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
}

void associativeContainersMaps(void);
void associativeContainersSets(void);
void associativeContainersMultimaps(void);
void associativeContainersMultisets(void);

/**************************************/

#endif
