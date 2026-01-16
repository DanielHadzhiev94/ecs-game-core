#pragma once

struct Vec2 {
    float x = 0.0F;
    float y = 0.0F;

    static Vec2 lerp(Vec2 &a, Vec2 &b, float t) {
        return {
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t
        };
    }
};
