#pragma once

#include <cstddef>

#include "../entity/entity_id.hpp"
#include "../registry/registry.hpp"

namespace engine::ecs {
    template<typename... Ts>
    class ViewIterator {
    public:
        ViewIterator() = delete;

        ViewIterator(Registry &_registry, const std::size_t _current_index, const std::size_t _end_index)
            : registry(_registry), current_index(_current_index), end_index(_end_index) {
        }

        ~ViewIterator() = default;

        EntityId operator*() const {
            return registry.entity_from_index(current_index);
        }

        ViewIterator &operator++() {
            ++current_index;
            advance_to_valid();
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

        void advance_to_valid() {
            while (current_index < end_index) {
                EntityId entity = registry.entity_from_index(current_index);

                if (registry.is_alive(entity) &&
                    (registry.has<Ts>(entity) && ...)) {
                    break;
                }

                ++current_index;
            }
        }

    private:
        Registry &registry;
        std::uint32_t current_index;
        std::uint32_t end_index;
    };
}
