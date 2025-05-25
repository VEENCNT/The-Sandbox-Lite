#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateDiesel(Scene* scene, int x, int y);

const Material DIESEL = {
    /*id*/ 6,
    /*default_lifetime*/ 2,
    /*color*/ sf::Color(237,255,33),
    /*name*/ "Diesel",
    /*updateFunc*/ updateDiesel
};

}  // namespace Sandbox
