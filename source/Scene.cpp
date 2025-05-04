#include "../include/Scene.hpp"

#include <algorithm>

namespace Sandbox {
Scene::Scene() {
    for (int i = 0; i < kDefaultWidth; ++i) {
        for (int j = 0; j < kDefaultHeight; ++j) {
            grid[i][j].setPosition(sf::Vector2f(Cell::kDefaultWidth * i, Cell::kDefaultHeight * j));
        }
    }
}

Cell& Scene::getCell(int x, int y) {
    return grid[x][y];
}

void Scene::update() {
    for (int i = 0; i < kDefaultWidth; ++i) {
        for (int j = 0; j < kDefaultHeight; ++j) {
            grid[i][j].reset();
        }
    }

    for (int i = 0; i < kDefaultWidth; ++i) {
        for (int j = 0; j < kDefaultHeight; ++j) {
            if (grid[i][j].isUpdated()) {
                continue;
            }

            switch (grid[i][j].getMaterial()) {
                case Material::Sand:
                    updateSand(i, j);
                    break;
                default:
                    break;
            }
        }
    }
}

void Scene::updateSand(int x, int y) {
    if (y + 1 >= kDefaultHeight) {
        grid[x][y].update();
        return;
    }

    if (x == 0) {
        if (grid[x][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x][y + 1].setMaterial(Material::Sand);
            grid[x][y + 1].update();

            return;
        } else if (grid[x + 1][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x + 1][y + 1].setMaterial(Material::Sand);
            grid[x + 1][y + 1].update();

            return;
        }
    }

    if (x == kDefaultWidth - 1) {
        if (grid[x][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x][y + 1].setMaterial(Material::Sand);
            grid[x][y + 1].update();

            return;
        } else if (grid[x - 1][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x - 1][y + 1].setMaterial(Material::Sand);
            grid[x - 1][y + 1].update();

            return;
        }
    }

    if ((x > 0) && (x < kDefaultWidth - 1)) {
        if (grid[x][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x][y + 1].setMaterial(Material::Sand);
            grid[x][y + 1].update();

            return;
        } else if (grid[x + 1][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x + 1][y + 1].setMaterial(Material::Sand);
            grid[x + 1][y + 1].update();

            return;
        } else if (grid[x - 1][y + 1].getMaterial() == Material::None) {
            grid[x][y].setMaterial(Material::None);
            grid[x][y].update();

            grid[x - 1][y + 1].setMaterial(Material::Sand);
            grid[x - 1][y + 1].update();

            return;
        }
    }

    grid[x][y].update();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (int i = 0; i < kDefaultWidth; ++i) {
        for (int j = 0; j < kDefaultHeight; ++j) {
            target.draw(grid[i][j]);
        }
    }
}
}  // namespace Sandbox
