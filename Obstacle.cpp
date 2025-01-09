#include "Obstacle.h"
#include <iostream>

#include "Forest.h"
#include "Pipe.h"
#include "Spike.h"

// Copy constructor
template <typename T>
Obstacle<T>::Obstacle(const Obstacle<T> &other) : obstacle(other.obstacle), damage(other.damage) {}

// Assignment operator
template <typename T>
Obstacle<T>& Obstacle<T>::operator=(const Obstacle<T> &other) {
    if (this != &other) {
        obstacle = other.obstacle;
        damage = other.damage;
    }
    return *this;
}

// Constructor
template <typename T>
Obstacle<T>::Obstacle(const std::string &hazard_type, int new_damage)
    : obstacle(hazard_type), damage(new_damage) {
}

template <typename T>
const std::string &Obstacle<T>::get_obstacle() const {
    return obstacle;
}

template <typename T>
int Obstacle<T>::get_damage() const {
    return damage;
}

template <typename T>
void Obstacle<T>::interact(Bird<T> &bird, bool passed) const {
    // Now using the correct template arguments for dynamic_cast
    if (auto* forest = dynamic_cast<const Forest<T>*>(this)) {
        forest->interact(bird, passed);
    } else if (auto* pipe = dynamic_cast<const Pipe<T>*>(this)) {
        pipe->interact(bird, passed);
    } else if (auto* spike = dynamic_cast<const Spike<T>*>(this)) {
        spike->interact(bird, passed);
    } else {
        std::cout << "The bird collided with an unknown obstacle." << std::endl;
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Obstacle<T> &o) {
    os << "Obstacle: " << o.get_obstacle() << ", Damage: " << o.get_damage();
    return os;
}

// Explicit template instantiation for the types you use in your project
template class Obstacle<int>;  // Example of instantiation
