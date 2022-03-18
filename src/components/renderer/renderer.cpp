#include "includes/node.hpp"
#include "includes/components/renderer/renderer.hpp"

Renderer::Renderer(const std::shared_ptr<Renderable>& mRenderable) : mRenderable(mRenderable)
{}

void Renderer::start()
{
    if (auto parentNode = node().lock())
    {
        auto transformOpt = parentNode->find_component<Transform>();

        if (transformOpt.has_value())
        {
            mTransform = std::move(transformOpt.value());
            return;
        }
    }

    throw std::runtime_error("'Renderer' component could not find a 'Transform' component on its node!");
}

std::unique_ptr<RenderFragment> Renderer::render(glm::vec2 aspectRatio) const
{
    return mRenderable->render(mTransform, aspectRatio);
}

void Renderer::set_renderable(const std::shared_ptr<Renderable>& renderable)
{
    this->mRenderable = renderable;
}

std::shared_ptr<Renderable> Renderer::renderable() const
{
    return mRenderable;
}