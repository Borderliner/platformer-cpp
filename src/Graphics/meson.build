gfx_sources = [
    'Window.cpp',
    'Scene.cpp'
]

gfx_headers = [
    'Window.hpp',
    'Scene.hpp'
]

gfx_deps = [
    sfml_dep,
    containers_dep
]

gfx_includes = [
    traits_inc,
    containers_inc
]

gfx_lib = static_library('platformer.gfx', gfx_sources + gfx_headers, dependencies: gfx_deps, include_directories: gfx_includes)
gfx_dep = declare_dependency(link_with: gfx_lib, sources: gfx_sources + gfx_headers, include_directories: gfx_includes)
