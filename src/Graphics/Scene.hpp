#pragma once

#include <memory>
#include <vector>

#include "Window.hpp"
#include "Model.hpp"

namespace GFX {
class Scene {
 public:
    Scene();
    Scene(std::shared_ptr<GFX::Window> window);

    void set_window(std::shared_ptr<GFX::Window> window);

    void render();

    void pre_frame();
    void on_frame();
    void post_frame();

    void add_model(std::shared_ptr<Containers::Model> model);
    void add_model(Containers::Model model);
    std::shared_ptr<Containers::Model> get_model(const std::string& name);
    void delete_model(const std::string& name);
    Containers::Model make_model(const std::string& name, const sf::Drawable& drawable);
 private:

    std::shared_ptr<GFX::Window> m_window;
    std::vector<std::shared_ptr<Containers::Model> > m_models;
};
}  // namespace GFX
