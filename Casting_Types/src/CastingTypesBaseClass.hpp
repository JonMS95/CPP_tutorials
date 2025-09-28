#ifndef CASTING_TYPES_BASE_CLASS
#define CASTING_TYPES_BASE_CLASS

#include <iostream>
#include <memory>
#include <string>

class CastingTypesBaseClass
{
protected:
    const std::unique_ptr<int> counter_ptr;
    const std::string status_msg = "object with counter: ";
    virtual void printStatusMsg(const std::string& msg_part, const std::string& class_level = "(Base class) ") const;

public:
    int getCounter(void) const;
    CastingTypesBaseClass() = delete;
    CastingTypesBaseClass(const int counter_val);
    virtual ~CastingTypesBaseClass();
    CastingTypesBaseClass(const CastingTypesBaseClass& other);
};

#endif