#pragma once
#include "Material.hpp"
#include <SFML/Graphics.hpp>

namespace Sandbox {

void updateRust(Scene* scene, int x, int y);

const Material RUST = {
    /*id*/ 17,
    /*default_lifetime*/ 50,
    /*color*/ sf::Color(175, 100, 50),
    /*name*/ "Rust",
    /*updateFunc*/ updateRust
};

}