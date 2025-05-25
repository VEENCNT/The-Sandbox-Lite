#include "../include/Cell.hpp"
#include "../include/Materials.hpp"

namespace Sandbox {
Cell::Cell(): shape(sf::Vector2f(kDefaultWidth, kDefaultHeight)) {
    setMaterial(Mats::None);
    setHealth(0);
    setUpdateStatus(false);
}

void Cell::setMaterial(const Mats& material) {
    this->material = material;
    const Material* props = getMaterialProperties(material);
    if (props == nullptr) {
        shape.setFillColor(sf::Color(0, 0, 0));
        setHealth(0);
        return;
    }
    shape.setFillColor(props->color);
    setHealth(props->default_lifetime);
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
    Mats firstMaterial = first.getMaterial();
    Mats secondMaterial = second.getMaterial();

    int firstHealth = first.getHealth();
    int secondHealth = second.getHealth();

    first.setMaterial(secondMaterial);
    second.setMaterial(firstMaterial);

    first.setHealth(secondHealth);
    second.setHealth(firstHealth);
}

}
