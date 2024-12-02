#include "Bird.h"
#include <iostream>
#include "Exceptions.h"

// Constructor implicit
Bird::Bird() : life(100) {
}
// Constructor de copiere
Bird::Bird(const Bird &other) : life(other.life) {
    std::cout << "Copy constructor called. Life: " << life << std::endl;
}

// Operator de atribuire
Bird &Bird::operator=(const Bird &other) {
    if (this != &other) {
        life = other.life;
        std::cout << "Assignment operator called. Life: " << life << std::endl;
    }
    return *this;
}

void Bird::reduce_life(int value) {
    life -= value;
    if (life <= 0) {
        life = 0;
        throw BirdLifeException();
    }
}

void Bird::reset() {
    life = 100;
}

bool Bird::is_alive() const {
    return life > 0;
}

void Bird::display() const {
    std::cout << "Bird: " << life << " life remaining." << std::endl;
}

void Bird::interact() const {
    if (!is_alive()) {
        std::cout << "The bird has died!" << std::endl;
    }
}
