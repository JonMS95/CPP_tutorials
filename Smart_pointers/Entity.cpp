#include "Entity.hpp"
#include <iostream>

Entity::Entity()
{
    std::cout << "Created Entity!\r\n";
}

Entity::~Entity()
{
    std::cout << "Deleted Entity!\r\n";
}