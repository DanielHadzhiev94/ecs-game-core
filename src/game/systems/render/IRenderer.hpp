#pragma once
#include "../../commands/render_command.hpp"

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual void draw(const RenderCommand &) = 0;
};
