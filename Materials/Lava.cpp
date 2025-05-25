#include "Lava.hpp"

void Sandbox::updateLava(Scene* scene, int x, int y) {
    if (scene->isCorrectCoordinates(x, y - 1) && scene->isCorrectMaterial(x, y - 1, Mats::Sand, Mats::Stone)) {
        scene->grid[x][y - 1].setHealth(scene->grid[x][y - 1].getHealth() - 1);

        if (scene->grid[x][y - 1].getHealth() == 0) {
            scene->grid[x][y - 1].setMaterial(Mats::Lava);
            scene->grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x, y - 1) && scene->isCorrectMaterial(x, y - 1, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x][y - 1].setHealth(scene->grid[x][y - 1].getHealth() - 1);

        if (scene->grid[x][y - 1].getHealth() == 0) {
            scene->grid[x][y - 1].setMaterial(Mats::Fire);
            scene->grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x, y - 1) && scene->isCorrectMaterial(x, y - 1, Mats::Water)) {
        scene->grid[x][y - 1].setHealth(scene->grid[x][y - 1].getHealth() - 1);

        if (scene->grid[x][y - 1].getHealth() == 0) {
            scene->grid[x][y - 1].setMaterial(Mats::Smoke);
            scene->grid[x][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y - 1) && scene->isCorrectMaterial(x + 1, y - 1, Mats::Sand, Mats::Stone)) {
        scene->grid[x + 1][y - 1].setHealth(scene->grid[x + 1][y - 1].getHealth() - 1);

        if (scene->grid[x + 1][y - 1].getHealth() == 0) {
            scene->grid[x + 1][y - 1].setMaterial(Mats::Lava);
            scene->grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y - 1) && scene->isCorrectMaterial(x + 1, y - 1, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x + 1][y - 1].setHealth(scene->grid[x + 1][y - 1].getHealth() - 1);

        if (scene->grid[x + 1][y - 1].getHealth() == 0) {
            scene->grid[x + 1][y - 1].setMaterial(Mats::Fire);
            scene->grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y - 1) && scene->isCorrectMaterial(x + 1, y - 1, Mats::Water)) {
        scene->grid[x + 1][y - 1].setHealth(scene->grid[x + 1][y - 1].getHealth() - 1);

        if (scene->grid[x + 1][y - 1].getHealth() == 0) {
            scene->grid[x + 1][y - 1].setMaterial(Mats::Smoke);
            scene->grid[x + 1][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y) && scene->isCorrectMaterial(x + 1, y, Mats::Sand, Mats::Stone)) {
        scene->grid[x + 1][y].setHealth(scene->grid[x + 1][y].getHealth() - 1);

        if (scene->grid[x + 1][y].getHealth() == 0) {
            scene->grid[x + 1][y].setMaterial(Mats::Lava);
            scene->grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y) && scene->isCorrectMaterial(x + 1, y, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x + 1][y].setHealth(scene->grid[x + 1][y].getHealth() - 1);

        if (scene->grid[x + 1][y].getHealth() == 0) {
            scene->grid[x + 1][y].setMaterial(Mats::Fire);
            scene->grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y) && scene->isCorrectMaterial(x + 1, y, Mats::Water)) {
        scene->grid[x + 1][y].setHealth(scene->grid[x + 1][y].getHealth() - 1);

        if (scene->grid[x + 1][y].getHealth() == 0) {
            scene->grid[x + 1][y].setMaterial(Mats::Smoke);
            scene->grid[x + 1][y].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::Sand, Mats::Stone)) {
        scene->grid[x + 1][y + 1].setHealth(scene->grid[x + 1][y + 1].getHealth() - 1);

        if (scene->grid[x + 1][y + 1].getHealth() == 0) {
            scene->grid[x + 1][y + 1].setMaterial(Mats::Lava);
            scene->grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x + 1][y + 1].setHealth(scene->grid[x + 1][y + 1].getHealth() - 1);

        if (scene->grid[x + 1][y + 1].getHealth() == 0) {
            scene->grid[x + 1][y + 1].setMaterial(Mats::Fire);
            scene->grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::Water)) {
        scene->grid[x + 1][y + 1].setHealth(scene->grid[x + 1][y + 1].getHealth() - 1);

        if (scene->grid[x + 1][y + 1].getHealth() == 0) {
            scene->grid[x + 1][y + 1].setMaterial(Mats::Smoke);
            scene->grid[x + 1][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::Sand, Mats::Stone)) {
        scene->grid[x][y + 1].setHealth(scene->grid[x][y + 1].getHealth() - 1);

        if (scene->grid[x][y + 1].getHealth() == 0) {
            scene->grid[x][y + 1].setMaterial(Mats::Lava);
            scene->grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x][y + 1].setHealth(scene->grid[x][y + 1].getHealth() - 1);

        if (scene->grid[x][y + 1].getHealth() == 0) {
            scene->grid[x][y + 1].setMaterial(Mats::Fire);
            scene->grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::Water)) {
        scene->grid[x][y + 1].setHealth(scene->grid[x][y + 1].getHealth() - 1);

        if (scene->grid[x][y + 1].getHealth() == 0) {
            scene->grid[x][y + 1].setMaterial(Mats::Smoke);
            scene->grid[x][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::Sand, Mats::Stone)) {
        scene->grid[x - 1][y + 1].setHealth(scene->grid[x - 1][y + 1].getHealth() - 1);

        if (scene->grid[x - 1][y + 1].getHealth() == 0) {
            scene->grid[x - 1][y + 1].setMaterial(Mats::Lava);
            scene->grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x - 1][y + 1].setHealth(scene->grid[x - 1][y + 1].getHealth() - 1);

        if (scene->grid[x - 1][y + 1].getHealth() == 0) {
            scene->grid[x - 1][y + 1].setMaterial(Mats::Fire);
            scene->grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::Water)) {
        scene->grid[x - 1][y + 1].setHealth(scene->grid[x - 1][y + 1].getHealth() - 1);

        if (scene->grid[x - 1][y + 1].getHealth() == 0) {
            scene->grid[x - 1][y + 1].setMaterial(Mats::Smoke);
            scene->grid[x - 1][y + 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y) && scene->isCorrectMaterial(x - 1, y, Mats::Sand, Mats::Stone)) {
        scene->grid[x - 1][y].setHealth(scene->grid[x - 1][y].getHealth() - 1);

        if (scene->grid[x - 1][y].getHealth() == 0) {
            scene->grid[x - 1][y].setMaterial(Mats::Lava);
            scene->grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y) && scene->isCorrectMaterial(x - 1, y, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x - 1][y].setHealth(scene->grid[x - 1][y].getHealth() - 1);

        if (scene->grid[x - 1][y].getHealth() == 0) {
            scene->grid[x - 1][y].setMaterial(Mats::Fire);
            scene->grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y) && scene->isCorrectMaterial(x - 1, y, Mats::Water)) {
        scene->grid[x - 1][y].setHealth(scene->grid[x - 1][y].getHealth() - 1);

        if (scene->grid[x - 1][y].getHealth() == 0) {
            scene->grid[x - 1][y].setMaterial(Mats::Smoke);
            scene->grid[x - 1][y].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y - 1) && scene->isCorrectMaterial(x - 1, y - 1, Mats::Sand, Mats::Stone)) {
        scene->grid[x - 1][y - 1].setHealth(scene->grid[x - 1][y - 1].getHealth() - 1);

        if (scene->grid[x - 1][y - 1].getHealth() == 0) {
            scene->grid[x - 1][y - 1].setMaterial(Mats::Fire);
            scene->grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y - 1) && scene->isCorrectMaterial(x - 1, y - 1, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
        scene->grid[x - 1][y - 1].setHealth(scene->grid[x - 1][y - 1].getHealth() - 1);

        if (scene->grid[x - 1][y - 1].getHealth() == 0) {
            scene->grid[x - 1][y - 1].setMaterial(Mats::Fire);
            scene->grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    if (scene->isCorrectCoordinates(x - 1, y - 1) && scene->isCorrectMaterial(x - 1, y - 1, Mats::Water)) {
        scene->grid[x - 1][y - 1].setHealth(scene->grid[x - 1][y - 1].getHealth() - 1);

        if (scene->grid[x - 1][y - 1].getHealth() == 0) {
            scene->grid[x - 1][y - 1].setMaterial(Mats::Smoke);
            scene->grid[x - 1][y - 1].setUpdateStatus(true);
        }
    }

    scene->grid[x][y].setHealth(scene->grid[x][y].getHealth() - 1);

    if (scene->grid[x][y].getHealth() == 0) {
        if (scene->grid[x][y].getMaterial() == Mats::Lava) {
            scene->grid[x][y].setMaterial(Mats::DullLava);
        } else if (scene->grid[x][y].getMaterial() == Mats::DullLava) {
            scene->grid[x][y].setMaterial(Mats::Lava);
        }
    }

    int nextX = x;
    int nextY = y;

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::None)) {
        nextX = x;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::None)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::None)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y) && scene->isCorrectMaterial(x + 1, y, Mats::None)) {
        nextX = x + 1;
        nextY = y;
    } else if (scene->isCorrectCoordinates(x - 1, y) && scene->isCorrectMaterial(x - 1, y, Mats::None)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(scene->grid[x][y], scene->grid[nextX][nextY]);

    scene->grid[x][y].setUpdateStatus(false);
    scene->grid[nextX][nextY].setUpdateStatus(true);
}
