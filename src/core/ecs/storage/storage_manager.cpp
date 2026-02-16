#include "ecs/storage/storage_manager.hpp"

namespace engine::ecs
{
    void StorageManager::destroy_entity(const EntityId entity)
    {
        for (auto &[_, storage] : component_storages_)
        {
            storage.get()->destroy(entity);
        }
    }
}
