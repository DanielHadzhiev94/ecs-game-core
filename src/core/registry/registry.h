#pragma once

#include "entity/entity_id.h"
#include "entity/entity_manager.h"
#include "storage/storage_manager.h"

class EntityManager;
class StorageManager;

class Registry {
public:
    Registry(EntityManager &entity_manager, StorageManager &storage_manager)
        : em(entity_manager), sm(storage_manager) {
    }

    EntityId create();

    template<typename T>
    bool add(EntityId, T);

    template<typename T>
    bool remove(EntityId);

    template<typename T>
    bool has(EntityId) const;

    template<typename T>
    T *get(EntityId);

    template<typename T>
    const T *get(EntityId) const;

    bool is_alive(EntityId) const;

    void destroy(EntityId);

private:
    EntityManager &em;
    StorageManager &sm;
};

template<typename T>
bool Registry::add(const EntityId entity, T) {
    if (!is_alive(entity))
        return false;

    if (has<T>(entity))
        return false;

    auto *storage = sm.get_or_create<T>();
    return storage->create(entity);
}

template<typename T>
bool Registry::remove(const EntityId entity) {
    if (!is_alive(entity))
        return false;

    if (!has<T>(entity))
        return false;

    auto storage = sm.get<T>();
    return storage->destroy(entity);
}

template<typename T>
bool Registry::has(const EntityId entity) const {
    auto *storage = sm.get<T>();
    return em.is_alive(entity) && storage && storage->get(entity);
}

template<typename T>
T *Registry::get(const EntityId entity) {
    auto *storage = sm.get<T>();
    if (!em.is_alive(entity) || !storage)
        return nullptr;

    return storage->get(entity);
}

template<typename T>
const T *Registry::get(const EntityId entity) const {
    auto *storage = sm.get<T>();
    if (!em.is_alive(entity) || !storage)
        return nullptr;

    return storage->get(entity);
}
