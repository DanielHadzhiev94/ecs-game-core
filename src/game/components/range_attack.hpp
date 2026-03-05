#pragma once
#include <cstdint>
#include <iostream>

namespace engine::game::components {
    struct RangeAttack {
        std::uint32_t damage = 10;
        float range = 20.f;

        float remaining = 0.f;
        float cooldown = 5.f;

        void attack() noexcept {
            remaining = cooldown;
        }

        const float get_remaining_cd() const {
            return remaining;
        }

        bool is_in_cooldown() const noexcept {
            return remaining > 0;
        }

        void tick(const float dt) {
            if (!is_in_cooldown())
                return;

            remaining -= dt;
        }
    };
}
