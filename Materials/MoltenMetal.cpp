#include "MoltenMetal.hpp"

void Sandbox::updateMoltenMetal(Scene* scene, int x, int y) {
    bool moved = false;
    int dir = (rand() % 2) * 2 - 1;

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::None)) {
        Cell::swap(scene->grid[x][y], scene->grid[x][y + 1]);
        moved = true;
    } else if (scene->isCorrectCoordinates(x + dir, y + 1) && scene->isCorrectMaterial(x + dir, y + 1, Mats::None)) {
        Cell::swap(scene->grid[x][y], scene->grid[x + dir][y + 1]);
        moved = true;
    }

    if (!moved) {
        scene->grid[x][y].setHealth(scene->grid[x][y].getHealth() - 1);
        if (scene->grid[x][y].getHealth() <= 0) {
            scene->grid[x][y].setMaterial(Mats::None);
        }
    }
}