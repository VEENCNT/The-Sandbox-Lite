#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

const Material DULLSMOKE = {
    /*id*/ 12,
    /*default_lifetime*/ 80,
    /*color*/ sf::Color(169, 169, 169),
    /*name*/ "DullSmoke",
    /*updateFunc*/ updateSmoke
};

}  // namespace Sandbox
