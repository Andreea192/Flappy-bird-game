#include "Forest.h"
#include <iostream>
#include <algorithm>

// Constructor
Forest::Forest(int new_damage) : Obstacle("Forest", new_damage), damage(new_damage) {
}

// Constructor de copiere
Forest::Forest(const Forest &other) : Obstacle(other), damage(other.damage) {
}

// Operator de atribuire
Forest &Forest::operator=(Forest other) {
    std::swap(*this, other);
    return *this;
}

void Forest::interact(Bird &bird, bool passed) const {
    if (!passed) {
        bird.reduce_life(damage);
        std::cout << "The bird collided with a Forest. Damage: " << damage << std::endl;
    } else {
        std::cout << "The bird successfully passed through the Forest!" << std::endl;
    }
}

void Forest::display() const {
    std::cout << "Forest [Damage: " << damage << "]" << std::endl;
}

Obstacle *Forest::clone() const {
    return new Forest(*this);
}
