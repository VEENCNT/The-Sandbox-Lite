#include "Fire.hpp"

namespace Sandbox {
void updateFire(Scene* scene, int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }

            if (scene->isCorrectCoordinates(x + dx, y + dy)) {
                if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Wick, Mats::Gunpowder, Mats::Diesel)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 1);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::Fire);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                } else if (scene->isCorrectMaterial(x + dx, y + dy, Mats::Water)) {
                    scene->getCell(x + dx, y + dy).setHealth(scene->getCell(x + dx, y + dy).getHealth() - 1);

                    if (scene->getCell(x + dx, y + dy).getHealth() <= 0) {
                        scene->getCell(x + dx, y + dy).setMaterial(Mats::Smoke);
                        scene->getCell(x + dx, y + dy).setUpdateStatus(true);
                    }
                }
            }
        }
    }

    scene->getCell(x, y).setHealth(scene->getCell(x, y).getHealth() - 1);

    if (scene->getCell(x, y).getHealth() == 3) {
        scene->getCell(x, y).setMaterial(Mats::DullFire);
    }

    if (scene->getCell(x, y).getHealth() <= 0) {
        scene->getCell(x, y).setMaterial(Mats::None);
    }

    scene->getCell(x, y).setUpdateStatus(false);
}
}
