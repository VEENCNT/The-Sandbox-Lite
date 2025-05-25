#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateWater(Scene* scene, int x, int y);

const Material WATER = {
    /*id*/ 3,
    /*default_lifetime*/ 10,
    /*color*/ sf::Color(35, 137, 218),
    /*name*/ "Water",
    /*updateFunc*/ updateWater
};

}