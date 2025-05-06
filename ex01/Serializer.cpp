#include "Serializer.hpp"

// Constructor
Serializer::Serializer(void) {}

// Copy constructor
Serializer::Serializer(Serializer const &src) {
    (void)src;
}

// Copy assignment operator
Serializer &Serializer::operator=(Serializer const &src) {
    (void)src;
    return *this;
}

// Destructor
Serializer::~Serializer(void) {}

// takes a pointer and converts it to the unsigned integer type uintptr_t
// this converts the pointer to a number
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// takes an unsigned integer parameter and converts it to a pointer to Data
// this converts the number back to the original pointer
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
