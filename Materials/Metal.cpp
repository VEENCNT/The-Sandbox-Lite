#include "Metal.hpp"

void Sandbox::updateMetal(Scene* scene, int x, int y) {
    if (scene->checkNeighborsForMaterial(x, y, Mats::Acid)) {
        scene->grid[x][y].setHealth(scene->grid[x][y].getHealth() - 2);
        if (scene->grid[x][y].getHealth() <= 0) {
            scene->grid[x][y].setMaterial(Mats::Rust);
        }
    }
}
