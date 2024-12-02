#include "Pipe.h"
#include <iostream>

// Constructor
Pipe::Pipe(int new_damage) : Obstacle("Pipe", new_damage) {
}

// Constructor de copiere
Pipe::Pipe(const Pipe &other) : Obstacle(other) {}

// Operatorul de atribuire
Pipe &Pipe::operator=(const Pipe &other) {
    if (this != &other) {
        Obstacle::operator=(other);
    }
    return *this;
}

// Implementarea metodei interact
void Pipe::interact(Bird &bird, bool passed) const {
    if (!passed) {
        bird.reduce_life(damage);
        std::cout << "The bird collided with a Pipe. Damage: " << damage << std::endl;
    } else {
        std::cout << "The bird successfully passed through the Pipe!" << std::endl;
    }
}

void Pipe::display() const {
    std::cout << "Pipe [Damage: " << damage << "]" << std::endl;
}

Obstacle *Pipe::clone() const {
    return new Pipe(*this); // Returnează o copie a obiectului Pipe curent
}
