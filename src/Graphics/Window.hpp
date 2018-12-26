#pragma once

#include <memory>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "NoCopy.hpp"
#include "NoMove.hpp"

namespace GFX {
class Window : public Traits::NoCopy, public Traits::NoMove {
 public:
    Window();
    Window(unsigned int window_width, unsigned int window_height, const std::string& window_title);
    ~Window();

    std::shared_ptr<sf::RenderWindow> get_window() const;
    void poll_events();
    bool is_open();

 private:
    std::shared_ptr<sf::RenderWindow> m_window;
    unsigned int m_window_width, m_window_height;
    std::string m_window_title;
    sf::Event m_event;

};
}  // namespace GFX
