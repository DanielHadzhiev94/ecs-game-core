#pragma once

#include <vector>
#include "entity_id.h"

struct Slot {
    uint32_t generation = 0;
};

class EntityManager {
public:
    EntityId create_entity();

    void destroy(EntityId);

    bool is_alive(EntityId) const;

    std::size_t entity_count() const;

private:
    std::vector<Slot> slots;
    std::vector<uint32_t> free_indexes;
};
