#include <iostream>
#include <string>

#include "../include/Scene.hpp"
#include "../include/Cell.hpp"

int main() {
    sf::RenderWindow window{sf::VideoMode(1280, 900), "The Sandbox Lite"};

    window.setFramerateLimit(90);

    Sandbox::Scene scene{};

    sf::Font font;
    font.loadFromFile("../arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);

    sf::Clock clock{};

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            int i = mousePosition.x / Sandbox::Cell::kDefaultWidth;
            int j = mousePosition.y / Sandbox::Cell::kDefaultHeight;

            if (i > 0 && i < Sandbox::Scene::kDefaultWidth && j > 0 && j < Sandbox::Scene::kDefaultHeight) {
                scene.getElement(i, j).setMaterial(Sandbox::Material::Sand);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            int i = mousePosition.x / Sandbox::Cell::kDefaultWidth;
            int j = mousePosition.y / Sandbox::Cell::kDefaultHeight;

            if (i > 0 && i < Sandbox::Scene::kDefaultWidth && j > 0 && j < Sandbox::Scene::kDefaultHeight) {
                scene.getElement(i, j).setMaterial(Sandbox::Material::Lava);
            }
        }

        window.clear();

        scene.update();

        sf::Time elapsed = clock.restart();

        text.setString(std::to_string(1 / elapsed.asSeconds()));

        window.draw(scene);

        window.draw(text);

        window.display();

    }

    return 0;
}
