#include "Lava.hpp"

namespace Sandbox {
void updateLava(Scene* scene, int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }

            if (scene->isCorrectCoordinates(x + dx, y + dy)) {
                if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Sand, Mats::Stone)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 1);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::Lava);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                } else if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 1);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::Fire);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                } else if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Water, Mats::Acid)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 1);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::Smoke);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                } else if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Metal)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 2);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::MoltenMetal);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                }
            }
        }
    }

    scene->getCell(x, y).setHealth(scene->getCell(x, y).getHealth() - 1);

    if (scene->getCell(x, y).getHealth() <= 0) {
        if (scene->getCell(x, y).getMaterial() == Mats::Lava) {
            scene->getCell(x, y).setMaterial(Mats::DullLava);
        } else if (scene->getCell(x, y).getMaterial() == Mats::DullLava) {
            scene->getCell(x, y).setMaterial(Mats::Lava);
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

    Cell::swap(scene->getCell(x, y), scene->getCell(nextX, nextY));

    scene->getCell(x, y).setUpdateStatus(false);
    scene->getCell(nextX, nextY).setUpdateStatus(true);
}
}
