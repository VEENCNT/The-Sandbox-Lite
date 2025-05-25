#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateMoltenMetal(Scene* scene, int x, int y);

const Material MOLTENMETAL = {
    /*id*/ 16,
    /*default_lifetime*/ 100,
    /*color*/ sf::Color(255, 80, 0),
    /*name*/ "MoltenMetal",
    /*updateFunc*/ updateMoltenMetal
};

}  // namespace Sandbox
