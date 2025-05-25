#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

const Material DULLFIRE = {
    /*id*/ 8,
    /*default_lifetime*/ 3,
    /*color*/ sf::Color(230, 38, 0),
    /*name*/ "DullFire",
    /*updateFunc*/ updateFire
};

}