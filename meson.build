project('platformer-cpp', 'cpp',
    version: '0.0.1',
    license: 'MIT')

cpp_args = [
    '-std=c++1z',
    '-Wall',
    
]

add_global_arguments(cpp_args, language : 'cpp')

if get_option('buildtype') == 'debug'
    add_global_arguments('-g', language : 'cpp')
    add_global_arguments('-O0', language : 'cpp')
    warning('Turning off optimization in debug mode')
elif get_option('buildtype') == 'release'
    add_global_arguments('-O3', language : 'cpp')
    message('Turning on O3 optimization in release mode')
endif

# Aqcuire all libraries and dependencies
sfml_dep = dependency('sfml-all')  # SFML 2.4 library, libsfml-dev
lua_deps = dependency('lua5.3')  # Lua 5.3, liblua5.3-dev
# nlohmann_json, nlohmann-json-dev

subdir('src')
subdir('test')
# subdir('lib')
