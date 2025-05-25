#pragma once
#include <SFML/Graphics.hpp>
#include "Material.hpp"

namespace Sandbox {

void updateWater(Scene* scene, int x, int y);

const Material WATER = {
    /*id*/ 3,
    /*default_lifetime*/ 3,
    /*color*/ sf::Color(35, 137, 218),
    /*name*/ "Water",
    /*updateFunc*/ updateWater
};

}  // namespace Sandbox
