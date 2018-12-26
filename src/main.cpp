#include <cstdlib>
#include <memory>
#include <iostream>

#include "Graphics/Window.hpp"
#include "Graphics/Scene.hpp"

int main(int argc, char* argv[]) {
    
    auto window = std::make_shared<GFX::Window>(1024, 768, "Platformer-C++");
    auto scene = std::make_shared<GFX::Scene>(window);

    sf::RectangleShape rect{sf::Vector2f(128.0f, 128.0f)};
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(320.0f, 240.0f);
    scene->add_model(scene->make_model("my-rectangle", rect));
    // Or
    // scene->add_model(Containers::Model("my-rectangle", rect));

    while (window->is_open()) {
        window->poll_events();

        scene->render();
    }

    std::exit(EXIT_SUCCESS);
}
