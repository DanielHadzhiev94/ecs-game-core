#pragma once
#include "systems/render/IRenderer.hpp"

class DummyRenderer : public IRenderer {
public:
    void draw(const RenderCommand &) override;
};
