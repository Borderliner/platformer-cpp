#pragma once

#include <memory>
#include <vector>

#include "Window.hpp"
#include "Model.hpp"

namespace GFX {

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
     * @param window The GFX::Window handle
     */
    Scene(std::shared_ptr<GFX::Window> window);

    /**
     * @brief Set the window
     * 
     * @param window a GFX::Window pointer
     */
    void set_window(std::shared_ptr<GFX::Window> window);

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

    /**
     * @brief Associated Window
     * 
     */
    std::shared_ptr<GFX::Window> m_window;

    /**
     * @brief A vector containing all models in game
     * 
     */
    std::vector<std::shared_ptr<Containers::Model> > m_models;
};
}  // namespace GFX
