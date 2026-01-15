#pragma once

#include "registry/registry.h"

class LifetimeSystem {
public:
    static void fixed_update(Registry &registry, float fixed_dt);
};
