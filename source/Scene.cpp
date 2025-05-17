#include "../include/Scene.hpp"

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
            grid[x][y].setUpdateStatus(false);
        }
    }

    for (int x = 0; x < kDefaultWidth; ++x) {
        for (int y = 0; y < kDefaultHeight; ++y) {
            if (grid[x][y].getUpdateStatus()) {
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

Cell& Scene::getElement(int x, int y) {
    return grid[x][y];
}

void Scene::updateSand(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, {Material::None, Material::Water, Material::Diesel})) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, {Material::None, Material::Water, Material::Diesel})) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, {Material::None, Material::Water, Material::Diesel})) {
        nextX = x - 1;
        nextY = y + 1;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateWater(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, {Material::None})) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, {Material::None})) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, {Material::None})) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, {Material::None})) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, {Material::None})) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateGunpowder(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, {Material::None, Material::Water, Material::Diesel})) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, {Material::None, Material::Water, Material::Diesel})) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, {Material::None, Material::Water, Material::Diesel})) {
        nextX = x - 1;
        nextY = y + 1;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateDiesel(int x, int y) {
    int nextX = x;
    int nextY = y;

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, {Material::None, Material::Water})) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, {Material::None, Material::Water})) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, {Material::None, Material::Water})) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, {Material::None})) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, {Material::None})) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

void Scene::updateFire(int x, int y) {
    const std::vector<Material> flameableMaterials = {Material::Wick, Material::Gunpowder, Material::Diesel};

    if (isCorrectCoordinates(x, y - 1) && isCorrectMaterial(x, y - 1, flameableMaterials)) {
        grid[x][y - 1].setHealth(grid[x][y - 1].getHealth() - 1);

        if (grid[x][y - 1].getHealth() == 0) {
            grid[x][y - 1].setMaterial(Material::Fire);
            grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y - 1) && isCorrectMaterial(x + 1, y - 1, flameableMaterials)) {
        grid[x + 1][y - 1].setHealth(grid[x + 1][y - 1].getHealth() - 1);

        if (grid[x + 1][y - 1].getHealth() == 0) {
            grid[x + 1][y - 1].setMaterial(Material::Fire);
            grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, flameableMaterials)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Fire);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, flameableMaterials)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Fire);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, flameableMaterials)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Fire);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, flameableMaterials)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Fire);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, flameableMaterials)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Fire);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y - 1) && isCorrectMaterial(x - 1, y - 1, flameableMaterials)) {
        grid[x - 1][y - 1].setHealth(grid[x - 1][y - 1].getHealth() - 1);

        if (grid[x - 1][y - 1].getHealth() == 0) {
            grid[x - 1][y - 1].setMaterial(Material::Fire);
            grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    grid[x][y].setHealth(grid[x][y].getHealth() - 1);

    if (grid[x][y].getHealth() <= 3) {
        grid[x][y].setMaterial(Material::DullFire);
    }

    if (grid[x][y].getHealth() == 0) {
        grid[x][y].setMaterial(Material::None);
    }

    grid[x][y].setUpdateStatus(true);
}

void Scene::updateLava(int x, int y) {
    const std::vector<Material> noneMaterial = {Material::None};
    const std::vector<Material> unflameableMaterials = {Material::Sand, Material::Stone};
    const std::vector<Material> flameableMaterials = {Material::Wick, Material::Gunpowder, Material::Diesel};

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, unflameableMaterials)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Lava);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, flameableMaterials)) {
        grid[x + 1][y].setHealth(grid[x + 1][y].getHealth() - 1);

        if (grid[x + 1][y].getHealth() == 0) {
            grid[x + 1][y].setMaterial(Material::Fire);
            grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, unflameableMaterials)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Lava);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, flameableMaterials)) {
        grid[x + 1][y + 1].setHealth(grid[x + 1][y + 1].getHealth() - 1);

        if (grid[x + 1][y + 1].getHealth() == 0) {
            grid[x + 1][y + 1].setMaterial(Material::Fire);
            grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, unflameableMaterials)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Lava);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, flameableMaterials)) {
        grid[x][y + 1].setHealth(grid[x][y + 1].getHealth() - 1);

        if (grid[x][y + 1].getHealth() == 0) {
            grid[x][y + 1].setMaterial(Material::Fire);
            grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, unflameableMaterials)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Lava);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, flameableMaterials)) {
        grid[x - 1][y + 1].setHealth(grid[x - 1][y + 1].getHealth() - 1);

        if (grid[x - 1][y + 1].getHealth() == 0) {
            grid[x - 1][y + 1].setMaterial(Material::Fire);
            grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, unflameableMaterials)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Lava);
            grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, flameableMaterials)) {
        grid[x - 1][y].setHealth(grid[x - 1][y].getHealth() - 1);

        if (grid[x - 1][y].getHealth() == 0) {
            grid[x - 1][y].setMaterial(Material::Fire);
            grid[x - 1][y].setUpdateStatus(true);
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

    if (isCorrectCoordinates(x, y + 1) && isCorrectMaterial(x, y + 1, noneMaterial)) {
        nextX = x;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y + 1) && isCorrectMaterial(x + 1, y + 1, noneMaterial)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x - 1, y + 1) && isCorrectMaterial(x - 1, y + 1, noneMaterial)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (isCorrectCoordinates(x + 1, y) && isCorrectMaterial(x + 1, y, noneMaterial)) {
        nextX = x + 1;
        nextY = y;
    } else if (isCorrectCoordinates(x - 1, y) && isCorrectMaterial(x - 1, y, noneMaterial)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(grid[x][y], grid[nextX][nextY]);

    grid[x][y].setUpdateStatus(true);
    grid[nextX][nextY].setUpdateStatus(true);
}

bool Scene::isCorrectCoordinates(int x, int y) {
    return (x >= 0) && (x < kDefaultWidth) && (y >= 0) && (y < kDefaultHeight);
}

bool Scene::isCorrectMaterial(int x, int y, const std::vector<Material>& materials) {
    auto iter = find(materials.begin(), materials.end(), grid[x][y].getMaterial());

    if (iter == materials.end()) {
        return false;
    } else {
        return true;
    }
}

}  // namespace Sandbox
