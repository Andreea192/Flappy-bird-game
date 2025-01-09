#ifndef GAMEMANAGEROBSERVER_H
#define GAMEMANAGEROBSERVER_H

#include "Observer.h"
#include <iostream>

class GameManagerObserver : public Observer {
public:
    virtual void update(const std::string& message) override {
        std::cout << "Game Manager State Changed: " << message << std::endl;
    }
};

#endif // GAMEMANAGEROBSERVER_H
