#include "../include/Cell.hpp"

namespace Sandbox {
Cell::Cell(): shape(sf::Vector2f(kDefaultWidth, kDefaultHeight)) {
    setMaterial(Material::None);
    setHealth(0);
    setUpdateStatus(false);
}

void Cell::setMaterial(const Material& material) {
    this->material = material;

    switch (material) {
        case Material::Stone:
            shape.setFillColor(sf::Color(90, 86, 83));
            setHealth(1000);
            break;
        case Material::Sand:
            shape.setFillColor(sf::Color(252, 221, 118));
            setHealth(100);
            break;
        case Material::Water:
            shape.setFillColor(sf::Color(35, 137, 218));
            setHealth(10);
            break;
        case Material::Wick:
            shape.setFillColor(sf::Color(78,53,36));
            setHealth(1);
            break;
        case Material::Gunpowder:
            shape.setFillColor(sf::Color(128, 128, 128));
            setHealth(3);
            break;
        case Material::Diesel:
            shape.setFillColor(sf::Color(237,255,33));
            setHealth(2);
            break;
        case Material::Fire:
            shape.setFillColor(sf::Color(204, 170, 0));
            setHealth(10);
            break;
        case Material::DullFire:
            shape.setFillColor(sf::Color(230, 38, 0));
            setHealth(3);
            break;
        case Material::Lava:
            shape.setFillColor(sf::Color(255, 66, 32));
            setHealth(100);
            break;
        case Material::DullLava:
            shape.setFillColor(sf::Color(255, 16, 32));
            setHealth(100);
            break;
        case Material::Smoke:
            shape.setFillColor(sf::Color(220, 220, 220));
            setHealth(120);
            break;
        case Material::DullSmoke:
            shape.setFillColor(sf::Color(169, 169, 169));
            setHealth(80);
            break;
        case Material::Acid:
            shape.setFillColor(sf::Color(50, 255, 50));
            setHealth(200);
            break;
        case Material::DullAcid:
            shape.setFillColor(sf::Color(30, 150, 30));
            setHealth(100);
            break;
        case Material::None:
            shape.setFillColor(sf::Color(0, 0, 0));
            setHealth(0);
            break;
    }
}

void Cell::setUpdateStatus(bool isUpdated) {
    this->isUpdated = isUpdated;
}

void Cell::setHealth(int lifetime) {
    this->health = lifetime;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(shape, states);
}

void Cell::swap(Cell& first, Cell& second) {
    Material firstMaterial = first.getMaterial();
    Material secondMaterial = second.getMaterial();

    int firstHealth = first.getHealth();
    int secondHealth = second.getHealth();

    first.setMaterial(secondMaterial);
    second.setMaterial(firstMaterial);

    first.setHealth(secondHealth);
    second.setHealth(firstHealth);
}

}
