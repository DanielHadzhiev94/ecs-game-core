#pragma once
#include "world.h"

class Game {
public:
    Game() = default;

    void update(float dt);

private:
    World world;
};
