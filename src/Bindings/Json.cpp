#include "Json.hpp"

using namespace Bindings;

Json::Json(const std::string& file_path) {
    m_file_path = file_path;
    if (file_path.empty() == false) {
        m_ifstream = std::ifstream(file_path);
        if (!m_ifstream.fail()) {
            m_ifstream >> m_json;
        } else {
            std::cerr << "Json could not find file \"" << file_path << "\"" << std::endl;
            return;
        }
        
    } else {
        std::cerr << "Empty json file path. Please specify a config.json file." << std::endl;
        return;
    }
}

json& Json::get_json() {
    return m_json;
}
