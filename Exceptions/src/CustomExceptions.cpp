/********* Include statements *********/

#include <stdexcept>
#include <string>
#include <fstream>
#include "Common.hpp"
#include "CustomExceptions.hpp"

/**************************************/

// This is how base class exception is defined (more or less):
//
//  class exception
// {
//   public:
//     exception() noexcept { }
//     virtual ~exception() noexcept;
//
//     // Default copy constructor, assignment operator overload, move constructor here.
//
//     virtual const char* what() const noexcept;
// };
//
// Since the methods shown are public, they can be overridden on condition the qualifiers are mantained
// (except possibly virtual but override instead, in case it's not meant to be derived anymore).
// An alternative (and popular) choice is to call the base constructor in the derived class constructor
// especially in those cases in which the base class constructor takes a string as input parameter.
// This can only be applied to already extended classes:
//
// class out_of_range : public logic_error
// {
//     public:
//     explicit out_of_range(const string& __arg);
//
//     // Default copy constructor, assignment operator overload, move constructor here.
//
//     virtual ~out_of_range() noexcept;
// };
//
// Typical derived class' what() method prototype should look like follows:
//
// const char* what() const noexcept override
//
// Let's split it into pieces:
// ·const char*: returns a constant character string (C-style).
// ·const: since the method modifies nothing, const qualifier should be used.
// ·noexcept: the method should not throw any exception.
// ·override: as the base class method is virtual, it should be overriden in the derived class.

/********* Include statements *********/

#define DEFAULT_PATH_NAME   "non_existing_path.txt"

/**************************************/

/***** Extended class definitions *****/

// Simplest example: deriving absolute base class. Only what method is overriden.

class MyException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Custom exception message (class: MyException)";
    }
};

// Derived class take a constant reference to a string as an input parameter, which
// is the string to be returned whenever an exception happens (by .what()).
// When deriving an already derived class, upper-level class constructor can be used.

class FileNotFoundException : public std::runtime_error
{
public:
    explicit FileNotFoundException(const std::string& file_name):
        std::runtime_error("File not found: " + file_name) {}
};

// Although base class constructor constructor can be called, .what() method can also
// be overriden.

class InvalidAgeException : public std::out_of_range
{
private:
    const std::string message;

public:
    InvalidAgeException(const int age):
        std::out_of_range("OOR: (invalid age)"), message("Invalid age: " + std::to_string(age)) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

/**************************************/

/***** Private function prototypes ****/

static void throwCustomException(void);
static void readFile(const std::string& file_path);

/**************************************/

/******** Function definitions ********/

static void throwCustomException(void)
{
    throw MyException();
}

static void readFile(const std::string& file_path)
{
    std::ifstream file;

    file.open(file_path);

    if(file.badbit)
        throw FileNotFoundException(file_path);

    std::string line;

    while(std::getline(file, line))
        std::cout << line << std::endl;
}

void causeCustomException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(throwCustomException(), MyException);
}

void causeFileNotFoundException(void)
{
    SIMPLE_TRY_CATCH_BLOCK(readFile(DEFAULT_PATH_NAME), FileNotFoundException);
}

/**************************************/
