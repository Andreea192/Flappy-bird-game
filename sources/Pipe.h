#ifndef PIPE_H
#define PIPE_H

#include "Obstacle.h"

template <typename T>
class Pipe : public Obstacle<T> {
public:
    // Constructor explicit
    explicit Pipe(int new_damage = 100);

    // Copy Constructor
    Pipe(const Pipe<T>& other);

    // Assignment Operator
    Pipe<T>& operator=(const Pipe<T>& other);

    // Member functions
    void interact(Bird<T>& bird, bool passed) const override;
    void display() const override;
    Obstacle<T>* clone() const override;
};

#endif // PIPE_H
