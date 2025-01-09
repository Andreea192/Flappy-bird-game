#include "Bird.h"
#include <iostream>
#include <stdexcept>

// Constructor implicit
template <typename T>
Bird<T>::Bird() : life(100), speed(T()) {}

// Constructor cu parametri
template <typename T>
Bird<T>::Bird(int life, T speed) : life(life), speed(speed) {}

// Constructor de copiere
template <typename T>
Bird<T>::Bird(const Bird<T>& other) : life(other.life), speed(other.speed) {
    std::cout << "Copy constructor called. Life: " << life << ", Speed: " << speed << std::endl;
}

// Operator de atribuire
template <typename T>
Bird<T>& Bird<T>::operator=(const Bird<T>& other) {
    if (this != &other) {
        life = other.life;
        speed = other.speed;
        std::cout << "Assignment operator called. Life: " << life << ", Speed: " << speed << std::endl;
    }
    return *this;
}

// Metoda de reducere a vieții
template <typename T>
void Bird<T>::reduce_life(T value) {
    life -= value;
    if (life <= 0) {
        life = 0;
        throw std::runtime_error("Bird's life has reached zero!");
    }
}

// Resetare viață și viteză
template <typename T>
void Bird<T>::reset() {
    life = 100;
    speed = T();
}

// Verificare dacă pasărea este vie
template <typename T>
bool Bird<T>::is_alive() const {
    return life > 0;
}

// Afișare starea păsării
template <typename T>
void Bird<T>::display() const {
    std::cout << "Bird: " << life << " life remaining, Speed: " << speed << std::endl;
}

// Verificare viață
template <typename T>
void Bird<T>::check_life() const {
    if (life > 50) {
        std::cout << "The bird is in good condition." << std::endl;
    } else {
        std::cout << "The bird is in poor condition." << std::endl;
    }
}

// Ajustarea vitezei
template <typename T>
void Bird<T>::adjust_speed(T factor) {
    speed *= factor;  // Ajustăm viteza în funcție de un factor
}

// Funcție prietenă care schimbă viteza păsării
template <typename U>
void change_bird_speed(Bird<U>& bird, U new_speed) {
    bird.speed = new_speed;
    std::cout << "The bird's speed has been changed to: " << bird.speed << std::endl;
}

// Specializarea funcției pentru tipul int (sau orice alt tip dorit)
template class Bird<int>;
template class Bird<float>;

