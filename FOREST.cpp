#include "Forest.h"
#include <iostream>
#include <algorithm>

template <typename T>
Forest<T>::Forest(int new_damage) : Obstacle<T>("Forest", new_damage), damage(new_damage) {
    // Constructor care inițializează atât clasa de bază Obstacle cât și atributul damage
}

template <typename T>
Forest<T>::Forest(const Forest<T> &other) : Obstacle<T>(other), damage(other.damage) {
    // Constructor de copiere
}

template <typename T>
Forest<T>& Forest<T>::operator=(Forest<T> other) {
    std::swap(*this, other);  // Swap pentru a implementa operatorul de atribuire
    return *this;
}

template <typename T>
void Forest<T>::interact(Bird<T> &bird, bool passed) const {
    if (!passed) {
        bird.reduce_life(this->get_damage());  // Folosește get_damage() moștenit din Obstacle
        std::cout << "The bird collided with a Forest. Damage: " << this->get_damage() << std::endl;
    } else {
        std::cout << "The bird successfully passed through the Forest!" << std::endl;
    }
}

template <typename T>
void Forest<T>::display() const {
    std::cout << "Forest [Damage: " << this->get_damage() << "]" << std::endl;  // Folosește get_damage() moștenit din Obstacle
}

template <typename T>
Obstacle<T>* Forest<T>::clone() const {
    return new Forest<T>(*this);  // Creează o copie a obiectului Forest
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Forest<T> &f) {
    os << "Forest [Damage: " << f.get_damage() << "]";  // Afișează damage-ul Forest
    return os;
}

// Explicit template instantiations
template class Forest<int>;  // Instanțierea template-ului pentru Forest cu tipul int
