#include "registry.h"

#include "entity/entity_manager.h"

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
