#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void update(const std::string& message) = 0;  // Metoda de actualizare
};

#endif // OBSERVER_H
