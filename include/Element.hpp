#pragma once

#include <SFML/Graphics.hpp>

namespace Sandbox {
enum Material {
    Sand,
    Stone,
    Water,
    None
};

class Element : public sf::Drawable, public sf::Transformable {
 public:
    Element();

    const Material& getMaterial() const;
    void setMaterial(const Material& material);

    bool getUpdateStatus();
    void setUpdateStatus(bool isUpdated);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    static void swapMaterials(Element& first, Element& second);

    static const int kDefaultWidth = 10;
    static const int kDefaultHeight = 10;

 private:
    sf::RectangleShape shape;
    Material material;

    bool isUpdated;
};
}  // namespace Sandbox
