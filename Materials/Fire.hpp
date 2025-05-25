#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateFire(Scene* scene, int x, int y);

const Material FIRE = {
    /*id*/ 7,
    /*default_lifetime*/ 10,
    /*color*/ sf::Color(204, 170, 0),
    /*name*/ "Fire",
    /*updateFunc*/ updateFire
};

}