#include "Fire.hpp"

void Sandbox::updateFire(Scene* scene, int x, int y) {
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

    if (scene->grid[x][y].getHealth() == 3) {
        scene->grid[x][y].setMaterial(Mats::DullFire);
    }

    if (scene->grid[x][y].getHealth() == 0) {
        scene->grid[x][y].setMaterial(Mats::None);
    }

    scene->grid[x][y].setUpdateStatus(false);
}
