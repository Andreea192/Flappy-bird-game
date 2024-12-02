#ifndef BIRD_H
#define BIRD_H

#include <ostream>

class Bird {
    int life;

public:
    Bird(); // Constructor implicit
    Bird(const Bird &other); // Constructor de copiere
    Bird &operator=(const Bird &other); // Operator de atribuire
    ~Bird() = default; // Destructor implicit

    void reduce_life(int value);

    void reset();

    [[nodiscard]] bool is_alive() const;

    void display() const;

    void interact() const;

    void check_life() const;

    friend std::ostream &operator<<(std::ostream &os, const Bird &b);
};

#endif // BIRD_H
