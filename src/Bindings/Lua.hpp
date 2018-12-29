#pragma once

#include "NoCopy.hpp"
#include "NoMove.hpp"

#include "API.hpp"

namespace Bindings {

typedef lua_State* StatePtr;

struct State {
    StatePtr pointer;
    std::string file_name;
    int load_error;
    int runtime_error;
};

class Lua : public Traits::NoCopy, public Traits::NoMove {
 private:
    std::vector<State> m_states;
    std::shared_ptr<Engine::Scene> m_scene;
    static std::shared_ptr<Engine::Scene> s_scene;
    Lua() { }
 public:
    
    Lua(std::shared_ptr<Engine::Scene> scene);
    ~Lua();
    bool init();
    void load_script(const std::string& file_name);
    void register_cpp_api(lua_State* state);
    bool execute();
};
}  // namespace Bindings
