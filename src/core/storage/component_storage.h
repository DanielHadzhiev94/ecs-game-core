#pragma once
#include <memory>
#include <map>
#include <entity/entity_id.h>


template<typename T>
struct Component {
    EntityId generation;
    T component;
};

template<typename T>
class ComponentStorage {
public:
    bool create_component(EntityId);

    T *get(EntityId);

    bool destroy(EntityId);

private:
    std::unordered_map<std::size_t, Component<T> > components;
};
