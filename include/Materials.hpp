#pragma once
#include "Materials/Stone.hpp"
#include "Materials/Sand.hpp"
#include "Materials/Water.hpp"
#include "Materials/Wick.hpp"
#include "Materials/Gunpowder.hpp"
#include "Materials/Diesel.hpp"
#include "Materials/Fire.hpp"
#include "Materials/DullFire.hpp"
#include "Materials/Lava.hpp"
#include "Materials/DullLava.hpp"
#include "Materials/Smoke.hpp"
#include "Materials/DullSmoke.hpp"
#include "Materials/Acid.hpp"
#include "Materials/DullAcid.hpp"
#include "Materials/Metal.hpp"
#include "Materials/MoltenMetal.hpp"
#include "Materials/Rust.hpp"
#include "Materials/None.hpp"
#include "Cell.hpp"

namespace Sandbox {
    constexpr const Material* Materials[] = {
        &NONE,
        &STONE,
        &SAND,
        &WATER,
        &WICK,
        &GUNPOWDER,
        &DIESEL,
        &FIRE,
        &DULLFIRE,
        &LAVA,
        &DULLLAVA,
        &SMOKE,
        &DULLSMOKE,
        &ACID,
        &DULLACID,
        &METAL,
        &MOLTENMETAL,
        &RUST
    };

    inline const Material* getMaterialProperties(Mats m) {
        int id = static_cast<int>(m);
        if (id >= 0 && id < (sizeof(Materials)/sizeof(Materials[0])))
            return Materials[id];
        return nullptr;
    }
}