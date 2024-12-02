#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <memory>

#include "Bird.h"
#include "Exceptions.h"
#include "Menu.h"
#include "Level.h"
#include "Pipe.h"
#include "Spike.h"
#include "Forest.h"

using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;
using Seconds = std::chrono::duration<int>;

void wait_for_key_to_continue() {
    std::cout << "Press 'p' to continue..." << std::endl;
    while (true) {
        if (_kbhit()) {
            char c = _getch();
            if (c == 'p') {
                break; // continue the game
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
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
        // levels >= 4
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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ball Game");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    sf::CircleShape ball(20);
    ball.setFillColor(sf::Color::Red);
    float positionY = 300;
    ball.setPosition(400, positionY);

    Bird bird1;
    Menu menu;
    menu.display_menu();

    int current_level = menu.get_level();
    [[maybe_unused]] int losses = 0;

    while (true) {
        std::cout << "Level " << current_level << ": " << std::endl;

        try {
            bird1.reset();
            Level level(current_level);

            std::unique_ptr<Obstacle> pipe1 = std::make_unique<Pipe>(50);
            std::unique_ptr<Obstacle> spike1 = std::make_unique<Spike>(30);
            std::unique_ptr<Obstacle> forest1 = std::make_unique<Forest>(40);

            while (bird1.is_alive()) {
                int num_pipes = 2 + (current_level / 2);
                for (int i = 0; i < num_pipes; ++i) {
                    int presses_required = required_presses(current_level, i);
                    std::cout << "Press Enter " << presses_required << " times to pass through pipe " << i + 1 << "." <<
                            std::endl;

                    int presses_made = 0;
                    TimePoint last_enter_time = Clock::now();
                    while (presses_made < presses_required) {
                        if (_kbhit()) {
                            char c = _getch();
                            if (c == '\r') {
                                TimePoint current_time = Clock::now();
                                if (std::chrono::duration_cast<Seconds>(current_time - last_enter_time).count() >= 3) {
                                    throw BirdLifeException();
                                }

                                presses_made++;
                                last_enter_time = current_time;
                                std::cout << "Press made: " << presses_made << std::endl;
                            }
                        }

                        TimePoint current_time = Clock::now();
                        if (std::chrono::duration_cast<Seconds>(current_time - last_enter_time).count() >= 2) {
                            presses_made--;
                            last_enter_time = current_time;
                            std::cout << "2 seconds passed! Number of presses reduced: " << presses_made << std::endl;

                            if (presses_made < 0) {
                                throw BirdLifeException();
                            }
                        }
                    }

                    bool passed = (presses_made >= presses_required);
                    level.interaction(bird1, passed);

                    // Check obstacles
                    pipe1->interact(bird1, passed);
                    spike1->interact(bird1, passed);
                    forest1->interact(bird1, passed);

                    // End the level
                    if (!bird1.is_alive()) {
                        std::cout << "You lost this level!" << std::endl;
                        break;
                    }
                }

                // Check if the bird is alive
                if (bird1.is_alive()) {
                    std::cout << "Level completed! Press 'p' to continue to the next level." << std::endl;
                    wait_for_key_to_continue();
                    menu.next_level();
                    current_level = menu.get_level();
                }
            }
        } catch (const InvalidValueException &e) {
            std::cout << "Error: " << e.what() << std::endl;
        } catch (const ImpossibleOperationException &e) {
            std::cout << "Error: " << e.what() << std::endl;
        } catch (const BirdLifeException &) {
            std::cout << "You lost this level!" << std::endl;
            std::cout << "Press 'p' to restart the current level." << std::endl;

            wait_for_key_to_continue();
            continue;
        } catch (const BaseException &e) {
            std::cout << "Unknown error: " << e.what() << std::endl;
        }
    }
}
