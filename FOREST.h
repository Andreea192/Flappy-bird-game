#ifndef FOREST_H
#define FOREST_H

#include "Obstacle.h"

class Forest : public Obstacle {
public:
    // Constructor
    Forest(int new_damage = 50);

    // Constructor de copiere
    Forest(const Forest &other);

    // Operator de atribuire
    Forest &operator=(Forest other);

    void interact(Bird &bird, bool passed) const override;

    void display() const override;

    Obstacle *clone() const override;

    int damage;
};

// Output operator pentru Forest
std::ostream &operator<<(std::ostream &os, const Forest &f);

#endif // FOREST_H
