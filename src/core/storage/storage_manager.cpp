#include "storage/storage_manager.h"

void StorageManager::destroy_entity(const EntityId entity) {
    for (auto &[_, storage]: components) {
        storage.get()->destroy(entity);
    }
}
