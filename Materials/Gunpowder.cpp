#include "Gunpowder.hpp"

namespace Sandbox {
void updateGunpowder(Scene* scene, int x, int y) {
    int nextX = x;
    int nextY = y;

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::None, Mats::Water, Mats::Diesel)) {
        nextX = x;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::None, Mats::Water, Mats::Diesel)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::None, Mats::Water, Mats::Diesel)) {
        nextX = x - 1;
        nextY = y + 1;
    }

    Cell::swap(scene->getCell(x, y), scene->getCell(nextX, nextY));

    scene->getCell(x, y).setUpdateStatus(false);
    scene->getCell(nextX, nextY).setUpdateStatus(true);
}
}
