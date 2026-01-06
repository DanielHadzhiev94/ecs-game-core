# ECS Registry – Design Notes

## 1. Context & Goal

- The Registry is a coordination layer and the only system that has the right to combine information about entity
  lifetime and component presence.
  It does not own entities and does not own component data.
  The Registry acts as an arbitrator that enforces invariants between the EntityManager and ComponentStorage, ensuring
  that component data can only exist and be accessed for valid entities.

## 2. Core Concepts

- **Entity**
    - Represents an opaque identifier used to reference objects in the ECS.
    - It consists of an index and a generation but does not perform any validation or lifetime checks itself.
    - Entity validity and lifetime are managed exclusively by the EntityManager.
- **StorageManager**
    - Owns and manages component storage containers.
    - Provides access to component data indexed by entity identifiers.
    - Does not perform entity lifetime or validity checks.
- **Registry**
    - Acts as the authoritative coordination layer between entity identity and component data.
    - Validates entity lifetime via the EntityManager before allowing access to component storage.
    - Enforces structural invariants across EntityManager and StorageManager without owning either.

## 3. Responsibilities

This section answers “Who is responsible for what?”
Each responsibility must be exclusive.

- **EntityManager**
    - Owns and manages entity identity and lifetime.
    - Creates and destroys entities.
    - Tracks entity validity using index + generation.
    - Does not know about components or component storage.

- **StorageManager / ComponentStorage**
    - Owns and manages component data storage.
    - Stores component data indexed by entity identifiers.
    - Performs no entity lifetime or validity checks.
    - Does not create or destroy entities.

- **Registry**
    - Acts as the authoritative coordinator between entity identity and component data.
    - Validates entity lifetime via the EntityManager before any structural component operation.
    - Delegates component data manipulation to the appropriate ComponentStorage.
    - Ensures structural consistency when entities are destroyed.

## 4. Invariants

This section defines rules that must never be violated.

- **Core Invariants**
    - An entity is considered valid if and only if the EntityManager confirms its lifetime.
    - Component data must never exist for an invalid entity.
    - ComponentStorage must not perform entity validity checks.
    - EntityManager must not be aware of components.
    - Registry is the only system allowed to combine entity lifetime and component presence.

- **Structural Invariants**
    - All components associated with an entity are removed when the entity is destroyed.
    - Component storage indices must remain stable across entity reuse.

## 5. Allowed / Disallowed Operations

This section prevents architecture drift.

- **Allowed**
    - Registry querying EntityManager to validate an EntityId.
    - Registry adding or removing components via ComponentStorage.
    - ComponentStorage storing and retrieving data by entity identifier.

- **Disallowed**
    - ComponentStorage checking entity generation or validity.
    - EntityManager accessing component data.
    - Systems or game logic modifying component storage directly.
    - Entity objects performing lifetime checks.

## 6. Non-Goals

This section defines what you are intentionally not solving yet.

- System execution and scheduling.
- Query and iteration APIs.
- Performance optimizations (cache layout, archetypes).
- Multithreading and job systems.
- Serialization and persistence.
