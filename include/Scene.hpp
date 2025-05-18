#pragma once

#include <cstdarg>

#include <SFML/Graphics.hpp>

#include "Cell.hpp"

namespace Sandbox {
class Scene : public sf::Drawable {
 public:
    Scene();

    void update();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    inline Cell& getElement(int x, int y);

    static const int kDefaultWidth = 128;
    static const int kDefaultHeight = 90;

 private:
    void updateSand(int x, int y);
    void updateWater(int x, int y);
    void updateGunpowder(int x, int y);
	void updateDiesel(int x, int y);
    void updateFire(int x, int y);
	void updateLava(int x, int y);

	inline bool isCorrectCoordinates(int x, int y);

    inline bool isCorrectMaterial(int x, int y);

    template<typename... Args>
    inline bool isCorrectMaterial(int x, int y, const Material& material, const Args&... args);

    Cell grid[kDefaultWidth][kDefaultHeight];
};

inline Cell& Scene::getElement(int x, int y) {
    return grid[x][y];
}

inline bool Scene::isCorrectCoordinates(int x, int y) {
    return (x >= 0) && (x < kDefaultWidth) && (y >= 0) && (y < kDefaultHeight);
}

inline bool Scene::isCorrectMaterial(int x, int y) {
    return false;
}

template<typename... Args>
inline bool Scene::isCorrectMaterial(int x, int y, const Material& material, const Args&... args) {
    return (grid[x][y].getMaterial() == material) || (isCorrectMaterial(x, y, args...));
}
}  // namespace Sandbox
