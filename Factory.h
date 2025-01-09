#ifndef FACTORY_H
#define FACTORY_H

#include "Spike.h"
#include "Pipe.h"
#include "FOREST.h"
#include <memory>

template <typename T>
class ObstacleFactory {
public:
    static std::unique_ptr<Obstacle<T>> create_obstacle(const std::string& type, int damage) {
        if (type == "Spike") {
            return std::make_unique<Spike<T>>(damage);  // Crează un Spike cu daunele specificate
        } else if (type == "Pipe") {
            return std::make_unique<Pipe<T>>(damage);  // Crează un Pipe cu daunele specificate
        } else if (type == "Forest") {
            return std::make_unique<Forest<T>>(damage);  // Crează un Forest cu daunele specificate
        }
        return nullptr;  // Dacă tipul nu este valid, returnează nullptr
    }
};

#endif // FACTORY_H
