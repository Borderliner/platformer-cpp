#include <cstdlib>
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

#include <sys/types.h>
#include <dirent.h>

#include "Engine/Window.hpp"
#include "Engine/Scene.hpp"

#include "Bindings/Json.hpp"
#include "Bindings/Lua.hpp"

typedef std::vector<std::string> string_vec;

void read_directory(const std::string &path, std::function<void(const std::string&)> cb) {
    if (auto dir = opendir(path.c_str())) {
        while (auto f = readdir(dir)) {
            if (!f->d_name || f->d_name[0] == '.') continue;
            if (f->d_type == DT_DIR) 
                read_directory(path + f->d_name + "/", cb);

            if (f->d_type == DT_REG)
                cb(path + f->d_name);
        }
        closedir(dir);
    }
}

int main(int argc, char* argv[]) {
    
    auto window = std::make_shared<Engine::Window>(1024, 768, "Platformer-C++");
    auto scene = std::make_shared<Engine::Scene>(window);

    // Read Config file
    Bindings::Json json{"config.json"};
    std::vector<std::string> folders = json.get_json()["scripts_folders"];
    std::vector<std::string> all_files;
    for(auto& each_folder : folders) {
        read_directory(each_folder, [&all_files](const std::string& file_name) {
            all_files.push_back(file_name);
        });
    }

    // Run lua scripts
    Bindings::Lua lua_engine{scene};
    
    if (all_files.empty()) {
        std::cerr << "No scripts found. Please configure the script folder in config.json" << std::endl;
        return EXIT_FAILURE;
    }

    for(auto& each_file : all_files) {
        lua_engine.load_script(each_file);
    }

    lua_engine.execute();

    while (window->is_open()) {
        window->poll_events();

        scene->render();
    }

    std::exit(EXIT_SUCCESS);
}
