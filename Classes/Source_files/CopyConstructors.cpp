/********* Include statements *********/

#include "CopyConstructors.hpp"

/**************************************/

/********* Method definitions *********/

CopyConstructors::CopyConstructors(const char* string_input)
{
    this->m_size = strlen(string_input);
    this->m_buffer = new char[this->m_size + 1];
    this->m_buffer[this->m_size] = 0;
    strcpy(this->m_buffer, string_input);

    std::cout << "Successfully created a \"CopyConstructors\" variable using string constructor!" << std::endl;
}

CopyConstructors::~CopyConstructors(void)
{
    if(this->m_buffer != nullptr)
        delete[] this->m_buffer;

    std::cout << "Destroyed \"CopyConstructors\" type variable!" << std::endl;
}

char& CopyConstructors::operator[](unsigned int index)
{
    if( (index < 0) || (index > (this->m_size - 1) ) )
        std::terminate();
    
    return this->m_buffer[index];
}

CopyConstructors::CopyConstructors(const CopyConstructors& other):
    m_size(other.m_size)
{
    this->m_buffer = new char[this->m_size + 1];
    strcpy(this->m_buffer, other.m_buffer);

    std::cout << "Successfully copied \"CopyConstructors\" type object instance!" << std::endl;
}

/**************************************/

/******** Function definitions ********/

CopyConstructors& CopyConstructors::operator=(const CopyConstructors& other)
{
    this->m_buffer  = other.m_buffer;
    this->m_size    = other.m_size;

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const CopyConstructors& copy_constructors)
{
    stream << copy_constructors.m_buffer;
    return stream;
}

void DummyPrintString(CopyConstructors other)
{
    std::cout << "m_buffer = " << other.m_buffer << ", m_size = " << other.m_size << std::endl;
}

void SmartPrintString(CopyConstructors& other)
{
    std::cout << "m_buffer = " << other.m_buffer << ", m_size = " << other.m_size << std::endl;
}

/**************************************/
