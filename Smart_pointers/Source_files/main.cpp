#include <iostream>
#include <string>
#include "Entity.hpp"
#include <memory>
// If smart pointers are going to be used, then "memory" file should be included.

int main()
{
    {
        // std::unique_ptr<Entity> pEntity(new Entity());
        // The unique pointer cannot be instantiated as int he line below:
        // std::unique_ptr<Entity> pEntity = new Entity();
        // The constructor for unique_ptr is explicit, which means that it should be called only in the specified way,
        // that's the one at the first attempt.
        // However, the first shown way to do it does not handle any exception, so it can be done in another way:
        std::unique_ptr<Entity> pEntity = std::make_unique<Entity>();

        // std::unique_ptr<Entity> p0 = pEntity;
        // The compiler will output an error if the line above is executed, as unique_ptr cannot be copied.
        // If we go to the class copy contructor's definition, we will see that the copy constructor is basically
        // a delete statement, just to prevent the developer from copying something that's meant to have a single
        // owner.

        pEntity->Greeting();
    }
    // As seen in the program output, the allocated object gets detroyed as soon as the scope is exited.
    // Therefore, the memory is freed automatically.


    // Shared pointers are kind of an extension to unique pointers. They allow the pointed entity to be owned
    // by more than just a single pointer. It achieves this by containing a counter that adds or subtracts one
    // depending on if the entity is being referenced or derreferenced. 
    std::shared_ptr<Entity> pShared1;
    {
        std::shared_ptr<Entity> pShared2 = std::make_shared<Entity>();
        // A new entity is created in the line above.
        pShared1 = pShared2;
        // Note that in this case, explicit copies are allowed. That's why they are called shared pointers.
    }
    // As this scope contains a shared pointer, which owns the entity same as the pointer in the previous scope,
    // the entity will not be destroyed until the scope is exited. Thus, the pointed object will only get deleted
    // once all the pointers allocated in stack, that point to that entity are deleted. In other words, the
    // heap-allocated object will only get destroyed once all the scopes where pointers to that object exist
    // are exited.

    return 0;
}