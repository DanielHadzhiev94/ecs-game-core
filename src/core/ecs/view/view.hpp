#pragma once

#include "view_iterator.hpp"
#include "../registry/registry.hpp"

namespace engine::ecs {
    template<typename... Ts>
    class View {
    public:
        using iterator = ViewIterator<Ts...>;

        View() = delete;

        explicit View(Registry &registry)
            : registry(registry),
              begin_index(0),
              end_index(registry.entity_capacity()) {
        }

        ~View() = default;

        iterator begin() const {
            iterator it(registry, begin_index, end_index);
            it.advance_to_valid();
            return it;
        }

        iterator end() const {
            return iterator(registry, end_index, end_index);
        }

    private:
        Registry &registry;
        std::uint32_t begin_index;
        std::uint32_t end_index;
    };
}
