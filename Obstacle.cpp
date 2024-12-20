#include "Obstacle.h"
#include <iostream>

#include "Forest.h"
#include "Pipe.h"
#include "Spike.h"

// Constructorul de copiere
Obstacle::Obstacle(const Obstacle &other) : obstacle(other.obstacle), damage(other.damage) {}

// Operatorul de atribuire
Obstacle &Obstacle::operator=(const Obstacle &other) {
    if (this != &other) {
        obstacle = other.obstacle;
        damage = other.damage;
    }
    return *this;
}

// Constructor
Obstacle::Obstacle(const std::string &hazard_type, int new_damage)
    : obstacle(hazard_type), damage(new_damage) {
}

const std::string &Obstacle::get_obstacle() const {
    return obstacle;
}

int Obstacle::get_damage() const {
    return damage;
}

void Obstacle::interact(Bird &bird, bool passed) const {
    if (auto* forest = dynamic_cast<const Forest*>(this)) {
        forest->interact(bird, passed);
    } else if (auto* pipe = dynamic_cast<const Pipe*>(this)) {
        pipe->interact(bird, passed);
    } else if (auto* spike = dynamic_cast<const Spike*>(this)) {
        spike->interact(bird, passed);
    } else {
        std::cout << "The bird collided with an unknown obstacle." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Obstacle &o) {
    os << "Obstacle: " << o.get_obstacle() << ", Damage: " << o.get_damage();
    return os;
}
