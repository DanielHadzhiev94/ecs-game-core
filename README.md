# ECS Game Core (C++)

This repository contains a small game core written in modern C++, with a strong
focus on **data-oriented design**, **explicit lifetime management**, and
**ECS-based architecture**.

The project is developed as a portfolio project with an emphasis on
engine-level decision making rather than feature completeness.

---

## Goals

- Implement a minimal but robust **Entity Component System (ECS)** core
- Demonstrate safe and explicit **entity identity and lifetime management**
- Avoid inheritance-heavy designs in favor of **composition**
- Keep systems decoupled and data-driven
- Maintain clear separation between engine core and game logic

---

## Non-goals

- This is **not** a full-featured engine
- This is **not** a Unity-style ECS clone
- Visual fidelity is secondary to architectural clarity

---

## Core Concepts

- **Entities** are lightweight identifiers (index + generation)
- **Components** are plain data, stored in cache-friendly layouts
- **Systems** operate on data, not objects
- No `shared_ptr`, no hidden ownership, no implicit lifetimes

---

## Project Structure

```
src/
  core/       Entity management, IDs, component storage
  systems/    Gameplay and engine systems
  platform/   Windowing, input, timing
  game/       Game-specific composition and logic
```

---

## Build

The project uses **CMake** and targets modern C++ (C++20).

```
mkdir build
cd build
cmake ..
cmake --build .
```

---

## Status

The project is developed incrementally using clearly defined milestones.
Each milestone focuses on a specific architectural concern
(e.g. entity lifetime, component storage, system execution).
