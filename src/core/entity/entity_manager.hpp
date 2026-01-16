#pragma once

#include <vector>
#include "entity_id.hpp"


struct Slot {
    uint32_t generation = 0;
};

class EntityManager {
public:
    EntityId create_entity();

    void destroy(EntityId);

    bool is_alive(EntityId) const;

    EntityId entity_from_index(uint32_t);

    std::size_t entity_capacity() const;

private:
    std::vector<Slot> slots;
    std::vector<uint32_t> free_indexes;
};
