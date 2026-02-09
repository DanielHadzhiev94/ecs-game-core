#include "input_system.hpp"

namespace engine::game::input
{
    void InputSystem::add_device(std::unique_ptr<IInputDevice> device)
    {
        devices_.push_back(std::move(device));
    }

    void InputSystem::update()
    {
        state_ = InputState{};

        for (const auto &device : devices_)
        {
            device->poll(state_);
        }
    }

    const InputState InputSystem::state() const
    {
        return state_;
    }
}
