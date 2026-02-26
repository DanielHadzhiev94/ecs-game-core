#include <algorithm>

#include "game.hpp"

Game::Game()
    : world() {
}

bool Game::is_running() const {
    return state == GameState::Running;
}

void Game::start() {
    if (state == GameState::Idle) {
        state = GameState::Running;
        run();
    }
}

void Game::stop() {
    if (state == GameState::Running)
        state = GameState::Stopped;
}

void Game::run() {
    // Create player and enemy
    world.initialization_demo();

    // Set the last_frame here, to prevent
    // to large first FrameTime
    clock.set_initial_frame();

    while (is_running()) {
        auto frameTime = clock.restart();
        frameTime = std::min(frameTime, MAX_FRAME_TIME);

        world.tick(frameTime);
    }
}
