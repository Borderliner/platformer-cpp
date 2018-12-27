#pragma once

#include <memory>
#include <vector>

#include "Window.hpp"
#include "Model.hpp"

namespace Engine {

/**
 * @brief Scene class deals with model management, camera, rendering and holding whatever data is on the scene
 * 
 */
class Scene {
 public:
    /**
     * @brief Construct a new Scene object
     * 
     */
    Scene();

    /**
     * @brief Construct a new Scene object
     * 
     * @param window The Engine::Window handle
     */
    Scene(std::shared_ptr<Engine::Window> window);

    /**
     * @brief Set the window
     * 
     * @param window a Engine::Window pointer
     */
    void set_window(std::shared_ptr<Engine::Window> window);

    /**
     * @brief This is the main rendering loop. It calls pre_frame(), on_frame(), and post_frame() respectively.
     * 
     */
    void render();

    /**
     * @brief Things to do before each frame
     * 
     */
    void pre_frame();

    /**
     * @brief Things to do during a frame
     * 
     */
    void on_frame();

    /**
     * @brief Things to do after a frame
     * 
     */
    void post_frame();

    /**
     * @brief Adds a Containers::Model to the game objects vector
     * 
     * @param model A Containers::Model object, with a sf::Drawable in it
     */
    void add_model(std::shared_ptr<Containers::Model> model);

    /**
     * @brief Adds a Containers::Model to the game objects vector
     * 
     * @param model A Containers::Model object, with a sf::Drawable in it
     */
    void add_model(Containers::Model model);

    /**
     * @brief Get the model by name
     * 
     * @param name 
     * @return std::shared_ptr<Containers::Model> 
     */
    std::shared_ptr<Containers::Model> get_model(const std::string& name);

    /**
     * @brief Delete a model from game objects vector by name
     * 
     * @param name 
     */
    void delete_model(const std::string& name);

    /**
     * @brief This is an intermediate function, which creates a Containers::Model object from a string and a sf::Drawable
     * 
     * @param name 
     * @param drawable A sf::Drawable object to wrap in
     * @return Containers::Model 
     */
    Containers::Model make_model(const std::string& name, const sf::Drawable& drawable);
 private:
    sf::Time get_elapsed_time();
    void restart_clock();

    /**
     * @brief Associated Window
     * 
     */
    std::shared_ptr<Engine::Window> m_window;

    /**
     * @brief A vector containing all models in game
     * 
     */
    std::vector<std::shared_ptr<Containers::Model> > m_models;
    sf::Clock m_clock;
    sf::Time m_elapsed_time;
    float m_frame_time;
};
}  // namespace Engine
