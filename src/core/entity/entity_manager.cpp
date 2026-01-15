#include <iostream>
#include "entity_manager.h"

#include <cassert>


EntityId EntityManager::create_entity() {
    std::uint32_t index;

    if (!free_indexes.empty()) {
        index = free_indexes.back();
        free_indexes.pop_back();
    } else {
        index = slots.size();
        slots.push_back(Slot{});
    }

    return {index, slots[index].generation};
}

bool EntityManager::is_alive(const EntityId entity) const {
    if (entity.index >= slots.size())
        return false;

    const auto &[generation] = slots[entity.index];
    if (entity.generation != generation)
        return false;

    return true;
}

void EntityManager::destroy(const EntityId entity) {
    if (is_alive(entity)) {
        auto &[generation] = slots[entity.index];
        ++generation;
        free_indexes.push_back(entity.index);
    }
}

EntityId EntityManager::entity_from_index(uint32_t index) {
    assert(index < slots.size());
    return EntityId{ index, slots[index].generation };
}

std::size_t EntityManager::entity_capacity() const {
    return slots.size();
}
