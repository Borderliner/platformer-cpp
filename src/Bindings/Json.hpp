#pragma once

#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

namespace Bindings {

using json = nlohmann::json;

class Json {
 private:
    std::ifstream m_ifstream;
    std::string m_file_path;
    json m_json;

    Json() { }
 public:
    
    Json(const std::string& file_path);
    json& get_json();
    ~Json() { }
};

}  // namespace Bindings
