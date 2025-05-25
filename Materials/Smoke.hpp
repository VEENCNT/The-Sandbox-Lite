#pragma once
#include "Material.hpp"
#include "../include/Scene.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateSmoke(Scene*, int x, int y);

const Material SMOKE = {
    /*id*/ 11,
    /*default_lifetime*/ 120,
    /*color*/ sf::Color(220, 220, 220),
    /*name*/ "Smoke",
    /*updateFunc*/ updateSmoke
};

}