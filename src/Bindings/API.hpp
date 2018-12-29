#pragma once

#include <lua5.3/lua.hpp>

#include <memory>
#include <vector>
#include <iostream>

#include "Scene.hpp"
#include <SFML/Graphics.hpp>

static std::shared_ptr<Engine::Scene> api_scene = std::make_shared<Engine::Scene>();

// C++ API
static lua_CFunction api_test() {
    std::cout << "C++ Fucntion Call" << std::endl;
}
