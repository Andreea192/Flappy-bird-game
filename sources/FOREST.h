#ifndef FOREST_H
#define FOREST_H

#include "Obstacle.h"
#include "Bird.h"

template <typename T>
class Forest : public Obstacle<T> {
public:
    // Constructor explicit
    explicit Forest(int new_damage = 50);

    // Constructor de copiere
    Forest(const Forest<T> &other);

    // Funcție pentru interacțiunea cu pasărea
    void interact(Bird<T> &bird, bool passed) const override;

    // Funcție pentru a afișa detalii despre forest
    void display() const override;

    // Funcție pentru a crea o copie a forest
    Obstacle<T> *clone() const override;
};

// Operator << pentru afișare
template <typename T>
std::ostream &operator<<(std::ostream &os, const Forest<T> &f);

#endif // FOREST_H
