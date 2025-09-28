#include "CastingTypesDerivedClass.hpp"

CastingTypesDerivedClass::CastingTypesDerivedClass(const int counter_val): CastingTypesBaseClass(counter_val)
{
    printStatusMsg(this->status_msg, derived_name);
}

int CastingTypesDerivedClass::getCounter(void) const
{
    return std::pow(CastingTypesBaseClass::getCounter(), 2);
}
