#pragma once

#include <functional>
#include <memory>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

namespace Containers {
class Model {
 private:
    static sf::RectangleShape empty_model;
    std::string m_name;
    std::reference_wrapper<const sf::Drawable> m_model;
    
 public:
    Model() : m_model(empty_model) { }
    Model(const std::string& name, const sf::Drawable& model);
    ~Model() { }
    Model(const Model& other);
    Model(Model&& other);

    Model& operator=(const Model& other);
    Model& operator=(Model&& other);

    std::string get_name() const {
        return m_name;
    }
    
    void set_name(const std::string& name) {
        if (!name.empty() && name.length() < 255) {
            m_name = name;
        } else {
            std::cerr << "Cannot set model name to \"" << name << "\". It's either empty, or longer than 255 characters." << std::endl;
        }
    }

    const sf::Drawable& get_model() const {
        return m_model.get();
    }

    void set_model(sf::Drawable& model) {
        m_model = model;
    }
};

}  // namespace containers
