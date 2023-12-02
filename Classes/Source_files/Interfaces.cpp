/********* Include statements *********/

#include "Interfaces.hpp"

/**************************************/

/********* Method definitions *********/

void InterfacesBase::Hello()
{
    std::cout << "This method has been implemented in the base class." << std::endl;
}

std::string InterfacesDerived::Greeting(void)
{
    return "I am a derived class instance.";
}

/**************************************/

/******** Function definitions ********/

std::string PrintInterfaceGreeting(InterfacesBase* pIfaceClass)
{
    return pIfaceClass->Greeting();
}

/**************************************/
