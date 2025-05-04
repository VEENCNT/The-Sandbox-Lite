#include "../include/Cell.hpp"

namespace Sandbox {
Cell::Cell(): shape(sf::Vector2f(kDefaultWidth, kDefaultHeight)), material(Material::None), velocity(0.0f, 0.0f), updated(false) {}

const Material& Cell::getMaterial() const {
    return material;
}

void Cell::setMaterial(const Material& material) {
    this->material = material;

    switch (material) {
        case Material::Sand:
            shape.setFillColor(sf::Color(252, 221, 118));
            break;
        case Material::Stone:
            shape.setFillColor(sf::Color(90, 86, 83));
            break;
        case Material::Water:
            shape.setFillColor(sf::Color(35, 137, 218));
            break;
        case Material::None:
            break;
    }
}

const sf::Vector2f& Cell::getVelocity() const {
    return velocity;
}

void Cell::setVelocity(const sf::Vector2f& velocity) {
    this->velocity = velocity;
}

bool Cell::isUpdated() {
    return updated;
}

void Cell::update() {
    this->updated = true;
}

void Cell::reset() {
    this->updated = false;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (material == Material::None) {
        return;
    }

    states.transform *= getTransform();

    target.draw(shape, states);
}

}
