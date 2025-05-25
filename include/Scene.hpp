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

    inline Cell& getCell(int x, int y);

    static const int kDefaultWidth = 128;
    static const int kDefaultHeight = 90;

    inline bool isCorrectCoordinates(int x, int y);
    inline bool isCorrectMaterial(int x, int y);
    template<typename... Args>
    inline bool isCorrectMaterial(int x, int y, const Mats& material, const Args&... args);
    bool checkNeighborsForMaterial(int x, int y, const Mats mat);

 private:
    Cell grid[kDefaultWidth][kDefaultHeight];
};

inline Cell& Scene::getCell(int x, int y) {
    return grid[x][y];
}

inline bool Scene::isCorrectCoordinates(int x, int y) {
    return (x >= 0) && (x < kDefaultWidth) && (y >= 0) && (y < kDefaultHeight);
}

inline bool Scene::isCorrectMaterial(int x, int y) {
    return false;
}

inline bool Scene::checkNeighborsForMaterial(int x, int y, const Mats mat) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0)
                continue;
            if (isCorrectCoordinates(x + dx, y + dy) && grid[x + dx][y + dy].getMaterial() == mat) {
                return true;
            }
        }
    }
    return false;
}

template<typename... Args>
inline bool Scene::isCorrectMaterial(int x, int y, const Mats& material, const Args&... args) {
    return (grid[x][y].getMaterial() == material) || (isCorrectMaterial(x, y, args...));
}
}  // namespace Sandbox
