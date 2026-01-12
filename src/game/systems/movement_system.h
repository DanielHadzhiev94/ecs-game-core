#pragma once
#include "system.h"


class MovementSystem : public System {
public:
    void update(Registry &registry, float df) override;
};
