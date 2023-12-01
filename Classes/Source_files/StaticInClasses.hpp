#ifndef STATIC_IN_CLASSES_HPP
#define STATIC_IN_CLASSES_HPP

/********* Include statements *********/

#include <iostream>

/**************************************/

// Whenever a variable is declared as static, it means that it is only visible from the translation unit's scope.
// However, there's an additional meaning for this keyword in C++ if applied within a class.
// When it cmes down to variables in classes, it means that there's a variable that should be defined and that will
// have a value which wll be the same for every class instance.
// Thus, it can be regarded as a variable that is not actually part of every class object instance but as a variable
// that is actually shared by each of those instances.
// Take into account that when calling those, it could be done as if they were actually members of the described class
// (even though they are not).

// Apart from variables, methods (i.e., functions associated to classes) can also be static. In this case, their
// aim is not to create a function that can be shared with each instance (it could be easier to create a function
// in pure C style), but for organizational purposes. 

/*********** Class prototype **********/

class StaticInClasses
{
private:
    int x = 0;
    int y = 0;
public:
    static int a, b;
    void SetX(int x_input);
    int GetX(void);
    void SetY(int y_input);
    int GetY(void);
    void PrintClassVars(void);
    void PrintStaticVars(void);
    static void Greeting(void);
};

/**************************************/

#endif
