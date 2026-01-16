#pragma once

#include <functional>
#include "entity_id.hpp"

namespace std
{
    template<>
    struct hash<EntityId>
    {
        std::size_t operator()(const EntityId& e) const noexcept
        {
            // 64-bit mix of index + generation
            std::size_t h1 = std::hash<std::uint32_t>{}(e.index);
            std::size_t h2 = std::hash<std::uint32_t>{}(e.generation);

            // Standard hash combine (boost-style)
            return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
        }
    };
}
