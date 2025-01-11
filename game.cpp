#include "Exceptions.h"
#include <iostream>

#include "Exceptions.h"

class Bird {
public:
    // Constructor
    explicit Bird(int initial_height) {
        if (initial_height < 0) {
            throw InvalidValueException();
        }
        height = initial_height;
        std::cout << "The bird was created with a height of: " << height << std::endl;
    }

    // Constructor de copiere
    Bird(const Bird &other) {
        height = other.height;
        std::cout << "The bird was copied with a height of: " << height << std::endl;
    }

    // Operator de atribuire
    Bird &operator=(const Bird &other) {
        if (this != &other) {
            height = other.height;
        }
        return *this;
    }

    // Funcție pentru zbor
    void fly() {
        if (height <= 0) {
            throw ImpossibleOperationException();
        }
        height += 10;
        std::cout << "The bird flew! New height: " << height << std::endl;
    }

    // Funcție pentru cădere
    /*void fall() {
        if (height <= 0) {
            throw ImpossibleOperationException();
        }
        height -= 10;
        std::cout << "The bird fell! New height: " << height << std::endl;
    }*/

private:
    int height; // Membru de date
};
