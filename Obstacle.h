#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>
#include "Bird.h"

class Obstacle {
protected:
    std::string obstacle;
    int damage;

public:
    virtual ~Obstacle() = default;

    // Constructor
    Obstacle(const std::string &hazard_type = "Obstacle", int new_damage = 100);

    //Constructor de copiere
    Obstacle(const Obstacle &other);

    // Operator
    Obstacle &operator=(const Obstacle &other);

    const std::string &get_obstacle() const;

    int get_damage() const;

    virtual void interact(Bird &bird, bool passed) const;

    virtual Obstacle *clone() const = 0;

    virtual void display() const = 0;
};


std::ostream &operator<<(std::ostream &os, const Obstacle &o);

#endif // OBSTACLE_H
