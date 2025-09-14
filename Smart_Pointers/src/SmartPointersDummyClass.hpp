#ifndef SMART_POINTER_DUMMY_CLASS_HPP
#define SMART_POINTER_DUMMY_CLASS_HPP

/********* Include statements *********/

#include <iostream>
#include <string>
#include <vector>

/**************************************/

/********** Class prototypes **********/

template <typename T, int N> class Dummy
{
private:
    const int m_size = N;
    T m_buffer[N];
    std::string m_name;

    void AssignValues(const std::vector<T>& values)
    {
        if(values.size() > this->m_size)
        {
            std::cout << "Warning: there are " << (values.size() - this->m_size) << " spare elements in the provided list." << std::endl;
        }

        size_t i = 0;

        for(const auto& value : values)
        {
            if(i < this->m_size)
                this->m_buffer[i++] = value;
            else
                break;
        }
    }

public:
    Dummy(void): m_name("DEFAULT") { std::cout << "Using constructor with default values." << std::endl; }

    Dummy(const std::string& name_input): m_name(name_input){}

    Dummy(const std::string& name_input, const std::vector<T>& values): m_name(name_input)
    {
        std::cout << "Using constructor with specified input parameters." << std::endl;
        this->AssignValues(values);
    }

    virtual ~Dummy(void) { std::cout << "Deleting instance with name: " << this->m_name << std::endl; }
    
    Dummy(const Dummy& other): m_size(other.m_size), m_name(other.m_name)
    {
        std::copy(std::begin(other.m_buffer), std::end(other.m_buffer), std::begin(this->m_buffer));
        this->m_name += " (copy)";
    }

    std::string GetName(void) { return this->m_name; }

    void SetName(std::string name_input) { this->m_name = name_input; }

    int GetSize(void) { return this->m_size; }

    std::string GetDummyAsString(void)
    {
        std::string ret = "";

        ret += this->m_name + " = {";

        for(int i = 0; i < this->m_size; i++)
        {
            ret += std::to_string(this->m_buffer[i]);
            
            if(i < (this->m_size - 1) )
                ret += ", ";
        }
        
        ret += "}";

        return ret;
    }

    void PrintElements(void) { std::cout << this->GetDummyAsString() << std::endl; }

    Dummy& operator=(const std::vector<T>& values)
    {
        this->AssignValues(values);

        return *this;
    }
    
    T& operator[](int index)
    {
        if( (index < 0) || (index >= m_size) )
        {
            std::cout << "Index is out of boundaries! Returning last index element." << std::endl;
            return this->m_buffer[this->m_size - 1];
        }

        return this->m_buffer[index];
    }

    static void PrintSharedPointerOwners(const std::shared_ptr<Dummy<T, N>>& other)
    {
        std::cout << "Number of owners of memory allocated by shared pointer: "<< other.use_count() << std::endl;
    }

    static void CheckWeakPointerAbailavility(const std::weak_ptr<Dummy<T, N>>& other)
    {
        if(auto shared = other.lock())
            std::cout << "Using weak_ptr to access stored resource.";
        else
            std::cout << "Resource in weak_ptr has already been deleted.";
        
        std::cout << std::endl;
    }
};

/**************************************/

#endif