#pragma once

#include <vector>

#include "input_device.hpp"
#include "input_state.hpp"

namespace engine::game::input
{
    class InputSystem
    {
    public:
        void add_device(std::unique_ptr<IInputDevice> device);

        void update();

        const InputState state() const;

    private:
        InputState state_;
        std::vector<std::unique_ptr<IInputDevice>> devices_;
    };
}
