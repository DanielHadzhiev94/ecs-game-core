#pragma once
#include <vector>
#include <unordered_map>
#include "../entity/entity_id.hpp"

namespace engine::ecs
{

    struct IComponentStorage
    {
        virtual ~IComponentStorage() = default;

        virtual bool destroy(EntityId) = 0;
    };

    template <typename T>
    class ComponentStorage final : public IComponentStorage
    {
    public:
        template <typename... Args>
        T &emplace(EntityId entity, Args &&...args)
        {

            std::size_t index = components_.size();
            components_.emplace_back(std::forward<Args>(args)...);
            index_to_entity_.push_back(entity);
            entity_to_index_.emplace(entity.index, index);

            return components_.back();
        }

        T *get(EntityId entity)
        {
            auto it = entity_to_index_.find(entity.index);
            if (it == entity_to_index_.end())
                return nullptr;

            return &components_[it->second];
        }

        const T *get(EntityId entity) const
        {
            auto it = entity_to_index_.find(entity.index);
            if (it == entity_to_index_.end())
                return nullptr;

            return &components_.at(it->second);
        }

        bool has(EntityId entity)
        {
            return entity_to_index_.find(entity.index) != entity_to_index_.end();
        }

        std::vector<T> &raw()
        {
            return components_;
        }

        bool destroy(EntityId entity) override
        {
            auto it = entity_to_index_.find(entity.index);
            if (it == entity_to_index_.end())
                return false;

            const std::size_t index = it->second;
            const std::size_t last_index = components_.size() - 1;

            // Swap current component with  component on the last position
            components_[index] = std::move(components_[last_index]);

            // Get the entity on the last index
            EntityId last_entity = index_to_entity_[last_index];

            // Replace the entity in the searched index, with the entity of the last element
            // this way we can remove the last element
            index_to_entity_[index] = last_entity;
            entity_to_index_[last_entity.index] = index;

            components_.pop_back();
            index_to_entity_.pop_back();
            entity_to_index_.erase(it);

            return true;
        }

    private:
        std::vector<T> components_;
        std::vector<EntityId> index_to_entity_;
        std::unordered_map<std::size_t, std::size_t> entity_to_index_;
    };
}
