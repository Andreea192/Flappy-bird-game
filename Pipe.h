#ifndef PIPE_H
#define PIPE_H

#include "Obstacle.h"

class Pipe : public Obstacle {
public:
    // Constructor
    Pipe(int new_damage = 100);

    // Constructor de copiere
    Pipe(const Pipe &other);

    // Operator de atribuire
    Pipe &operator=(const Pipe &other);

    void interact(Bird &bird, bool passed) const override;

    void display() const override;

    Obstacle *clone() const override;
};

#endif // PIPE_H
