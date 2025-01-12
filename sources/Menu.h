#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

class Menu {
private:
    static int instance_count;
    std::string colors[4];
    int current_level;

public:
    Menu(); // Constructor implicit
    Menu(const Menu &other); // Constructor de copiere
    Menu &operator=(const Menu &other); // Operator de atribuire

    ~Menu(); // Destructor

    static int get_instance_count();

    void display_menu();

    [[nodiscard]] int get_level() const;

    void next_level();

    void reset_level();

    friend std::ostream &operator<<(std::ostream &os, const Menu &m);
};

#endif // MENU_H
