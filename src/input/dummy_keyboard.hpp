#pragma once

#include "input_device.hpp"
#include "input_context.hpp"

namespace engine::input {
    class DummyKeyboard final : public IInputDevice {
    public:
        explicit DummyKeyboard(const InputContext &context);

        void poll(InputState &state) override;

    private:
        const InputContext &context;
        bool toggle = false;
    };
}
