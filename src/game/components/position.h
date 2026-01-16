#pragma once

struct Position {
    float x = 0.0F;
    float y = 0.0F;

    // We initialize the prev stat with the current state, to avoid jitter
    float previous_x = x;
    float previous_y = y;
};
