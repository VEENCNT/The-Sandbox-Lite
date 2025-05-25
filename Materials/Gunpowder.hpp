#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateGunpowder(Scene* scene, int x, int y);

const Material GUNPOWDER = {
    /*id*/ 5,
    /*default_lifetime*/ 3,
    /*color*/ sf::Color(128, 128, 128),
    /*name*/ "Gunpowder",
    /*updateFunc*/ updateGunpowder
};

}