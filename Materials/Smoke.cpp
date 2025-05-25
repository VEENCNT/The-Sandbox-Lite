#include "Smoke.hpp"

namespace Sandbox {
void updateSmoke(Scene* scene, int x, int y) {
    Cell& cell = scene->getCell(x, y);
    cell.setHealth(cell.getHealth() - 1);

    if (cell.getHealth() == 80) {
        cell.setMaterial(Mats::DullSmoke);
    }

    if (cell.getHealth() == 0) {
        cell.setMaterial(Mats::None);
        cell.setUpdateStatus(false);

        return;
    }

    int nextX = x;
    int nextY = y;

    if (scene->isCorrectCoordinates(x, y - 1) && !scene->isCorrectMaterial(x, y - 1, Mats::Stone, Mats::Wick, Mats::Smoke, Mats::DullSmoke)) {
        nextX = x;
        nextY = y - 1;
    } else if (scene->isCorrectCoordinates(x + 1, y - 1) &&
               !scene->isCorrectMaterial(x + 1, y - 1, Mats::Stone, Mats::Wick, Mats::Smoke, Mats::DullSmoke)) {
        nextX = x + 1;
        nextY = y - 1;
    } else if (scene->isCorrectCoordinates(x - 1, y - 1) &&
               !scene->isCorrectMaterial(x - 1, y - 1, Mats::Stone, Mats::Wick, Mats::Smoke, Mats::DullSmoke)) {
        nextX = x - 1;
        nextY = y - 1;
    } else if (scene->isCorrectCoordinates(x + 1, y) && !scene->isCorrectMaterial(x + 1, y, Mats::Stone, Mats::Wick, Mats::Smoke, Mats::DullSmoke)) {
        nextX = x + 1;
        nextY = y;
    } else if (scene->isCorrectCoordinates(x - 1, y) && !scene->isCorrectMaterial(x - 1, y, Mats::Stone, Mats::Wick, Mats::Smoke, Mats::DullSmoke)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(scene->getCell(x, y), scene->getCell(nextX, nextY));

    scene->getCell(x, y).setUpdateStatus(false);
    scene->getCell(nextX, nextY).setUpdateStatus(true);
}
}
