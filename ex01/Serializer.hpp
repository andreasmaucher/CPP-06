#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <limits.h>
#include <sstream>
#include <cstring>
#include <numeric>
#include <cmath>
#include <stdint.h>
#include "Data.hpp"

class Serializer {

    private:
        // constructor (private to prevent instantiation
        Serializer(void);
        // Copy constructor 
        Serializer(Serializer const &src);
        // Copy assignment operator
        Serializer &operator=(Serializer const &src);
        // Destructor
        ~Serializer(void);

    public:
        // public methods
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif