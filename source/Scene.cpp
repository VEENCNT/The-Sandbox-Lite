#include "../include/Scene.hpp"
#include "../include/Materials.hpp"

#include <cstdarg>

#include <algorithm>
#include <iostream>

namespace Sandbox {
Scene::Scene() {
    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            grid[x][y].setPosition(sf::Vector2f(Cell::kDefaultWidth * x, Cell::kDefaultHeight * y));
        }
    }
}

void Scene::update() {
    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            if (grid[x][y].getUpdateStatus()) {
                grid[x][y].setUpdateStatus(false);
                continue;
            }
            getMaterialProperties(grid[x][y].getMaterial())->updateFunc(this, x, y);            
        }
    }
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            if (grid[x][y].getMaterial() == Mats::None) {
                continue;
            }

            target.draw(grid[x][y]);
        }
    }
}
}  // namespace Sandbox
