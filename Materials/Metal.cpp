#include "Metal.hpp"

namespace Sandbox {
void updateMetal(Scene* scene, int x, int y) {
    if (scene->checkNeighborsForMaterial(x, y, Mats::Acid)) {
        scene->getCell(x, y).setHealth(scene->getCell(x, y).getHealth() - 2);

        if (scene->getCell(x, y).getHealth() <= 0) {
            scene->getCell(x, y).setMaterial(Mats::Rust);
        }
    }
}
}
