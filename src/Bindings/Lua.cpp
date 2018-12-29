#include "Lua.hpp"

using namespace Bindings;

Lua::Lua(std::shared_ptr<Engine::Scene> scene) {
    m_scene = scene;
    api_scene = m_scene;
}

Lua::~Lua() {
    for (auto& state : m_states) {
        lua_close(state.pointer);
    }
}

bool Lua::init() {
    return true;
}

void Lua::load_script(const std::string& file_name) {
    m_states.push_back({luaL_newstate(), file_name, 0, 0});

    // Open all libraries
    luaL_openlibs(m_states.back().pointer);

    register_cpp_api(m_states.back().pointer);

    m_states.back().load_error = luaL_loadfile(m_states.back().pointer, m_states.back().file_name.c_str());
}

void Lua::register_cpp_api(lua_State* state) {
    //register new custom method
    // lua_register(state, "cpp_test", api_test());
}

bool Lua::execute() {
    for (auto& state : m_states) {
        if (!state.load_error) {
            state.runtime_error = lua_pcall(state.pointer, 0, LUA_MULTRET, 0);
        } else {
            std::cerr << "Load Error: Error loading script file \"" << state.file_name << "\"." << std::endl;
        }

        if (state.runtime_error) {
            std::cerr << "----// Runtime Error:" << std::endl;
            std::cerr << lua_tostring(state.pointer, -1);
            lua_pop(state.pointer, 1);
        }

        lua_close(state.pointer);
    }

    return true;
}

