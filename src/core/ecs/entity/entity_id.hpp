#pragma once

#include <cstdint>

namespace engine::ecs {
    struct EntityId {
        std::uint32_t index = 0;
        std::uint32_t generation = 0;
    };

    inline bool operator==(const EntityId &a, const EntityId &b) noexcept {
        return a.index == b.index && a.generation == b.generation;
    }

    inline bool operator!=(const EntityId &a, const EntityId &b) noexcept {
        return !(a == b);
    }
}
