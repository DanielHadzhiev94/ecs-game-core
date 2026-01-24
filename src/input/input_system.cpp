#include "input_system.hpp"

namespace engine::input {
    void InputSystem::add_device(std::unique_ptr<IInputDevice> device) {
        devices_.push_back(std::move(device));
    }

    void InputSystem::update() {
        // 1. Reset input state for the current frame
        state_ = InputState{};

        // 2. Poll all input devices
        for (const auto &device: devices_) {
            device->poll(state_);
        }
    }

    const InputState InputSystem::state() const {
        return state_;
    }
}
