#pragma once

#include <unordered_set>
#include <tuple>

#include "entity/entity_id.hpp"
#include "entity/entity_id_hash.hpp"
#include "entity/entity_manager.hpp"
#include "storage/storage_manager.hpp"

class EntityManager;
class StorageManager;

class Registry {
public:
    explicit Registry(EntityManager &entity_manager, StorageManager &storage_manager);

    EntityId create();

    template<typename T>
    bool add(EntityId);

    template<typename T>
    bool remove(EntityId);

    template<typename T>
    bool has(EntityId) const;

    template<typename T>
    T *get(EntityId);

    template<typename T>
    const T *get(EntityId) const;

    bool is_alive(EntityId) const;

    EntityId entity_from_index(std::uint32_t) const;

    std::size_t entity_capacity() const;

    bool schedule_destruction(EntityId);

    void execute_scheduled_destruction();

private:
    EntityManager &entity_manager;
    StorageManager &storage_manager;
    std::unordered_set<EntityId> destruction_queue;

    void destroy(EntityId);
};

template<typename T>
bool Registry::add(const EntityId entity) {
    if (!is_alive(entity))
        return false;

    if (has<T>(entity))
        return false;

    auto &storage = storage_manager.get_or_create<T>();
    return storage.create(entity);
}

template<typename T>
bool Registry::remove(const EntityId entity) {
    if (!is_alive(entity))
        return false;

    if (!has<T>(entity))
        return false;

    auto storage = storage_manager.get<T>();
    if (storage == nullptr)
        return false;

    return storage->destroy(entity);
}

template<typename T>
bool Registry::has(const EntityId entity) const {
    auto *storage = storage_manager.get<T>();
    return entity_manager.is_alive(entity) && storage && storage->get(entity);
}

template<typename T>
T *Registry::get(EntityId entity) {
    auto *storage = storage_manager.get<T>();
    if (!entity_manager.is_alive(entity) || !storage)
        return nullptr;

    return storage->get(entity);
}

template<typename T>
const T *Registry::get(EntityId entity) const {
    auto *storage = storage_manager.get<T>();
    if (!entity_manager.is_alive(entity) || !storage)
        return nullptr;

    return storage->get(entity);
}
