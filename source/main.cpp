#include <iostream>
#include <string>

#include "../include/Scene.hpp"
#include "../include/Cell.hpp"

int main() {
    sf::RenderWindow window{sf::VideoMode(1280, 900), "The Sandbox Lite"};
    window.setFramerateLimit(90);

    Sandbox::Scene scene{};

    Sandbox::Material brushMaterial = Sandbox::Material::Stone;

    sf::Font font;
    font.loadFromFile("../PixelizerBold.ttf");

    sf::Text brushInfo;
    brushInfo.setFont(font);
    brushInfo.setStyle(sf::Text::Bold);
    brushInfo.setCharacterSize(36);
    brushInfo.setFillColor(sf::Color::White);
    brushInfo.setPosition(sf::Vector2f(10.0f, 10.0f));
    brushInfo.setString("Stone");

    sf::Text fpsInfo;
    fpsInfo.setFont(font);
    fpsInfo.setCharacterSize(12);
    fpsInfo.setFillColor(sf::Color::White);
    fpsInfo.setPosition(sf::Vector2f(10.0f, 52.0f));

    sf::Clock clock{};

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
            brushMaterial = Sandbox::Material::Stone;
            brushInfo.setString("Stone");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
            brushMaterial = Sandbox::Material::Sand;
            brushInfo.setString("Sand");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
            brushMaterial = Sandbox::Material::Water;
            brushInfo.setString("Water");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
            brushMaterial = Sandbox::Material::Wick;
            brushInfo.setString("Wick");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
            brushMaterial = Sandbox::Material::Gunpowder;
            brushInfo.setString("Gunpowder");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) {
            brushMaterial = Sandbox::Material::Diesel;
            brushInfo.setString("Diesel");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7)) {
            brushMaterial = Sandbox::Material::Fire;
            brushInfo.setString("Fire");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8)) {
            brushMaterial = Sandbox::Material::Lava;
            brushInfo.setString("Lava");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)) {
            brushMaterial = Sandbox::Material::Smoke;
            brushInfo.setString("Smoke");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10)) {
            brushMaterial = Sandbox::Material::Acid;
            brushInfo.setString("Acid");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
            brushMaterial = Sandbox::Material::Metal;
            brushInfo.setString("Metal");
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            int i = mousePosition.x / Sandbox::Cell::kDefaultWidth;
            int j = mousePosition.y / Sandbox::Cell::kDefaultHeight;

            if (i > 0 && i < Sandbox::Scene::kDefaultWidth && j > 0 && j < Sandbox::Scene::kDefaultHeight) {
                scene.getElement(i, j).setMaterial(brushMaterial);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            int i = mousePosition.x / Sandbox::Cell::kDefaultWidth;
            int j = mousePosition.y / Sandbox::Cell::kDefaultHeight;

            if (i > 0 && i < Sandbox::Scene::kDefaultWidth && j > 0 && j < Sandbox::Scene::kDefaultHeight) {
                scene.getElement(i, j).setMaterial(Sandbox::Material::None);
            }
        }

        window.clear();

        scene.update();

        sf::Time elapsed = clock.restart();

        fpsInfo.setString(std::to_string(1 / elapsed.asSeconds()));

        window.draw(scene);

        window.draw(brushInfo);

        window.draw(fpsInfo);

        window.display();

    }

    return 0;
}
