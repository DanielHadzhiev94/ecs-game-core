# C++ ECS Gameplay Framework

This repository contains a small gameplay-focused engine core written in modern C++.

The project demonstrates a minimal **Entity Component System (ECS)** architecture together with a simple gameplay loop including movement, attacks, cooldowns, damage handling, and entity lifetime management.

The primary goal of the project is to explore **data-oriented design, explicit ownership, and system-driven gameplay logic**.

---

# Overview

This project implements a lightweight ECS framework together with a small gameplay simulation.

The architecture focuses on:

- explicit entity identity and lifetime management
- data-oriented component storage
- decoupled gameplay systems
- minimal ownership complexity

The project intentionally avoids complex rendering or engine features in order to focus on **core gameplay architecture and ECS design**.

---

# Gameplay Demo

The demo simulates a simple combat interaction between a player and an enemy.

Implemented gameplay systems include:

- Input system
- Movement system
- Attack system
- Cooldown system
- Damage / health system
- Enemy AI system
- Entity lifetime management

Example run output:
- [Health System] Target 1 Receive dmg: 10 Remaining health: 10
- [Attack System] Spell is in cooldown: 5s
- [Health System] Target 1 Receive dmg: 10 Remaining health: 0
- [Lifetime System] Target 1 is dead
  
This demonstrates the gameplay pipeline:
Input → AttackSystem → Cooldown → Damage → HealthSystem → LifetimeSystem


---

# Core Concepts

## Entities

Entities are lightweight identifiers composed of:
index + generation


This allows entity slots to be safely reused without creating dangling references.

---

## Components

Components are simple data structures that contain no behavior.

They are stored in **contiguous memory layouts** to improve cache locality and iteration performance.

---

## Systems

Systems contain gameplay logic and operate on component data.

The architecture intentionally avoids:

- inheritance-heavy object hierarchies
- `shared_ptr`
- hidden ownership
- implicit lifetimes

This keeps gameplay code explicit and predictable.

---

# Project Structure
src/
core/ ECS core (entity IDs, registry, component storage)
systems/ Gameplay systems
platform/ Windowing, input, timing
game/ Game composition and demo logic


---

# Build

The project uses **CMake** and targets **C++20**.

mkdir build
cd build
cmake ..
cmake --build .


---

# Run

After building the project, run the demo executable:
./demo/ecs_demo

---

# Status

The project is developed incrementally using milestone-based development.

Each milestone focuses on a specific architectural concern such as:

- entity lifetime management
- component storage
- system execution
- gameplay interaction

The current version demonstrates a complete minimal gameplay loop implemented using ECS.


