#pragma once

#include <SFML/Graphics.hpp>

#include "Element.hpp"

namespace Sandbox {
class Scene : public sf::Drawable {
 public:
    Scene();

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    Element& getElement(int x, int y);

    static const int kDefaultWidth = 144;
    static const int kDefaultHeight = 90;

 private:
    void updateSand(int x, int y);
    void updateWater(int x, int y);

    void updateVelocity(int x, int y);

    Element grid[kDefaultWidth][kDefaultHeight];
};
}  // namespace Sandbox
