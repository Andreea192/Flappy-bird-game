#include "Spike.h"
#include <iostream>

// Constructor
template <typename T>
Spike<T>::Spike(int new_damage) : Obstacle<T>("Spike", new_damage) {  // Instanțierea Obstacle cu T
}

// Constructor de copiere
template <typename T>
Spike<T>::Spike(const Spike<T> &other) : Obstacle<T>(other) {  // Instanțierea Obstacle cu T
}

// Operatorul de atribuire
template <typename T>
Spike<T>& Spike<T>::operator=(const Spike<T> &other) {
    if (this != &other) {
        Obstacle<T>::operator=(other);  // Apelează operatorul de atribuire al clasei de bază
    }
    return *this;
}

// Interacțiunea cu pasărea
template <typename T>
void Spike<T>::interact(Bird<T> &bird, bool passed) const {
    if (!passed) {
        bird.reduce_life(this->get_damage());  // Folosește get_damage pentru a obține daunele
        std::cout << "Pasărea s-a lovit de un Spike. Daune: " << this->get_damage() << std::endl;
    } else {
        std::cout << "Pasărea a trecut cu succes prin Spike!" << std::endl;
    }
}

// Afișarea detaliilor
template <typename T>
void Spike<T>::display() const {
    std::cout << "Spike [Daune: " << this->get_damage() << "]" << std::endl;  // Folosește get_damage
}

// Clonare
template <typename T>
Obstacle<T>* Spike<T>::clone() const {
    return new Spike<T>(*this);  // Returnează o copie a obiectului Spike curent
}

// Explicit template instantiation pentru tipul int
template class Spike<int>;  // Instanțierea explicită pentru Spike<int>
