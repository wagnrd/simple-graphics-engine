#include "includes/components/renderer/renderer.hpp"
#include "includes/systems/renderers/text_renderer/text_renderer.hpp"
#include "glm/glm.hpp"

void TextRenderer::add_display(const std::shared_ptr<Camera>& camera, const std::shared_ptr<TextDisplay>& display)
{
    if (!mCameras.contains(camera))
        mCameras[camera] = std::unordered_set<std::shared_ptr<TextDisplay>>();

    mCameras[camera].insert(display);
}

void TextRenderer::swap_camera(const std::shared_ptr<Camera>& oldCamera, const std::shared_ptr<Camera>& newCamera)
{
    auto it = mCameras.find(oldCamera);

    if (it == mCameras.end())
        return;

    auto displays = std::move(it->second);
    mCameras.erase(it);
    mCameras[newCamera] = displays;
}

void TextRenderer::process()
{
    for (const auto&[camera, displays]: mCameras)
    {
        auto rootNode = camera->renderable_node_tree();

        for (const auto& display: displays)
        {
            auto renderedImage = render(rootNode);
            display->draw(std::move(renderedImage));
        }
    }
}

std::unique_ptr<TextRenderFragment> TextRenderer::render(const std::shared_ptr<Node>& node) const
{
    auto rendererOpt = node->find_component<Renderer>();

    if (rendererOpt.has_value())
    {
        auto renderFragment = rendererOpt.value()->render(glm::vec2(1, 1));
        auto textRenderFragment = std::make_unique<TextRenderFragment>(renderFragment->width, renderFragment->height);

        for (size_t i = 0; i < renderFragment->height; ++i)
        {
            for (size_t j = 0; j < renderFragment->width; ++j)
            {
                auto index = i * renderFragment->width + j;
                auto color = renderFragment->content[index];

                if (color.r >= 200 || color.g >= 200 || color.b >= 200)
                    textRenderFragment->content[index] = '#';
                else if (color.r >= 100 || color.g >= 100 || color.b >= 100)
                    textRenderFragment->content[index] = '+';
                else
                    textRenderFragment->content[index] = ' ';
            }
        }

        return textRenderFragment;
    }

    return {};
}