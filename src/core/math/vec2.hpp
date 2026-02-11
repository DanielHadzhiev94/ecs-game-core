#pragma once

namespace engine::math
{
    struct Vec2
    {
        float x = 0.0F;
        float y = 0.0F;

        Vec2 operator+(const Vec2 &other) const
        {
            return {x + other.x, y + other.y};
        }

        Vec2 operator-(const Vec2 &other) const
        {
            return {x - other.x, y - other.y};
        }

        Vec2 operator*(float scalar) const
        {
            return {x * scalar, y * scalar};
        }

        Vec2 &operator+=(const Vec2 &other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vec2 &operator-=(const Vec2 &other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vec2 &operator*=(float scalar)
        {
            x *= scalar;
            y *= scalar;
            return *this;
        }

        static Vec2 lerp(const Vec2 &previous, const Vec2 &current, float alpha)
        {
            return {
                previous.x + (current.x - previous.x) * alpha,
                previous.y + (current.y - previous.y) * alpha};
        }
    };
}
