#include "Model.hpp"

sf::RectangleShape Containers::Model::empty_model = sf::RectangleShape(sf::Vector2f(0.0f, 0.0f));

Containers::Model::Model(const std::string& name, const sf::Drawable& model) : m_model(std::ref(model)) {
    if (!name.empty() && name.length() < 255) {
        m_name = name;
    } else {
        std::cerr << "Invalid model \"" << name << "\"" << std::endl;
        std::cerr << "Make sure the name is not empty, it's less than 255 characters, and the model is valid." << std::endl;
    }
}

Containers::Model::Model(const Model& other) : m_model(other.m_model) {
    m_name = other.m_name;
}

Containers::Model::Model(Model&& other) : m_model(std::move(other.m_model)) {
    m_name = other.m_name;
    other.m_name = "";
}

Containers::Model& Containers::Model::operator=(const Model& other) {
    m_name = other.m_name;
    m_model = other.m_model;

    return *this;
}

Containers::Model& Containers::Model::operator=(Model&& other) {
    m_name = other.m_name;
    other.m_name = "";
    m_model = std::move(other.m_model);

    return *this;
}