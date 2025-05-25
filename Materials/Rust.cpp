#include "Rust.hpp"

void Sandbox::updateRust(Scene* scene, int x, int y) {
    scene->grid[x][y].setHealth(scene->grid[x][y].getHealth() - 1);
    if (scene->grid[x][y].getHealth() <= 0) {
        scene->grid[x][y].setMaterial(Mats::None);
    }
}
