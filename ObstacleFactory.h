//
#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H

#include "Spike.h"
#include "Pipe.h"
#include "Forest.h"
#include <memory>
#include <string>

template <typename T>
class ObstacleFactory {
public:
    static std::unique_ptr<Obstacle<T>> create_obstacle(const std::string& obstacle_type, int damage) {
        if (obstacle_type == "Spike") {
            return std::make_unique<Spike<T>>(damage);
        } else if (obstacle_type == "Pipe") {
            return std::make_unique<Pipe<T>>(damage);
        } else if (obstacle_type == "Forest") {
            return std::make_unique<Forest<T>>(damage);
        } else {
            throw std::invalid_argument("Unknown obstacle type: " + obstacle_type);
        }
    }
};

#endif // OBSTACLE_FACTORY_H
