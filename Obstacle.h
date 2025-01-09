#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>
#include <iostream> // Pentru afisare
#include "Bird.h" // Asigură-te că Bird este inclus corect

// Forward declarations pentru clase template
template <typename T> class Forest;
template <typename T> class Pipe;
template <typename T> class Spike;

template <typename T>
class Obstacle {
protected:
    std::string obstacle;
    int damage;

public:
    virtual ~Obstacle() = default;

    // Constructor
    Obstacle(const std::string &hazard_type = "Obstacle", int new_damage = 100);

    // Copy constructor
    Obstacle(const Obstacle<T> &other);

    // Assignment operator
    Obstacle<T>& operator=(const Obstacle<T> &other);

    const std::string &get_obstacle() const;

    int get_damage() const;

    // Function to interact with Bird<T> (bird must be a templated object)
    virtual void interact(Bird<T> &bird, bool passed) const;

    virtual Obstacle<T>* clone() const = 0;

    // Adăugăm implementarea funcției display() direct în header
    virtual void display() const {
        std::cout << "Obstacle: " << obstacle << ", Damage: " << damage << std::endl;
    }
};

// External friend function
template <typename T>
std::ostream &operator<<(std::ostream &os, const Obstacle<T> &o);

#endif // OBSTACLE_H
