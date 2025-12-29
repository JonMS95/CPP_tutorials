#ifndef BASIC_RANGES_HPP
#define BASIC_RANGES_HPP

/******** Function prototypes *********/

namespace range_basics
{
    
void iterateVector(const std::vector<int>& vec);
void iterateList(const std::list<std::string>& words);
void iterateString(const std::string& str);
void iterateTemporaryRange(const int start = 1, const int end = 10);

}

/**************************************/

#endif