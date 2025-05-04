#include <vector>
#include <iostream>

#include "../include/Scene.hpp"
#include "../include/Cell.hpp"

int main() {
    sf::RenderWindow window{sf::VideoMode(800, 600), "The Sandbox Lite"};

    Sandbox::Scene scene{};

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
                scene.getCell(i, j).setMaterial(Sandbox::Material::Sand);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            int i = mousePosition.x / Sandbox::Cell::kDefaultWidth;
            int j = mousePosition.y / Sandbox::Cell::kDefaultHeight;

            if (i > 0 && i < Sandbox::Scene::kDefaultWidth && j > 0 && j < Sandbox::Scene::kDefaultHeight) {
                scene.getCell(i, j).setMaterial(Sandbox::Material::None);
            }
        }

        window.clear();

        scene.update();

        window.draw(scene);

        window.display();
    }

    return 0;
}
