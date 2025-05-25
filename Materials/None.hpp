#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateNone(Scene* scene, int x, int y);

const Material NONE = {
    /*id*/ 0,
    /*default_lifetime*/ 0,
    /*color*/ sf::Color(0, 0, 0),
    /*name*/ "None",
    /*updateFunc*/ updateNone
};

}