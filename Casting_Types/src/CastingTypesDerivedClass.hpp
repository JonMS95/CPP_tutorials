#ifndef CASTING_TYPES_DERIVED_CLASS
#define CASTING_TYPES_DERIVED_CLASS

#include <cmath>
#include "CastingTypesBaseClass.hpp"

class CastingTypesDerivedClass : public CastingTypesBaseClass
{
private:
    const std::string derived_name = "(Derived class) ";
    
public:
    CastingTypesDerivedClass(const int counter_val = 0);
    int getCounter(void) const;
    ~CastingTypesDerivedClass() override = default;
};

#endif