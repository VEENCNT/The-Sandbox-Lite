#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateMetal(Scene* scene, int x, int y);

const Material METAL = {
    /*id*/ 15,
    /*default_lifetime*/ 500,
    /*color*/ sf::Color(150, 150, 150),
    /*name*/ "Metal",
    /*updateFunc*/ updateMetal
};

}