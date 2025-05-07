#ifndef REALTYPE_HPP

#define REALTYPE_HPP

#include <iostream>

class Base {
    public:
        // public virtual destructor
        virtual ~Base(void) { std::cout << "Base destructor called" << std::endl; }
};

// three empty classes that inherit from Base
class A : public Base {
public:
    ~A(void) { std::cout << "A destructor called" << std::endl; }
};

class B : public Base {
public:
    ~B(void) { std::cout << "B destructor called" << std::endl; }
};

class C : public Base {
public:
    ~C(void) { std::cout << "C destructor called" << std::endl; }
};

// Function declarations
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
