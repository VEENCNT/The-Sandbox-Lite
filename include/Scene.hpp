#pragma once

#include <SFML/Graphics.hpp>

#include "Cell.hpp"

namespace Sandbox {
class Scene: public sf::Drawable {
 public:
    Scene();

	Cell& getCell(int x, int y);

	void update();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    static const int kDefaultWidth = 80;
    static const int kDefaultHeight = 60;

 private:
    void updateSand(int x, int y);

    Cell grid[kDefaultWidth][kDefaultHeight];
};
}  // namespace Sandbox
