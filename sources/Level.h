#ifndef LEVEL_H
#define LEVEL_H

#include "Obstacle.h"
#include <memory>
#include "Spike.h"
#include "Bird.h" // Include Bird.h pentru a folosi Bird<int>

class Level {
private:
    int difficulty;
    std::unique_ptr<Obstacle<int>> obstacle;  // Aici trebuie să specifici tipul Obstacle<int>

public:
    // Constructor implicit
    Level();

    // Constructor cu parametru pentru dificultate
    explicit Level(int newDifficulty);

    // Constructor cu parametri pentru dificultate și obstacol
    Level(int newDifficulty, std::unique_ptr<Obstacle<int>> newObstacle);  // Aici trebuie să fie Obstacle<int>

    // Destructor
    ~Level() = default;

    // Constructor de copiere
    Level(const Level &other);

    // Operator de atribuire
    Level &operator=(Level other);

    Obstacle<int>* getObstacle() const { return obstacle.get(); }

    int getDifficulty() const { return difficulty; }

    void interaction(Bird<int> &bird, bool hasPassed) const;  // Trebuie să folosești Bird<int>

    void display() const;

    // Funcție pentru a returna un pointer la Spike, dacă obstacolul este de acest tip
    Spike<int>* getSpike() const;

    friend void swap(Level &first, Level &second) noexcept;
};

// Operator pentru afișare
std::ostream &operator<<(std::ostream &os, const Level &level);

#endif // LEVEL_H
