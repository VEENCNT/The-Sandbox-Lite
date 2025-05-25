#pragma once

#include <SFML/Graphics.hpp>

namespace Sandbox {
enum Mats : int {
    Stone = 1,
    Sand,
    Water,
    Wick,
    Gunpowder,
    Diesel,
    Fire,
    DullFire,
    Lava,
    DullLava,
    Smoke,
    DullSmoke,
    None
};

class Cell : public sf::Drawable, public sf::Transformable {
 public:
    Cell();

    inline const Mats& getMaterial() const;
    void setMaterial(const Mats& material);

    inline bool getUpdateStatus() const;
    void setUpdateStatus(bool isUpdated);

    inline int getHealth() const;
    void setHealth(int health);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    static void swap(Cell& first, Cell& second);

    static const int kDefaultWidth = 10;
    static const int kDefaultHeight = 10;

 private:
    sf::RectangleShape shape;
    Mats material;

    bool isUpdated;

    int health;
};

inline const Mats& Cell::getMaterial() const {
    return material;
}

inline bool Cell::getUpdateStatus() const {
    return isUpdated;
}

inline int Cell::getHealth() const {
    return health;
}
}  // namespace Sandbox
