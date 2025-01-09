
#include "GameManager.h"

// Inițializarea instanței statice
GameManager* GameManager::instance = nullptr;

GameManager* GameManager::get_instance() {
    if (instance == nullptr) {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::set_score(int s) {
    score = s;
    notify("Score updated: " + std::to_string(score));
}

int GameManager::get_score() {
    return score;
}

void GameManager::set_level(int l) {
    level = l;
    notify("Level updated: " + std::to_string(level));
}

int GameManager::get_level() {
    return level;
}

void GameManager::reset() {
    score = 0;
    level = 1;
    notify("Game reset");
}

void GameManager::attach(Observer* observer) {
    observers.push_back(observer);
}

void GameManager::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void GameManager::notify(const std::string& message) {
    for (Observer* observer : observers) {
        observer->update(message);
    }
}
