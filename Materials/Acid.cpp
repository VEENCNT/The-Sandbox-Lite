#include "Acid.hpp"

namespace Sandbox {
void updateAcid(Scene* scene, int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }

            if (scene->isCorrectCoordinates(x + dx, y + dy)) {
                if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Stone, Mats::Sand, Mats::Wick, Mats::Gunpowder)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 5);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::None);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                }
            }
        }
    }

    int nextX = x;
    int nextY = y;

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::None, Mats::Water)) {
        nextX = x;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::None, Mats::Water)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::None, Mats::Water)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y) && scene->isCorrectMaterial(x + 1, y, Mats::None, Mats::Water)) {
        nextX = x + 1;
        nextY = y;
    } else if (scene->isCorrectCoordinates(x - 1, y) && scene->isCorrectMaterial(x - 1, y, Mats::None, Mats::Water)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(scene->getCell(x, y), scene->getCell(nextX, nextY));

    scene->getCell(x, y).setUpdateStatus(false);
    scene->getCell(nextX, nextY).setUpdateStatus(true);
}
}
