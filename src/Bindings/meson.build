lua_inc = include_directories('.')

lua_sources = [
    'Lua.cpp'
]

lua_headers = [
    'Lua.hpp'
]

lua_deps = [
    lua_deps
]

lua_includes = [
    
]

lua_lib = static_library('platformer.lua', lua_sources + lua_headers, dependencies: lua_deps, include_directories: lua_includes)
lua_dep = declare_dependency(link_with: lua_lib, sources: lua_sources + lua_headers, include_directories: lua_includes)
