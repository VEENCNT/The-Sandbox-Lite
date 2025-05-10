#include "../include/Scene.hpp"

#include <algorithm>
#include <iostream>

namespace Sandbox {
Scene::Scene() {
    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            grid[x][y].setPosition(sf::Vector2f(Element::kDefaultWidth * x, Element::kDefaultHeight * y));
        }
    }
}

void Scene::update() {
    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            grid[x][y].setUpdateStatus(false);
        }
    }

    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            if (grid[x][y].getUpdateStatus()) {
                continue;
            }

            switch (grid[x][y].getMaterial()) {
                case Material::Sand:
                    updateSand(x, y);
                    break;
                case Material::Water:
                    updateWater(x, y);
                    break;
                default:
                    break;
            }
        }
    }
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            target.draw(grid[x][y]);
        }
    }
}

Element& Scene::getElement(int x, int y) {
    return grid[x][y];
}

void Scene::updateSand(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (x > 0 && x < kDefaultWidth - 1 && y + 1 < kDefaultHeight && grid[x][y + 1].getMaterial() == Material::None) {
        nextX = x;
        nextY = y + 1;
    } else if (x + 1 < kDefaultWidth && y + 1 < kDefaultHeight && grid[x + 1][y + 1].getMaterial() == Material::None) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (x > 0 && y + 1 < kDefaultHeight && grid[x - 1][y + 1].getMaterial() == Material::None) {
        nextX = x - 1;
        nextY = y + 1;
    }

    if (x > 0 && x < kDefaultWidth - 1 && y + 1 < kDefaultHeight && grid[x][y + 1].getMaterial() == Material::Water) {
        nextX = x;
        nextY = y + 1;
    } else if (x + 1 < kDefaultWidth && y + 1 < kDefaultHeight && grid[x + 1][y + 1].getMaterial() == Material::Water) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (x > 0 && y + 1 < kDefaultHeight && grid[x - 1][y + 1].getMaterial() == Material::Water) {
        nextX = x - 1;
        nextY = y + 1;
    }

    Element::swapMaterials(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateWater(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (x > 0 && x < kDefaultWidth - 1 && y + 1 < kDefaultHeight && grid[x][y + 1].getMaterial() == Material::None) {
        nextX = x;
        nextY = y + 1;
    } else if (x + 1 < kDefaultWidth && y + 1 < kDefaultHeight && grid[x + 1][y + 1].getMaterial() == Material::None) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (x - 1 >= 0 && y + 1 < kDefaultHeight && grid[x - 1][y + 1].getMaterial() == Material::None) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (x + 1 < kDefaultWidth && grid[x + 1][y].getMaterial() == Material::None) {
        nextX = x + 1;
        nextY = y;
    } else if (x - 1 >= 0 && grid[x - 1][y].getMaterial() == Material::None) {
        nextX = x - 1;
        nextY = y;
    }

    Element::swapMaterials(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

}  // namespace Sandbox
