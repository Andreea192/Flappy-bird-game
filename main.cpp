#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <memory>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

char getch() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

#include "Bird.h"
#include "Exceptions.h"
#include "Menu.h"
#include "Level.h"
#include "Pipe.h"
#include "Spike.h"
#include "FOREST.h"
#include "Factory.h"
#include "GameManager.h"
#include "GameManagerObserver.h"

using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;
using Seconds = std::chrono::duration<int>;

void wait_for_key_to_continue() {
    std::cout << "Press 'p' to continue..." << std::endl;
    while (true) {
        if (kbhit()) {
            char c = getch();
            if (c == 'p') {
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int required_presses(int level, int pipe_index) {
    if (level == 1) {
        return 3;
    } else if (level == 2) {
        return 2;
    } else if (level == 3) {
        return 4;
    } else {
        if (pipe_index % 4 == 0) {
            return 3;
        } else if (pipe_index % 4 == 1 || pipe_index % 4 == 2) {
            return 2;
        } else {
            return 4;
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy Bird Game");
    sf::CircleShape bird_shape(20);
    bird_shape.setFillColor(sf::Color::Yellow);
    float bird_y = 300;
    bird_shape.setPosition(400, bird_y);

    Bird<int> bird(100, 5); // Pasărea începe cu viața 100 și viteza 5
    Menu menu;
    menu.display_menu();

    int current_level = menu.get_level();
    int losses = 0;

    GameManagerObserver observer;
    GameManager* gameManager = GameManager::get_instance();
    gameManager->attach(&observer);

    wait_for_key_to_continue();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        try {
            bird.reset();
            Level level(current_level);

            // Exemplu: Utilizare funcția getSpike
            Spike<int>* spike = level.getSpike();
            if (spike) {
                spike->interact(bird, false);
            }

            // Exemplu: Utilizare get_instance_count
            std::cout << "Number of menu instances: " << Menu::get_instance_count() << std::endl;

            level.interaction(bird, true);

            // Simulare obstacole
            std::unique_ptr<Obstacle<int>> obstacle1 = ObstacleFactory<int>::create_obstacle("Pipe", 50);
            std::unique_ptr<Obstacle<int>> obstacle2 = ObstacleFactory<int>::create_obstacle("Spike", 30);
            std::unique_ptr<Obstacle<int>> obstacle3 = ObstacleFactory<int>::create_obstacle("Forest", 40);

            while (bird.is_alive()) {
                int num_pipes = 2 + (current_level / 2);

                for (int i = 0; i < num_pipes; ++i) {
                    int presses_required = required_presses(current_level, i);
                    std::cout << "Press Enter " << presses_required << " times to pass pipe " << i + 1 << "." << std::endl;

                    int presses_made = 0;
                    TimePoint last_enter_time = Clock::now();

                    while (presses_made < presses_required) {
                        TimePoint current_time = Clock::now();

                        if (std::chrono::duration_cast<Seconds>(current_time - last_enter_time).count() >= 3) {
                            presses_made--;
                            std::cout << "Presses reduced! Current presses: " << presses_made << std::endl;
                            last_enter_time = current_time;

                            if (presses_made < 0) {
                                bird.check_life(); // Verificare viață pasăre
                                throw BirdLifeException();
                            }
                        }

                        if (kbhit()) {
                            char c = getch();
                            if (c == '\r') {
                                presses_made++;
                                last_enter_time = Clock::now();
                                std::cout << "Press made: " << presses_made << std::endl;
                            }
                        }
                    }

                    bird.adjust_speed(1);
                    change_bird_speed(bird, 15);
                    obstacle1->interact(bird, presses_made >= presses_required);
                }
            }

            current_level++;
            gameManager->set_level(current_level); // Actualizare nivel
            gameManager->set_score(current_level * 100); // Actualizare scor
            menu.next_level(); // Utilizare funcția next_level
            std::cout << "Level complete! Moving to Level " << current_level << "." << std::endl;
            std::cout << "Current score: " << gameManager->get_score() << std::endl;
            wait_for_key_to_continue();

        } catch (const BirdLifeException&) {
            std::cout << "Bird died! Restarting current level." << std::endl;
            losses++;
            if (losses >= 3) {
                std::cout << "3 losses! Restarting at Level 1." << std::endl;
                current_level = 1;
                losses = 0;
                menu.reset_level(); // Resetare nivel
            }
            wait_for_key_to_continue();
        }
    }
    gameManager->detach(&observer);
    return 0;
}
