#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

const Material DULLACID = {
    /*id*/ 14,
    /*default_lifetime*/ 100,
    /*color*/ sf::Color(30, 150, 30),
    /*name*/ "DullAcid",
    /*updateFunc*/ updateAcid
};

}  // namespace Sandbox
