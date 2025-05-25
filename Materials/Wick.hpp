#pragma once
#include <SFML/Graphics.hpp>
#include "Material.hpp"

namespace Sandbox {

void updateWick(Scene* scene, int x, int y);

const Material WICK = {
    /*id*/ 4,
    /*default_lifetime*/ 1,
    /*color*/ sf::Color(78, 53, 36),
    /*name*/ "Wick",
    /*updateFunc*/ updateWick
};

}  // namespace Sandbox
