/********* Include statements *********/

#include <iostream>
#include <memory>
#include "SmartPointersDummyClass.hpp"

/**************************************/

/********** Define statements *********/

#define MSG_TEST_HEADER             "*********************************"
#define MSG_TEST_SMART_POINTERS     "Testing Smart Pointers."
#define MSG_TEST_UNIQUE_POINTERS    "Testing Unique Pointers."
#define MSG_TEST_SHARED_POINTERS    "Testing Shared Pointers."
#define MSG_TEST_WEAK_POINTERS      "Testing Weak Pointers."

/**************************************/

/******** Function definitions ********/

void PrintTestHeader(const char* header)
{
    std::cout << std::endl << MSG_TEST_HEADER << std::endl << header << std::endl << MSG_TEST_HEADER << std::endl;
}

void TestSmartPointers()
{
    PrintTestHeader(MSG_TEST_SMART_POINTERS);

    // Smart pointers are a safer way to allocate and deallocate heap memory than using "new" and "delete" keywords, since
    // memory is freed automatically when it is no longer used. Essentially, smart pointers are just a kind of wrappers
    // around raw pointers, thus, new and delete are implicitly called when using smart pointers. In fact, the usage of the
    // "delete" keyword to deallocate memory that has been previously allocated by using these pointers is forbidden, as it
    // can lead to undefined behaviour or memory leaks as allocated memory could be freed twice.
    // As of 2023, there are 4 types of smart pointers:
    // ·Unique pointers:    also known as "scope pointers", they only exist within the scope in which they were previously
    //                      created. As the name suggests, just a single pointer to a specificied memory address may exist.
    // ·Shared pointers:    
    // ·Weak pointers:      
    // ·Auto pointers:      deprecated from C++11 onwards, replaced by unique pointers which provide improved safety.  

    /*********** Unique pointer ***********/
    PrintTestHeader(MSG_TEST_UNIQUE_POINTERS);
    // Let's create a new scope in which a couple of unique pointer are allocated.
    // Two syntax exist to dreate these pointers:
    // std::unique_ptr<class_name> pointer_name(new object());
    // std::unique_ptr<class_name> pointer_name = std::make_unique<class_name>();
    // The latter is preferred for exception safety reasons, although it does not allow initializer lists in constructor parameters.
    {
        std::unique_ptr<Dummy<float, 2>> pDummy0 = std::make_unique<Dummy<float, 2>>();
        pDummy0->SetName("Float dummy");
        (*pDummy0)[0] = 1.1;
        (*pDummy0)[1] = 2.2;

        std::unique_ptr<Dummy<int, 3>> pDummy1(new Dummy<int, 3>("Integer dummy", {3, 4, 5}));

        // as the name suggests, unique pointers cannot be copied. Therefore, the statement below could lead to a compilation error:
        // std::unique_ptr<Dummy<float, 2>> pDummy0_copy = pDummy0;
        // In fact, the copy constructor and "=" operator overload are equeal to delete. This is intended to prevent the code from
        // potential pitfalls, as the heap memory is freed if any of the unique pointers is deallocated.

        std::cout << pDummy0->GetDummyAsString() << std::endl;
        pDummy1->PrintElements();
    }
    // As soon as the stack pointer exits the context in which the unique pointers were declared, they will be
    // deallocated from heap memory.
    /**************************************/

    /*********** Shared pointer ***********/
    PrintTestHeader(MSG_TEST_SHARED_POINTERS);
    // In contrast to unique pointers, the lifetime of shared pointers is not constrained to the scope in which they were instantiated.
    // The way this works under the hood is by using a technique known as reference counting. Basically, it keeps track of how many
    // references exist to the pointer, so that the reserved memory is only freed once it is known that no reference to that memory
    // space exist. The syntax for this type of pointer is similar to the one used in unique pointers:
    // std::shared_ptr<class_name> pointer_name(new object());
    // std::shared_ptr<class_name> pointer_name = std::make_shared<class_name>();
    // Again, in this case it is way more efficient to use the latter syntax, since it needn't call the constructor first an then the
    // reference counter mechanism, but all at the same instead.

    {
        std::shared_ptr<Dummy<char, 4>> pDummy2;
        
        {
            pDummy2 = std::make_shared<Dummy<char, 4>>();

            std::shared_ptr<Dummy<char, 4>> pDummy3 = pDummy2;
            pDummy3->SetName("Char dummy");
            
            for(int i = 0; i < pDummy3->GetSize(); i++)
                (*pDummy3)[i] = 'a' + i;

            Dummy<char, 4>::PrintSharedPointerOwners(pDummy2);

            std::cout << "Number of owners of memory allocated by pDummy2: "<< pDummy2.use_count() << std::endl;
        }

        pDummy2->PrintElements();

        Dummy<char, 4>::PrintSharedPointerOwners(pDummy2);
    }

    // In the example shown above, it may be noticed that memory has not been freed after exiting the scope in which pDummy3 pointer
    // was been created, since a reference stored in pDummy2 still existed (the latter pointer exists outside the scope). Apart from that,
    // the pointer can be easily copied. In conclusion, the memory was freed only when the scope in which pDummy2 was created no longer
    // existed.

    /**************************************/

    /************ Weak pointer ************/
    PrintTestHeader(MSG_TEST_WEAK_POINTERS);
    // Weak pointers provide a non-owning refernce to an object. Different from shared pointers, these will not create any reference counter
    // whatsoever. The aim of this type of pointers is to prevent the code from creating circular references.

    {
        std::shared_ptr<Dummy<std::string, 2>> pDummy4 = std::make_shared<Dummy<std::string, 2>>();
        std::weak_ptr<Dummy<std::string, 2>> pDummy5 = pDummy4;

        Dummy<std::string, 2>::CheckWeakPointerAbailavility(pDummy5);

        pDummy4->SetName("String dummy");

        pDummy5.reset();

        Dummy<std::string, 2>::CheckWeakPointerAbailavility(pDummy5);
    }

    /**************************************/
}

int main()
{
    TestSmartPointers();

    return 0;
}

/**************************************/
