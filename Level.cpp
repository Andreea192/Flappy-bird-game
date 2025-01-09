#include "Level.h"
#include "FOREST.h"
#include <iostream>

// Constructor cu parametru pentru dificultate
Level::Level(int newDifficulty) : difficulty(newDifficulty) {
    // Crearea unui obstacol implicit de tip Forest
    obstacle = std::make_unique<Forest<int>>(50);  // Instanțiem un Forest cu o daună de 50
}

// Constructor cu parametri pentru dificultate și obstacol
Level::Level(int newDifficulty, std::unique_ptr<Obstacle<int>> newObstacle)
    : difficulty(newDifficulty), obstacle(std::move(newObstacle)) {
}

// Constructor de copiere
Level::Level(const Level &other)
    : difficulty(other.difficulty),
      obstacle(other.obstacle ? other.obstacle->clone() : nullptr) {
}

// Operator de atribuire
Level &Level::operator=(Level other) {
    std::swap(*this, other);
    return *this;
}

void swap(Level &first, Level &second) noexcept {
    using std::swap;
    swap(first.difficulty, second.difficulty);
    swap(first.obstacle, second.obstacle);
}

void Level::interaction(Bird<int> &bird, bool hasPassed) const {
    if (obstacle) {
        obstacle->interact(bird, hasPassed);  // Folosim interact cu Bird<int>
    }
}

void Level::display() const {
    std::cout << "Level [Difficulty: " << difficulty << "] ";
    if (obstacle) {
        obstacle->display();
    }
    std::cout << std::endl;
}

Spike<int>* Level::getSpike() const {
    return dynamic_cast<Spike<int>*>(obstacle.get());  // Returnează un pointer la Spike dacă este cazul
}

std::ostream &operator<<(std::ostream &os, const Level &level) {
    os << "Level [Difficulty: " << level.getDifficulty() << "] ";
    if (level.getObstacle()) {
        level.getObstacle()->display();
    }
    return os;
}
