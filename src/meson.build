subdir('Traits')
subdir('Containers')
subdir('Engine')
subdir('Bindings')

runtime_sources = [
    'Runtime/main.cpp'
]

runtime_headers = [

]

runtime_deps = [
    containers_dep,
    engine_dep,
    bindings_dep
]

runtime_includes = [
    include_directories('.')
]

executable('platformer.runtime', runtime_sources + runtime_headers, dependencies: runtime_deps, include_directories: runtime_includes)
