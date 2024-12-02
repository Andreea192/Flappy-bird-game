#include "Spike.h"
#include <iostream>

// Constructor
Spike::Spike(int new_damage) : Obstacle("Spike", new_damage) {
}

// Constructor de copiere
Spike::Spike(const Spike &other) : Obstacle(other) {}

// Operatorul de atribuire
Spike &Spike::operator=(const Spike &other) {
    if (this != &other) {
        Obstacle::operator=(other);
    }
    return *this;
}

void Spike::interact(Bird &bird, bool passed) const {
    if (!passed) {
        bird.reduce_life(damage);
        std::cout << "The bird collided with a Spike. Damage: " << damage << std::endl;
    } else {
        std::cout << "The bird successfully passed through the Spike!" << std::endl;
    }
}

void Spike::display() const {
    std::cout << "Spike [Damage: " << damage << "]" << std::endl;
}

Obstacle *Spike::clone() const {
    return new Spike(*this); // Returnează o copie a obiectului Spike curent
}
