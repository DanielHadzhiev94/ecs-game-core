#pragma once

#include <cstddef>

#include "../entity/entity_id.h"
#include "../registry/registry.h"

template<typename... Ts>
class ViewIterator {
public:
    ViewIterator() = delete;

    ViewIterator(Registry &_registry, const std::size_t _current_index, const std::size_t _end_index)
        : registry(_registry), current_index(_current_index), end_index(_end_index) {
    }

    ~ViewIterator() = default;

    EntityId operator*() const {
        return EntityId{ current_index };
    }

    ViewIterator &operator++() {
        ++current_index;
        advanced_to_valid();
        return *this;
    }

    bool operator==(const ViewIterator &other) const {
        return &registry == &other.registry &&
               current_index == other.current_index;
    }

    bool operator!=(const ViewIterator &other) const {
        return &registry != &other.registry ||
               current_index != other.current_index;
    }

    void advanced_to_valid() {
        while (current_index < end_index) {
            EntityId entity{current_index};

            if (registry.is_alive(entity) &&
                (registry.has<Ts>(entity) && ...)) {
                break;
            }

            ++current_index;
        }
    }

private:
    Registry &registry;
    std::size_t current_index;
    std::size_t end_index;
};
