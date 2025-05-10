#include "../include/Element.hpp"

namespace Sandbox {
Element::Element(): shape(sf::Vector2f(kDefaultWidth, kDefaultHeight)), material(Material::None), isUpdated(false) {}

const Material& Element::getMaterial() const {
    return material;
}

void Element::setMaterial(const Material& material) {
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

bool Element::getUpdateStatus() {
    return isUpdated;
}

void Element::setUpdateStatus(bool isUpdated) {
    this->isUpdated = isUpdated;
}

void Element::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (material == Material::None) {
        return;
    }

    states.transform *= getTransform();

    target.draw(shape, states);
}

void Element::swapMaterials(Element& first, Element& second) {
    Material firstMaterial = first.getMaterial();
    Material secondMaterial = second.getMaterial();

    first.setMaterial(secondMaterial);
    second.setMaterial(firstMaterial);
}

}
