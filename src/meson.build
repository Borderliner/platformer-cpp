subdir('Traits')
subdir('Containers')
subdir('Engine')

runtime_sources = [
    'Runtime/main.cpp'
]

runtime_headers = [

]

runtime_deps = [
    containers_dep,
    engine_dep,
]

runtime_includes = [
    include_directories('.')
]

executable('platformer.runtime', runtime_sources + runtime_headers, dependencies: runtime_deps, include_directories: runtime_includes)
