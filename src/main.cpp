#include <cstdlib>
#include <memory>
#include <iostream>

#include "Graphics/Window.hpp"
#include "Graphics/Scene.hpp"

int main(int argc, char* argv[]) {
    
    auto window = std::make_shared<GFX::Window>(1024, 768, "Platformer-C++");
    auto scene = std::make_shared<GFX::Scene>(window);

    sf::Texture mushroom_tex;
    mushroom_tex.loadFromFile("data/assets/sprites/mushroom.png");
    sf::Sprite mushroom_sprite;
    mushroom_sprite.setTexture(mushroom_tex);

    scene->add_model(scene->make_model("mushroom", mushroom_sprite));

    while (window->is_open()) {
        window->poll_events();

        scene->render();
    }

    std::exit(EXIT_SUCCESS);
}
