#include "Menu.h"

int Menu::instance_count = 0;

// Constructor implicit
Menu::Menu() {
    colors[0] = "Red";
    colors[1] = "Green";
    colors[2] = "Blue";
    colors[3] = "Yellow";
    current_level = 1;
    instance_count++;
}

// Constructor de copiere
Menu::Menu(const Menu &other) {
    for (int i = 0; i < 4; ++i) {
        colors[i] = other.colors[i];
    }
    current_level = other.current_level;
    instance_count++;
}

// Operator de atribuire
Menu &Menu::operator=(const Menu &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            colors[i] = other.colors[i];
        }
        current_level = other.current_level;
    }
    return *this;
}

// Destructor
Menu::~Menu() {
    instance_count--;
}

int Menu::get_instance_count() {
    return instance_count;
}

void Menu::display_menu() {
    std::cout << "Select a color for the bird: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ". " << colors[i] << std::endl;
    }
    std::cout << "Select the level " << current_level << ": ";
    int selected_level;
    std::cin >> selected_level;
    if (selected_level > 0 && selected_level <= current_level) {
        current_level = selected_level;
    } else {
        std::cout << "Invalid level! The current level will be used: " << current_level << std::endl;
    }
}

// Get current level
int Menu::get_level() const {
    return current_level;
}

void Menu::next_level() {
    current_level++;
}

void Menu::reset_level() {
    current_level = 1;
}

std::ostream &operator<<(std::ostream &os, const Menu &m) {
    os << "Menu [current level: " << m.current_level << "]";
    return os;
}
