#pragma once

#include <typeindex>
#include <unordered_map>
#include <memory>
#include "component_storage.hpp"

namespace engine::ecs
{
    class StorageManager
    {
    public:
        template <typename T>
        ComponentStorage<T> &get_or_create();

        template <typename T>
        const ComponentStorage<T> *get() const;

        template <typename T>
        ComponentStorage<T> *get();

        template <typename T>
        bool remove_storage();

        void destroy_entity(EntityId);

    private:
        std::unordered_map<std::type_index, std::unique_ptr<IComponentStorage>> component_storages_;

        template <typename T>
        ComponentStorage<T> *find_storage();

        template <typename T>
        const ComponentStorage<T> *find_storage() const;
    };

    template <typename T>
    ComponentStorage<T> *StorageManager::find_storage()
    {
        const std::type_index key = {typeid(T)};

        auto it = component_storages_.find(key);
        if (it == component_storages_.end())
            return nullptr;

        return static_cast<ComponentStorage<T> *>(it->second.get());
    }

    template <typename T>
    const ComponentStorage<T> *StorageManager::find_storage() const
    {
        const std::type_index key = {typeid(T)};

        auto it = component_storages_.find(key);
        if (it == component_storages_.end())
            return nullptr;

        return static_cast<const ComponentStorage<T> *>(it->second.get());
    }

    template <typename T>
    ComponentStorage<T> &StorageManager::get_or_create()
    {
        auto storage = find_storage<T>();

        if (storage == nullptr)
        {
            const std::type_index key{typeid(T)};
            auto new_storage = std::make_unique<ComponentStorage<T>>();
            auto *raw = new_storage.get();
            component_storages_.emplace(key, std::move(new_storage));
            return *raw;
        }

        return *storage;
    }

    template <typename T>
    const ComponentStorage<T> *StorageManager::get() const
    {
        return find_storage<T>();
    }

    template <typename T>
    ComponentStorage<T> *StorageManager::get()
    {
        return find_storage<T>();
    }

    template <typename T>
    bool StorageManager::remove_storage()
    {
        const std::type_index key{typeid(T)};

        if (component_storages_.erase(key))
            return true;

        return false;
    }
}
