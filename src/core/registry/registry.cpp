#include "registry.h"

#include "entity/entity_manager.h"

EntityId Registry::create() {
    return em.create_entity();
}

bool Registry::is_alive(const EntityId entity) const {
    return em.is_alive(entity);
}

void Registry::destroy(const EntityId entity) {
    if (!is_alive(entity))
        return;

    sm.destroy_entity(entity);
    em.destroy(entity);
}
