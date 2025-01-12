#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"

class GameManager {
private:
    static GameManager* instance;  // Declarăm variabila statică
    int score;
    int level;
    std::vector<Observer*> observers;

    // Constructor privat pentru a preveni instanțierea directă
    GameManager() : score(0), level(1) {}

public:
    static GameManager* get_instance();  // Declarăm funcția pentru a obține instanța

    void set_score(int s);
    int get_score();

    void set_level(int l);
    int get_level();

    void reset();

    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(const std::string& message);
};

#endif // GAMEMANAGER_H
