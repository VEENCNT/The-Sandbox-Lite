#pragma once

#include <SFML/Graphics.hpp>

namespace Sandbox {
enum Material {
    Stone,
    Sand,
    Water,
    Wick,
    Gunpowder,
    Diesel,
    Fire,
    DullFire,
    Lava,
    DullLava,
    None
};

class Cell : public sf::Drawable, public sf::Transformable {
 public:
    Cell();

    const Material& getMaterial() const;
    void setMaterial(const Material& material);

    bool getUpdateStatus();
    void setUpdateStatus(bool isUpdated);

    int getHealth() const;
    void setHealth(int health);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    static void swap(Cell& first, Cell& second);

    static const int kDefaultWidth = 10;
    static const int kDefaultHeight = 10;

 private:
    sf::RectangleShape shape;
    Material material;

    bool isUpdated;

    int health;
};
}  // namespace Sandbox
