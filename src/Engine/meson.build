engine_sources = [
    'Window.cpp',
    'Scene.cpp'
]

engine_headers = [
    'Window.hpp',
    'Scene.hpp'
]

engine_deps = [
    sfml_dep,
    containers_dep
]

engine_includes = [
    traits_inc,
    containers_inc
]

engine_lib = static_library('platformer.engine', engine_sources + engine_headers, dependencies: engine_deps, include_directories: engine_includes)
engine_dep = declare_dependency(link_with: engine_lib, sources: engine_sources + engine_headers, include_directories: engine_includes)
