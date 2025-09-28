#include "CastingTypesBaseClass.hpp"

void CastingTypesBaseClass::printStatusMsg(const std::string& msg_part, const std::string& class_level) const
{
    std::cout << class_level << msg_part << " " << this->status_msg << *this->counter_ptr << std::endl;
}

int CastingTypesBaseClass::getCounter(void) const
{
    return *this->counter_ptr;
}

CastingTypesBaseClass::CastingTypesBaseClass(const int counter_val): counter_ptr(std::make_unique<int>(counter_val))
{
    this->printStatusMsg("Created");
}

CastingTypesBaseClass::~CastingTypesBaseClass()
{
    this->printStatusMsg("Destroying");
}

CastingTypesBaseClass::CastingTypesBaseClass(const CastingTypesBaseClass& other): counter_ptr(std::make_unique<int>(other.getCounter()))
{
    this->printStatusMsg("Created copy of");
}
