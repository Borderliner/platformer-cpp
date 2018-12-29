bindings_inc = include_directories('.')

bindings_sources = [
    'Lua.cpp',
    'Json.cpp'
]

bindings_headers = [
    'API.hpp',
    'Lua.hpp',
    'Json.hpp'
]

bindings_deps = [
    sfml_dep,
    lua_deps,
    engine_dep
]

bindings_includes = [
    traits_inc,
    engine_inc
]

bindings_lib = static_library('platformer.bindings', bindings_sources + bindings_headers, dependencies: bindings_deps, include_directories: bindings_includes)
bindings_dep = declare_dependency(link_with: bindings_lib, sources: bindings_sources + bindings_headers, include_directories: bindings_includes)
