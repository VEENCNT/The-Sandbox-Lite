#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateAcid(Scene* scene, int x, int y);

const Material ACID = {
    /*id*/ 13,
    /*default_lifetime*/ 200,
    /*color*/ sf::Color(50, 255, 50),
    /*name*/ "Acid",
    /*updateFunc*/ updateAcid
};

}