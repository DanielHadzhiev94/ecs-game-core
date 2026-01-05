#include "component_storage.h"

template<typename T>
bool ComponentStorage<T>::create_component(const EntityId entity) {
    auto it = components.find(entity.index);
    if (it != components.end() && it->second.generation == entity.generation)
        return false;

    components[entity.index] = Component{entity.generation, std::make_unique<T>()};

    return true;
}

template<typename T>
T *ComponentStorage<T>::get(const EntityId entity) {
    auto it = components.find(entity.index);
    if (it == components.end() || it->second.generation != entity.generation)
        return nullptr;

    return it->second.current.get();
}

template<typename T>
bool ComponentStorage<T>::destroy(const EntityId entity) {
    auto it = components.find(entity.index);
    if (it != components.end() && it->second.generation == entity.generation) {
        components.erase(entity.index);

        return true;
    }

    return false;
}
