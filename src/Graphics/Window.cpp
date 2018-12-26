#include "Window.hpp"

GFX::Window::Window() : Window(1024, 768, "Main Window") {}

GFX::Window::Window(unsigned int window_width, unsigned int window_height, const std::string& window_title) {
    m_window_width = window_width;
    m_window_height = window_height;
    m_window_title = window_title;
    m_fullscreen = false;
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Default);

    if (m_window == nullptr) {
        std::cerr << "Cannot create SFML window. Make sure DISPLAY=:0 environment variable is set." << std::endl;
        GFX::Window::~Window();
    }
}

GFX::Window::~Window() {
    m_window_width = 0;
    m_window_height = 0;
    m_window_title = "";
    m_window->close();
    m_window.reset();
}

std::shared_ptr<sf::RenderWindow> GFX::Window::get_window() const {
    return m_window;
}

void GFX::Window::poll_events() {
    while (m_window->pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed) {
            m_window->close();
        }

        if ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code == sf::Keyboard::Escape)) {
            m_window->close();
        }

        if ((m_event.type == sf::Event::KeyPressed) && (m_event.key.code == sf::Keyboard::F5)) {
            set_fullscreen(!m_fullscreen);
        }

        if (m_event.type == sf::Event::Resized) {
        }
    }
}

bool GFX::Window::is_open() {
    return m_window->isOpen();
}

void GFX::Window::set_fullscreen(bool fullscreen) {
    // If not already fullscreen, and fullscreen was requested
    if (!m_fullscreen && fullscreen) {
        m_window->create(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Fullscreen);
        m_fullscreen = fullscreen;
    // If it's already fullscreen, but requested otherwise
    } else if (m_fullscreen && !fullscreen) {
        m_window->create(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Default);
        m_fullscreen = fullscreen;
    } else {
        // pass
    }
}
