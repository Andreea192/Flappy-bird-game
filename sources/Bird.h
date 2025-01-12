
#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Bird {
public:
    // Constructor implicit
    Bird();

    // Constructor cu parametri
    Bird(int life, T speed);

    // Constructor de copiere
    Bird(const Bird<T>& other);

    // Operator de atribuire
    Bird<T>& operator=(const Bird<T>& other);

    // Metoda pentru a reduce viața
    void reduce_life(T value);

    // Metoda pentru a reseta viața și viteza
    void reset();

    // Verifică dacă pasărea este vie
    bool is_alive() const;

    // Afișează starea păsării
    void display() const;

    // Verifică viața păsării
    void check_life() const;

    // Ajustează viteza
    void adjust_speed(T factor);

    // Funcție prietenă care poate modifica obiecte de tip Bird
    template <typename U>
    friend void change_bird_speed(Bird<U>& bird, U new_speed);

private:
    int life;
    T speed; // Atribut de tip T care depinde de tipul șablonului
};

// Funcție șablon prietenă
template <typename T>
void change_bird_speed(Bird<T>& bird, T new_speed) {
    bird.adjust_speed(new_speed);
    std::cout << "Bird speed changed to: " << new_speed << std::endl;
}

#endif // BIRD_H
