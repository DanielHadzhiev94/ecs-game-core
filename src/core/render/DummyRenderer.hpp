#pragma once
#include "IRenderer.hpp"


namespace engine::render {
    class DummyRenderer : public IRenderer {
    public:
        void draw(const RenderCommand &) override;
    };
}
