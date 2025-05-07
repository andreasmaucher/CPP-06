#include "RealType.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Testing with pointers (dynamically allocated) ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;
        Base* ptr = generate();
        std::cout << "Identifying type using pointer: ";
        identify(ptr);
        std::cout << "Identifying type using reference: ";
        identify(*ptr);
        delete ptr;
    }

    std::cout << "\n--- Testing with direct instantiation (stack allocation) ---" << std::endl;
    {
        std::cout << "\nTesting with A:" << std::endl;
        A a;
        Base& ref = a;
        std::cout << "Identifying type using pointer: ";
        identify(&a);
        std::cout << "Identifying type using reference: ";
        identify(ref);
    }
    {
        std::cout << "\nTesting with B:" << std::endl;
        B b;
        Base& ref = b;
        std::cout << "Identifying type using pointer: ";
        identify(&b);
        std::cout << "Identifying type using reference: ";
        identify(ref);
    }
    {
        std::cout << "\nTesting with C:" << std::endl;
        C c;
        Base& ref = c;
        std::cout << "Identifying type using pointer: ";
        identify(&c);
        std::cout << "Identifying type using reference: ";
        identify(ref);
    }

    return 0;
}
