#pragma once

#include <cstddef>

#include "../registry/registry.h"

template<typename... Ts>
class ViewIterator {
public:
    ViewIterator() = delete;

    ViewIterator(Registry &_registry, const std::size_t _current_index, const std::size_t _end_index)
        : registry(_registry), current_index(_current_index), end_index(_end_index) {
    }

    ~ViewIterator() = default;

private:
    Registry &registry;
    std::size_t current_index;
    std::size_t end_index;
};
