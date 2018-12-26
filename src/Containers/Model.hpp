#pragma once

#include <functional>
#include <memory>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

namespace Containers {

/**
 * @brief Model class is a light-weight wrapper, with a string name, and a sf::Drawable object
 * 
 */
class Model {
 private:
    /**
     * @brief Empty model to assign to empty objects
     * 
     */
    static sf::RectangleShape empty_model;

    /**
     * @brief Stores the name of the model
     * 
     */
    std::string m_name;

    /**
     * @brief Stores a reference to the actual model
     * 
     */
    std::reference_wrapper<const sf::Drawable> m_model;
    
 public:
    /**
     * @brief Construct a new Model object
     * 
     */
    Model() : m_model(empty_model) { }

    /**
     * @brief Construct a new Model object
     * 
     * @param name The name to associate with this model
     * @param model The actual sf::Drawable object. It can be any drawable object, as long as SFML supports it
     */
    Model(const std::string& name, const sf::Drawable& model);

    /**
     * @brief Destroy the Model object. Nothing special going on.
     * 
     */
    ~Model() { }

    /**
     * @brief Copy constructor
     * 
     * @param other 
     */
    Model(const Model& other);

    /**
     * @brief Move constructor
     * 
     * @param other 
     */
    Model(Model&& other);

    /**
     * @brief Copy assignment
     * 
     * @param other 
     * @return Model& 
     */
    Model& operator=(const Model& other);

    /**
     * @brief Move assignment
     * 
     * @param other 
     * @return Model& 
     */
    Model& operator=(Model&& other);

    /**
     * @brief Get the name of the Model
     * 
     * @return std::string 
     */
    std::string get_name() const;

    /**
     * @brief Set the name of the model
     * 
     * @param name 
     */
    void set_name(const std::string& name);

    /**
     * @brief Get the sf::Drawable object
     * 
     * @return const sf::Drawable& 
     */
    const sf::Drawable& get_model() const;

    /**
     * @brief Set the model with the specified one. Stores it as a std::reference_wrapper<sf::Drawable>, so it can be copied.
     * 
     * @param model The actual sf::Drawable object
     */
    void set_model(sf::Drawable& model);
};
}  // namespace containers
