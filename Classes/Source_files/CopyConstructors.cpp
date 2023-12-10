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
}

CopyConstructors::~CopyConstructors(void)
{
    if(this->m_buffer != nullptr)
        delete[] this->m_buffer;
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
}

/**************************************/

/******** Function definitions ********/

std::ostream& operator<<(std::ostream& stream, const CopyConstructors& copy_constructors)
{
    stream << copy_constructors.m_buffer;
    return stream;
}

/**************************************/
