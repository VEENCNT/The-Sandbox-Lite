#include "Stone.hpp"
#include "Sand.hpp"

void Sandbox::updateSand(Scene* scene, int x, int y) {
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

    Cell::swap(scene->grid[x][y], scene->grid[nextX][nextY]);

    scene->grid[x][y].setUpdateStatus(false);
    scene->grid[nextX][nextY].setUpdateStatus(true);
}
