#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Cell.hpp"

namespace Sandbox {
class Scene : public sf::Drawable {
 public:
    Scene();

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    Cell& getElement(int x, int y);

    static const int kDefaultWidth = 144;
    static const int kDefaultHeight = 90;

 private:
    void updateSand(int x, int y);
    void updateWater(int x, int y);
    void updateGunpowder(int x, int y);
	void updateDiesel(int x, int y);
    void updateFire(int x, int y);
	void updateLava(int x, int y);

	bool isCorrectCoordinates(int x, int y);
    bool isCorrectMaterial(int x, int y, const std::vector<Material>& materials);

    Cell grid[kDefaultWidth][kDefaultHeight];
};
}  // namespace Sandbox
