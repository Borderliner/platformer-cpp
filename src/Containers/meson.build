containers_inc = include_directories('.')

containers_sources = [
    'Model.cpp'
]

containers_headers = [
    'Model.hpp'
]

containers_deps = [
    sfml_dep
]

containers_includes = [
    
]

containers_lib = static_library('platformer.containers', containers_sources + containers_headers, dependencies: containers_deps, include_directories: containers_includes)
containers_dep = declare_dependency(link_with: containers_lib, sources: containers_sources + containers_headers, include_directories: containers_includes)
