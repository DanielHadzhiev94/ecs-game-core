#include "registry.h"

#include "entity/entity_manager.h"

Registry::Registry(EntityManager &entity_manager, StorageManager &storage_manager)
    : entity_manager(entity_manager), storage_manager(storage_manager) {
}

EntityId Registry::create() {
    return entity_manager.create_entity();
}

bool Registry::is_alive(const EntityId entity) const {
    return entity_manager.is_alive(entity);
}

void Registry::destroy(const EntityId entity) {
    if (!is_alive(entity))
        return;

    storage_manager.destroy_entity(entity);
    entity_manager.destroy(entity);
}

std::size_t Registry::entity_capacity() const {
    return entity_manager.entity_capacity();
}

bool Registry::schedule_destruction(EntityId entity) {
    if (!entity_manager.is_alive(entity))
        return false;

    auto [_, result] = destruction_queue.insert(entity);
    return result;
}

void Registry::execute_scheduled_destruction() {
    for (auto &entity: destruction_queue) {
        destroy(entity);
    }

    destruction_queue.clear();
}
