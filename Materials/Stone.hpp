#pragma once
#include <SFML/Graphics.hpp>
#include "Material.hpp"

namespace Sandbox {

void updateStone(Scene* scene, int x, int y);

const Material STONE = {
    /*id*/ 1,
    /*default_lifetime*/ 1000,
    /*color*/ sf::Color(90, 86, 83),
    /*name*/ "Stone",
    /*updateFunc*/ updateStone
};

}  // namespace Sandbox
