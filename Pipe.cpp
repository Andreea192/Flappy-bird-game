#include "Pipe.h"
#include <iostream>

template <typename T>
Pipe<T>::Pipe(int new_damage) : Obstacle<T>("Pipe", new_damage) {}

template <typename T>
Pipe<T>::Pipe(const Pipe<T> &other) : Obstacle<T>(other) {}

template <typename T>
Pipe<T>& Pipe<T>::operator=(const Pipe<T> &other) {
    if (this != &other) {
        Obstacle<T>::operator=(other);
    }
    return *this;
}

template <typename T>
void Pipe<T>::interact(Bird<T> &bird, bool passed) const {
    if (!passed) {
        bird.reduce_life(this->get_damage());  // Apelăm get_damage() din clasa de bază
        std::cout << "The bird collided with a Pipe. Damage: " << this->get_damage() << std::endl;
    } else {
        std::cout << "The bird successfully passed through the Pipe!" << std::endl;
    }
}

template <typename T>
void Pipe<T>::display() const {
    std::cout << "Pipe obstacle with " << this->get_damage() << " damage." << std::endl;
}

template <typename T>
Obstacle<T>* Pipe<T>::clone() const {
    return new Pipe<T>(*this);
}

// Explicit template instantiation
template class Pipe<int>;  // Instanțierea template-ului pentru tipul int
