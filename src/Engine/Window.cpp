#include "Window.hpp"

Engine::Window::Window() : Window(1024, 768, "Main Window") {}

Engine::Window::Window(unsigned int window_width, unsigned int window_height, const std::string& window_title, float fps) {
    m_window_width = window_width;
    m_window_height = window_height;
    m_window_title = window_title;
    m_initial_aspect_ratio = static_cast<float>(window_width) / static_cast<float>(window_height);
    m_fullscreen = false;
    set_fps(fps);
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Default);

    if (m_window == nullptr) {
        std::cerr << "Cannot create SFML window. Make sure DISPLAY=:0 environment variable is set." << std::endl;
        Engine::Window::~Window();
    }
}

Engine::Window::~Window() {
    m_window_width = 0;
    m_window_height = 0;
    m_window_title = "";
    m_window->close();
    m_window.reset();
}

std::shared_ptr<sf::RenderWindow> Engine::Window::get_window() const {
    return m_window;
}

void Engine::Window::poll_events() {
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
            if (!m_fullscreen) {
                m_window_width = m_event.size.width;
                m_window_height = m_event.size.height;
                float new_width = m_initial_aspect_ratio * m_window_height;
                float new_height = m_window_width / m_initial_aspect_ratio;
                float offset_width = (m_window_width - new_width) / 2.0;
                float offset_height = (m_window_height - new_height) / 2.0;
                sf::View view = m_window->getDefaultView();
                if (m_window_width >= m_initial_aspect_ratio * m_window_height) {
                    view.setViewport(sf::FloatRect(offset_width / m_window_width, 0.0, new_width / m_window_width, 1.0));
                } else {
                    view.setViewport(sf::FloatRect(0.0, offset_height / m_window_height, 1.0, new_height / m_window_height));
                }
                
                m_window->setView(view);
            }
            
        }

        if (m_event.type == sf::Event::LostFocus) { }
        if (m_event.type == sf::Event::GainedFocus) { }
    }
}

bool Engine::Window::is_open() {
    return m_window->isOpen();
}

void Engine::Window::set_fullscreen(bool fullscreen) {
    // If not already fullscreen, and fullscreen was requested
    if (!m_fullscreen && fullscreen) {
        m_window->close();
        m_window_width = sf::VideoMode::getDesktopMode().width;
        m_window_height = sf::VideoMode::getDesktopMode().height;
        m_window->create(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Fullscreen);
        
        m_fullscreen = fullscreen;
    // If it's already fullscreen, but requested otherwise
    } else if (m_fullscreen && !fullscreen) {
        m_window->close();
        m_window_width = sf::VideoMode::getDesktopMode().height * m_initial_aspect_ratio;
        m_window_height = sf::VideoMode::getDesktopMode().height;
        m_window->create(sf::VideoMode(m_window_width, m_window_height), m_window_title, sf::Style::Default);
        
        m_fullscreen = fullscreen;
    } else {
        // pass
    }
}

void Engine::Window::set_fps(float fps) {
    if (fps > 1.0 && fps <= 200.0) {
        m_fps = fps;
    } else {
        std::cerr << "Requested fps is either too low or too high. It should be between (1.0 and 200.0]" << std::endl;
    }
}

float Engine::Window::get_fps() const {
    return m_fps;
}
