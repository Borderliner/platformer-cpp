#pragma once

#include <memory>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "NoCopy.hpp"
#include "NoMove.hpp"

namespace Engine {

/**
 * @brief A light-weight wrapper around sf::RenderWindow, to handle windowing functionality
 * 
 */
class Window : public Traits::NoCopy, public Traits::NoMove {
 public:
    /**
     * @brief Construct a new Window object
     * 
     */
    Window();
    
    /**
     * @brief Construct a new Window object
     * 
     * @param window_width Window width
     * @param window_height Window height
     * @param window_title Window title
     */
    Window(unsigned int window_width, unsigned int window_height, const std::string& window_title, float fps = 60.0);

    /**
     * @brief Destroy the Window object
     * 
     */
    ~Window();

    /**
     * @brief Get the sf::RenderWindow object
     * 
     * @return std::shared_ptr<sf::RenderWindow> 
     */
    std::shared_ptr<sf::RenderWindow> get_window() const;

    /**
     * @brief Polls window events and responds properly
     * 
     */
    void poll_events();

    /**
     * @brief Returns whether the window is open and showing
     * 
     * @return true 
     * @return false 
     */
    bool is_open();

    void set_fullscreen(bool fullscreen);
    void set_fps(float fps);
    float get_fps() const;

 private:
    /**
     * @brief Window object
     * 
     */
    std::shared_ptr<sf::RenderWindow> m_window;
    unsigned int m_window_width, m_window_height;
    std::string m_window_title;
    bool m_fullscreen;
    float m_fps;

    /**
     * @brief Saves events in this variable
     * 
     */
    sf::Event m_event;

};
}  // namespace Engine
