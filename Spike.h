#ifndef SPIKE_H
#define SPIKE_H

#include "Obstacle.h"

class Spike : public Obstacle {
public:
    // Constructor
    Spike(int new_damage = 200);

    // Constructor de copiere
    Spike(const Spike &other);

    // Operator de atribuire
    Spike &operator=(const Spike &other);

    void interact(Bird &bird, bool passed) const override;

    void display() const override;

    Obstacle *clone() const override;
};

#endif // SPIKE_H
