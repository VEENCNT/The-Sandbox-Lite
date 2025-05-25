#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

const Material DULLLAVA = {
    /*id*/ 10,
    /*default_lifetime*/ 100,
    /*color*/ sf::Color(255, 16, 32),
    /*name*/ "DullLava",
    /*updateFunc*/ updateLava
};

}