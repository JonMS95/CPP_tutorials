#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

/********* Include statements *********/

#include <string>
#include <memory>

/**************************************/

// Singletons are a type of object in C++ that are meant to be instantiated solely once. This may make sense
// for instance, services that should have just a single handlers: for a given host acting as a server, we may
// want to have just a single object handling each port (a single ssh server, a single http server, and so on).
//
// For such purpose, it's required to build a class taht cannot support copy/move constructors nor assignment
// operator overloading. In the same fashion, no constructor can be public since the aim is just a single object
// to be instantiated. As such guarantee should be provided, an object-instantiation handler should be written
// (or at least, it's strongly recommended in most of the cases).
// 
// In this case, the typical Meyers singleton template is going to be followed.

/********** Class prototypes **********/

class SingletonClass
{
private:
    const int server_port;
    const std::string server_name;
    
    SingletonClass(const int input_server_port, const std::string input_server_name);

public:
    SingletonClass(void) = delete;
    SingletonClass(const SingletonClass& other) = delete;
    SingletonClass(SingletonClass&& other) = delete;
    SingletonClass& operator=(SingletonClass& other) = delete;

    static SingletonClass& instance(const int input_server_port, const std::string input_server_name);

    int getInstancePort(void);
    std::string getInstanceName(void);
};

/**************************************/

#endif
