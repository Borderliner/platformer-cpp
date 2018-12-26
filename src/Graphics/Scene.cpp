#include "Scene.hpp"

GFX::Scene::Scene() {}

GFX::Scene::Scene(std::shared_ptr<GFX::Window> window) {
    m_window = window;
}

void GFX::Scene::set_window(std::shared_ptr<GFX::Window> window) {
    m_window = window;
}

void GFX::Scene::render() {
    pre_frame();
    on_frame();
    post_frame();
}

void GFX::Scene::pre_frame() {
    m_window->get_window()->setActive(true);
    m_window->get_window()->clear(sf::Color::Black);

    // Loop through all models here.
    for (auto& model : m_models) {
        // And call draw() function on everything
        // Here finally we unpack the sf::Drawable buried deep inside the model
        // Clean and modern C++17 API, yaaay!
        m_window->get_window()->draw(model->get_model());
    }
}

void GFX::Scene::on_frame() {
    // Display everything by swapping the buffers
    m_window->get_window()->display();
}

void GFX::Scene::post_frame() { }

void GFX::Scene::add_model(std::shared_ptr<Containers::Model> model) {
    m_models.push_back(model);
}

void GFX::Scene::add_model(Containers::Model model) {
    m_models.push_back(std::make_shared<Containers::Model>(model));
}

std::shared_ptr<Containers::Model> GFX::Scene::get_model(const std::string& name) {
    if (!name.empty()) {
        for (auto& model : m_models) {
            if (model->get_name() == name) {
                return model;
            }
        }

        std::cerr << "Cannot find a model called \"" << name << "\" to retrieve" << std::endl;
        return nullptr;
    } else {
        std::cerr << "Cannot get the model. Specified name is empty." << std::endl;
        return nullptr;
    }
}

void GFX::Scene::delete_model(const std::string& name) {
    if (!name.empty()) {
        m_models.erase(
            std::remove_if(
                m_models.begin(),
                m_models.end(),
                [&name](std::shared_ptr<Containers::Model> model) -> bool {
                    if (model->get_name() == name) {
                        model->set_name("");
                        model.reset();

                        // Returning true erases this model from m_models.
                        return true;
                    } else {
                        return false;
                    }
                }
            ),
            m_models.end()
        );
    } else {
        std::cerr << "Cannot delete the model. Specified name is empty." << std::endl;
    }
}

Containers::Model GFX::Scene::make_model(const std::string& name, const sf::Drawable& drawable) {
    return Containers::Model{name, drawable};
}
