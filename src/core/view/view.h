#pragma once
#include <cstdint>
#include "view_iterator.h"
#include "../registry/registry.h"

template<typename... Ts>
class View {
public:
    using iterator = ViewIterator<Ts...>;

    View() = delete;

    explicit View(Registry &registry)
        : registry(registry),
          begin_index(0),
          end_index(registry.entity_count()) {
    }

    ~View() = default;

    iterator begin() const {
        return iterator(registry, begin_index, end_index);
    };

    iterator end() const {
        return iterator(registry, end_index, end_index);
    };

private:
    Registry &registry;
    std::size_t begin_index;
    std::size_t end_index;
};
