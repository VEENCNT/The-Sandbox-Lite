#include "MoltenMetal.hpp"

namespace Sandbox {
void updateMoltenMetal(Scene* scene, int x, int y) {
    bool moved = false;
    int dir = (rand() % 2) * 2 - 1;

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::None)) {
        Cell::swap(scene->getCell(x, y), scene->getCell(x, y + 1));
        moved = true;
    } else if (scene->isCorrectCoordinates(x + dir, y + 1) && scene->isCorrectMaterial(x + dir, y + 1, Mats::None)) {
        Cell::swap(scene->getCell(x, y), scene->getCell(x + dir, y + 1));
        moved = true;
    }

    if (!moved) {
        scene->getCell(x, y).setHealth(scene->getCell(x, y).getHealth() - 1);

        if (scene->getCell(x, y).getHealth() <= 0) {
            scene->getCell(x, y).setMaterial(Mats::None);
        }
    }
}
}
