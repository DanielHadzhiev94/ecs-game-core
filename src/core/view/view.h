#pragma once
#include "view_iterator.h"
#include "../registry/registry.h"

template<typename... Ts>
class View {
public:
    using iterator = ViewIterator<Ts...>;

    View() = delete;

    explicit View(Registry &_registry)
        : registry(_registry) {
    }

    ~View() = default;

    iterator begin() const;

    iterator end() const;

private:
    Registry &registry;
};
