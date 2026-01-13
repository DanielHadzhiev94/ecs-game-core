#pragma once
#include "../../core/view/view.h"

class System {
public:
    virtual ~System() = default;

    virtual void update(Registry& registry, float dt) = 0;
};
