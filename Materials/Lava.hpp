#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateLava(Scene* scene, int x, int y);

const Material LAVA = {
    /*id*/ 9,
    /*default_lifetime*/ 100,
    /*color*/ sf::Color(255, 66, 32),
    /*name*/ "Lava",
    /*updateFunc*/ updateLava
};

}  // namespace Sandbox
