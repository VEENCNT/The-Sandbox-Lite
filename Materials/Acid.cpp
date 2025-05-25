#include "Acid.hpp"

void Sandbox::updateAcid(Scene* scene, int x, int y) {
    bool contactWithLava = false;

    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(dx == 0 && dy == 0) continue;

            if(scene->isCorrectCoordinates(x+dx, y+dy)) {
                Cell& neighbor = scene->grid[x+dx][y+dy];

                if(neighbor.getMaterial() == Mats::Lava ||
                   neighbor.getMaterial() == Mats::DullLava) {
                    contactWithLava = true;
                }
            }
        }
    }

    if(contactWithLava) {
        scene->grid[x][y].setHealth(scene->grid[x][y].getHealth() - 20);
    }

    if(scene->grid[x][y].getHealth() <= 0) {
        scene->grid[x][y].setMaterial(Mats::Smoke);
        scene->grid[x][y].setUpdateStatus(true);
        return;
    }

    constexpr Mats corrosive[] = {Mats::Stone, Mats::Wick, Mats::Gunpowder};
    for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; dy++) {
            if(dx == 0 && dy == 0) continue;

            if(scene->isCorrectCoordinates(x+dx, y+dy)) {
                Cell& neighbor = scene->grid[x+dx][y+dy];
                for(auto mat : corrosive) {
                    if(neighbor.getMaterial() == mat) {
                        neighbor.setHealth(neighbor.getHealth() - 5);
                        if(neighbor.getHealth() <= 0) {
                            neighbor.setMaterial(Mats::None);
                        }
                    }
                }
            }
        }
    }

    int nextX = x;
    int nextY = y;

    if (scene->isCorrectCoordinates(x, y + 1) && scene->isCorrectMaterial(x, y + 1, Mats::None)) {
        nextX = x;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y + 1) && scene->isCorrectMaterial(x + 1, y + 1, Mats::None)) {
        nextX = x + 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x - 1, y + 1) && scene->isCorrectMaterial(x - 1, y + 1, Mats::None)) {
        nextX = x - 1;
        nextY = y + 1;
    } else if (scene->isCorrectCoordinates(x + 1, y) && scene->isCorrectMaterial(x + 1, y, Mats::None)) {
        nextX = x + 1;
        nextY = y;
    } else if (scene->isCorrectCoordinates(x - 1, y) && scene->isCorrectMaterial(x - 1, y, Mats::None)) {
        nextX = x - 1;
        nextY = y;
    }

    Cell::swap(scene->grid[x][y], scene->grid[nextX][nextY]);

    scene->grid[x][y].setUpdateStatus(false);
    scene->grid[nextX][nextY].setUpdateStatus(true);

    if(scene->grid[nextX][nextY].getHealth() <= 0) {
        scene->grid[nextX][nextY].setMaterial(Mats::None);
    }
}
