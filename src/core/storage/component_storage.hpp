#pragma once
#include <unordered_map>
#include "../entity/entity_id.hpp"

struct IComponentStorage {
    virtual ~IComponentStorage() = default;

    virtual bool destroy(EntityId);
};

template<typename T>
class ComponentStorage final : public IComponentStorage {
public:
    bool create(EntityId entity) {
        auto it = components.find(entity.index);
        if (it != components.end())
            return false;

        components.emplace(entity.index, T{});

        return true;
    }

    T *get(EntityId entity) {
        auto it = components.find(entity.index);
        if (it == components.end())
            return nullptr;

        return &it->second;
    }

    const T *get(EntityId entity) const {
        auto it = components.find(entity.index);
        if (it == components.end())
            return nullptr;

        return &it->second;
    }

    bool destroy(EntityId entity) override {
        auto it = components.find(entity.index);
        if (it != components.end()) {
            components.erase(entity.index);

            return true;
        }

        return false;
    }

private:
    std::unordered_map<std::size_t, T> components;
};
