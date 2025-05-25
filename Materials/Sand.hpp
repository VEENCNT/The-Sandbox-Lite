#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateSand(Scene* scene, int x, int y);

const Material SAND = {
    /*id*/ 2,
    /*default_lifetime*/ 100,
    /*color*/ sf::Color(252, 221, 118),
    /*name*/ "Sand",
    /*updateFunc*/ updateSand
};

}