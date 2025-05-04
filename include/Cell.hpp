#pragma once

#include <SFML/Graphics.hpp>

namespace Sandbox {
enum Material {
    Sand,
    Stone,
    Water,
    None
};

class Cell : public sf::Drawable, public sf::Transformable {
 public:
    Cell();

    const Material& getMaterial() const;
    void setMaterial(const Material& material);

    const sf::Vector2f& getVelocity() const;
    void setVelocity(const sf::Vector2f& velocity);

    bool isUpdated();

    void update();
    void reset();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    static const int kDefaultWidth = 10;
    static const int kDefaultHeight = 10;

 private:
    sf::RectangleShape shape;
    Material material;

    sf::Vector2f velocity;
    bool updated;
};
}  // namespace Sandbox
