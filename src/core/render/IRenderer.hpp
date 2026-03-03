#pragma once

#include "game/commands/render_command.hpp"


namespace engine::render {
    class IRenderer {
    public:
        virtual ~IRenderer() = default;

        virtual void draw(const game::commands::RenderCommand &) = 0;
    };
}
