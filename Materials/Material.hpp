#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "../include/Scene.hpp"

namespace Sandbox {

struct Material {
    int id;
    int default_lifetime;
    sf::Color color;
    std::string name;
    void (*updateFunc)(Scene*, int, int);
};

}  // namespace Sandbox
