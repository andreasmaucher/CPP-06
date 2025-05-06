#include "Serializer.hpp"
#include <iostream>

/*
    General idea: convert a memory address (pointer) into a number and back while
    preserving the exact location in memory
*/

int main()
{
    Data originalData = {"DataMonkey", 42, 3.14};
    
    std::cout << "--- Original Data ---" << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << "Score: " << originalData.score << std::endl;
    
    // Get pointer to original data
    Data* originalPtr = &originalData;
    std::cout << "\nOriginal pointer: " << originalPtr << std::endl;
    
    // Serialize the pointer: turn it into a number
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize: turn the number back into a pointer
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    
    // Compare pointers
    std::cout << "\nPointer comparison: " << (originalPtr == deserializedPtr ? "MATCH" : "DIFFERENT") << std::endl;
    
    std::cout << "\n--- Deserialized Data ---" << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << "Value: " << deserializedPtr->value << std::endl;
    std::cout << "Score: " << deserializedPtr->score << std::endl;
    
    return 0;
}
