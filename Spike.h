#ifndef SPIKE_H
#define SPIKE_H

#include "Obstacle.h"
#include "Bird.h" // Include Bird.h pentru a putea folosi Bird în interacțiune

template <typename T>
class Spike : public Obstacle<T> {
public:
    // Constructor explicit
    explicit Spike(int new_damage = 200);

    // Constructor de copiere
    Spike(const Spike<T> &other);

    // Operator de atribuire
    Spike &operator=(const Spike<T> &other);

    // Metoda interactivă
    void interact(Bird<T> &bird, bool passed) const override;

    // Afisare detalii
    void display() const override;

    // Clonare
    Obstacle<T> *clone() const override;
};

#endif // SPIKE_H
