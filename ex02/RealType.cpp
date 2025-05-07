#include "RealType.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* // destructor
Base::~Base(void) {} */

// randomly instantiates A, B, or C and returns the instance as a Base pointer
Base* generate(void) {
    // initiate random number generator
    static bool first = true;
    if (first) {
        std::srand(std::time(NULL)); // seeding with current time, srand uses determistic algo (not random)
        first = false;
    }
    
    // Generate random number between 0 and 2
    int random = std::rand() % 3;
    
    // Create and return instance based on random number
    switch (random) {
        case 0:
            std::cout << "Generated type A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated type C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

// prints the actual type of the object pointed to by p: "A", "B", or "C"
void identify(Base* p) {
    // Try to dynamic_cast to each type
    // If cast succeeds, it's that type
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// prints the actual type of the object referenced by p: "A", "B", or "C".
void identify(Base& p) {
    // Using try-catch blocks because dynamic_cast throws on reference failure
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
    
    std::cout << "Unknown type" << std::endl;
}
