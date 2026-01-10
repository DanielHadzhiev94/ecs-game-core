#include <iostream>
#include "entity_manager.h"


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

bool EntityManager::is_alive(const EntityId entity_id) const {
    if (entity_id.index >= slots.size())
        return false;

    if (const auto &[generation] = slots[entity_id.index]; entity_id.generation != generation)
        return false;

    return true;
}

void EntityManager::destroy(const EntityId entity_id) {
    if (is_alive(entity_id)) {
        auto &[generation] = slots[entity_id.index];
        ++generation;
        free_indexes.push_back(entity_id.index);
    }
}

std::size_t EntityManager::entity_count() const {
    return slots.size();
}
