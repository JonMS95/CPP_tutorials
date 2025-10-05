/********* Include statements *********/

#include <iostream>
#include <string>
#include "Singletons.hpp"

/**************************************/

/********* Include statements *********/

#define DEFAULT_NAME        "DEFAULT"

#define MSG_CREATION        "Created a Singleton object!"
#define MSG_DESTRUCTION     "Destroyed a Singleton object!"
#define MSG_EXCEPTION_ERROR "Singleton has not been created yet!"

/**************************************/

/********* Method definitions *********/
    
SingletonClass::SingletonClass(const int input_server_port = 80, const std::string input_server_name = "HTTP"):
server_port(input_server_port), server_name(input_server_name)
{
    std::cout << MSG_CREATION << std::endl;
}

SingletonClass& SingletonClass::instance(const int input_server_port, const std::string input_server_name)
{
    static SingletonClass obj(input_server_port, input_server_name);
    return obj;
}

int SingletonClass::getInstancePort(void)
{
    return this->server_port;
}

std::string SingletonClass::getInstanceName(void)
{
    return this->server_name;
}

/**************************************/
