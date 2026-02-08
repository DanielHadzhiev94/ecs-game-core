#include "dummy_keyboard.hpp"

namespace engine::game::input
{
    DummyKeyboard::DummyKeyboard(const InputContext &context)
        : context(context)
    {
    }

    void DummyKeyboard::poll(InputState &state)
    {
        toggle = !toggle;

        state.set_pressed(InputAction::MoveLeft, toggle);
        state.set_pressed(InputAction::MoveRight, !toggle);
        state.set_pressed(InputAction::Jump, false);
    }
}
