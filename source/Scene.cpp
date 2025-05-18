#include "../include/Scene.hpp"

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

            switch (grid[x][y].getMaterial()) {
                case Material::Stone:
                    break;
                case Material::Sand:
                    updateSand(x, y);
                    break;
                case Material::Water:
                    updateWater(x, y);
                    break;
                case Material::Wick:
                    break;
                case Material::Gunpowder:
                    updateGunpowder(x, y);
                    break;
                case Material::Diesel:
                    updateDiesel(x, y);
                    break;
                case Material::Fire:
                    updateFire(x, y);
                    break;
                case Material::DullFire:
                    updateFire(x, y);
                    break;
                case Material::Lava:
                    updateLava(x, y);
                    break;
                case Material::DullLava:
                    updateLava(x, y);
                    break;
                case Material::Smoke:
                    updateSmoke(x, y);
                    break;
                case Material::DullSmoke:
                    updateSmoke(x, y);
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
            if (grid[x][y].getMaterial() == Material::None) {
                continue;
            }

            target.draw(grid[x][y]);
        }
    }
}

void Scene::updateSand(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::None, Material::Water, Material::Diesel)) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::None, Material::Water, Material::Diesel)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::None, Material::Water, Material::Diesel)) {
        nextX = x - 1;
        nextY = y + 1;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(false);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateWater(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::None)) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::None)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::None)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::None)) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::None)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(false);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateGunpowder(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::None, Material::Water, Material::Diesel)) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::None, Material::Water, Material::Diesel)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::None, Material::Water, Material::Diesel)) {
        nextX = x - 1;
        nextY = y + 1;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(false);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateDiesel(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::None, Material::Water)) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::None, Material::Water)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::None, Material::Water)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::None, Material::Water)) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::None, Material::Water)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(false);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateFire(int x, int y) {
    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x][y - 1].setHealth(grid[x][y - 1].getHealth() - 1);

        if (grid[x][y - 1].getHealth() == 0) {
            grid[x][y - 1].setMaterial(Material::Fire);
            grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, Material::Water)) {
        grid[x][y - 1].setHealth(grid[x][y - 1].getHealth() - 1);

        if (grid[x][y - 1].getHealth() == 0) {
            grid[x][y - 1].setMaterial(Material::Smoke);
            grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x + 1][y - 1].setHealth(grid[x + 1][y - 1].getHealth() - 1);

        if (grid[x + 1][y - 1].getHealth() == 0) {
            grid[x + 1][y - 1].setMaterial(Material::Fire);
            grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, Material::Water)) {
        grid[x + 1][y - 1].setHealth(grid[x + 1][y - 1].getHealth() - 1);

        if (grid[x + 1][y - 1].getHealth() == 0) {
            grid[x + 1][y - 1].setMaterial(Material::Smoke);
            grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Fire);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::Water)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Smoke);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Fire);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::Water)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Smoke);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Fire);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::Water)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Smoke);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Fire);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::Water)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Smoke);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Fire);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::Water)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Smoke);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x - 1][y - 1].setHealth(grid[x - 1][y - 1].getHealth() - 1);

        if (grid[x - 1][y - 1].getHealth() == 0) {
            grid[x - 1][y - 1].setMaterial(Material::Fire);
            grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, Material::Water)) {
        grid[x - 1][y - 1].setHealth(grid[x - 1][y - 1].getHealth() - 1);

        if (grid[x - 1][y - 1].getHealth() == 0) {
            grid[x - 1][y - 1].setMaterial(Material::Smoke);
            grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    grid[x][y].setHealth(grid[x][y].getHealth() - 1);

    if (grid[x][y].getHealth() == 3) {
        grid[x][y].setMaterial(Material::DullFire);
    }

    if (grid[x][y].getHealth() == 0) {
        grid[x][y].setMaterial(Material::None);
    }

    grid[x][y].setUpdateStatus(false);
}

void Scene::updateLava(int x, int y) {
    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, Material::Sand, Material::Stone)) {
        grid[x][y - 1].setHealth(grid[x][y - 1].getHealth() - 1);

        if (grid[x][y - 1].getHealth() == 0) {
            grid[x][y - 1].setMaterial(Material::Lava);
            grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x][y - 1].setHealth(grid[x][y - 1].getHealth() - 1);

        if (grid[x][y - 1].getHealth() == 0) {
            grid[x][y - 1].setMaterial(Material::Fire);
            grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, Material::Water)) {
        grid[x][y - 1].setHealth(grid[x][y - 1].getHealth() - 1);

        if (grid[x][y - 1].getHealth() == 0) {
            grid[x][y - 1].setMaterial(Material::Smoke);
            grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, Material::Sand, Material::Stone)) {
        grid[x + 1][y - 1].setHealth(grid[x + 1][y - 1].getHealth() - 1);

        if (grid[x + 1][y - 1].getHealth() == 0) {
            grid[x + 1][y - 1].setMaterial(Material::Lava);
            grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x + 1][y - 1].setHealth(grid[x + 1][y - 1].getHealth() - 1);

        if (grid[x + 1][y - 1].getHealth() == 0) {
            grid[x + 1][y - 1].setMaterial(Material::Fire);
            grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, Material::Water)) {
        grid[x + 1][y - 1].setHealth(grid[x + 1][y - 1].getHealth() - 1);

        if (grid[x + 1][y - 1].getHealth() == 0) {
            grid[x + 1][y - 1].setMaterial(Material::Smoke);
            grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::Sand, Material::Stone)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Lava);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Fire);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::Water)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Smoke);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::Sand, Material::Stone)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Lava);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Fire);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::Water)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Smoke);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::Sand, Material::Stone)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Lava);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Fire);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::Water)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Smoke);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::Sand, Material::Stone)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Lava);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Fire);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::Water)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Smoke);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::Sand, Material::Stone)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Lava);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Fire);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::Water)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Smoke);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, Material::Sand, Material::Stone)) {
        grid[x - 1][y - 1].setHealth(grid[x - 1][y - 1].getHealth() - 1);

        if (grid[x - 1][y - 1].getHealth() == 0) {
            grid[x - 1][y - 1].setMaterial(Material::Fire);
            grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, Material::Wick, Material::Gunpowder, Material::Diesel)) {
        grid[x - 1][y - 1].setHealth(grid[x - 1][y - 1].getHealth() - 1);

        if (grid[x - 1][y - 1].getHealth() == 0) {
            grid[x - 1][y - 1].setMaterial(Material::Fire);
            grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, Material::Water)) {
        grid[x - 1][y - 1].setHealth(grid[x - 1][y - 1].getHealth() - 1);

        if (grid[x - 1][y - 1].getHealth() == 0) {
            grid[x - 1][y - 1].setMaterial(Material::Smoke);
            grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    grid[x][y].setHealth(grid[x][y].getHealth() - 1);

    if (grid[x][y].getHealth() == 0) {
        if (grid[x][y].getMaterial() == Material::Lava) {
            grid[x][y].setMaterial(Material::DullLava);
        } else if (grid[x][y].getMaterial() == Material::DullLava) {
            grid[x][y].setMaterial(Material::Lava);
        }
    }

    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, Material::None)) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, Material::None)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, Material::None)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::None)) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::None)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(false);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateSmoke(int x, int y) {
    grid[x][y].setHealth(grid[x][y].getHealth() - 1);

    if (grid[x][y].getHealth() == 80) {
        grid[x][y].setMaterial(Material::DullSmoke);
    }

    if (grid[x][y].getHealth() == 0) {
        grid[x][y].setMaterial(Material::None);
        grid[x][y].setUpdateStatus(false);

        return;
    }

    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, Material::None, Material::Sand, Material::Water, Material::Gunpowder, Material::Diesel, Material::Lava, Material::DullLava)) {
        nextX = x;
        nextY = y - 1;
    } else if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, Material::None, Material::Sand, Material::Water, Material::Gunpowder, Material::Diesel, Material::Lava, Material::DullLava)) {
        nextX = x + 1;
        nextY = y - 1;
    } else if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, Material::None, Material::Sand, Material::Water, Material::Gunpowder, Material::Diesel, Material::Lava, Material::DullLava)) {
        nextX = x - 1;
        nextY = y - 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, Material::None, Material::Sand, Material::Water, Material::Gunpowder, Material::Diesel, Material::Lava, Material::DullLava)) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, Material::None, Material::Sand, Material::Water, Material::Gunpowder, Material::Diesel, Material::Lava, Material::DullLava)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(false);
    grid[nextX][nextY].setUpdateStatus(true);
}
}  // namespace Sandbox
