#include "Rust.hpp"

namespace Sandbox {
void updateRust(Scene* scene, int x, int y) {
    scene->getCell(x, y).setHealth(scene->getCell(x, y).getHealth() - 1);

    if (scene->getCell(x, y).getHealth() <= 0) {
        scene->getCell(x, y).setMaterial(Mats::None);
    }
}
}
