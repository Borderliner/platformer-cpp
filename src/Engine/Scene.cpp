#include "Scene.hpp"

Engine::Scene::Scene() {
    // If not specified, set it to 60.0
    m_frame_time = 1.0 / 60.0;
}

Engine::Scene::Scene(std::shared_ptr<Engine::Window> window) {
    m_window = window;
    m_frame_time = 1.0 / m_window->get_fps();
}

void Engine::Scene::set_window(std::shared_ptr<Engine::Window> window) {
    m_window = window;
    m_frame_time = 1.0 / m_window->get_fps();
}

void Engine::Scene::render() {
    pre_frame();
    on_frame();
    post_frame();
    restart_clock();
}

void Engine::Scene::pre_frame() {
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

void Engine::Scene::on_frame() {
    // Display everything by swapping the buffers
    if (m_elapsed_time.asSeconds() > m_frame_time) {
        m_window->get_window()->display();

        m_elapsed_time -= sf::seconds(m_frame_time);
    }
}

void Engine::Scene::post_frame() { }

void Engine::Scene::add_model(std::shared_ptr<Containers::Model> model) {
    m_models.push_back(model);
}

void Engine::Scene::add_model(Containers::Model model) {
    m_models.push_back(std::make_shared<Containers::Model>(model));
}

std::shared_ptr<Containers::Model> Engine::Scene::get_model(const std::string& name) {
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

void Engine::Scene::delete_model(const std::string& name) {
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

Containers::Model Engine::Scene::make_model(const std::string& name, const sf::Drawable& drawable) {
    return Containers::Model{name, drawable};
}

sf::Time Engine::Scene::get_elapsed_time() {
    return m_elapsed_time;
}

void Engine::Scene::restart_clock() {
    m_elapsed_time += m_clock.restart();
}