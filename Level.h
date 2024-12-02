#ifndef LEVEL_H
#define LEVEL_H

#include "Obstacle.h"
#include <memory>
#include "Spike.h"

class Level {
private:
    int difficulty;
    std::unique_ptr<Obstacle> obstacle;

public:
    // Constructor implicit
    Level();

    // Constructor cu parametru pentru dificultate
    explicit Level(int newDifficulty);

    // Constructor cu parametri pentru dificultate și obstacol
    Level(int newDifficulty, std::unique_ptr<Obstacle> newObstacle);

    // Destructor
    ~Level() = default;

    // Constructor de copiere
    Level(const Level &other);

    // Operator de atribuire
    Level &operator=(Level other);

    Obstacle *getObstacle() const { return obstacle.get(); }

    int getDifficulty() const { return difficulty; }

    void interaction(Bird &bird, bool hasPassed) const;

    void display() const;

    // Funcție pentru a returna un pointer la Spike, dacă obstacolul este de acest tip
    Spike *getSpike() const;

    friend void swap(Level &first, Level &second) noexcept;
};

// Operator pentru afișare
std::ostream &operator<<(std::ostream &os, const Level &level);

#endif // LEVEL_H
