#pragma once

#include "IRenderer.hpp"
#include "../game/commands/render_command.hpp"

namespace engine::render {
    class DummyRenderer : public IRenderer {
    public:
        void draw(const game::commands::RenderCommand &) override;
    };
}
