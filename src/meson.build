subdir('Traits')
subdir('Containers')
subdir('Graphics')

runtime_sources = [
    'main.cpp'
]

runtime_headers = [

]

runtime_deps = [
    containers_dep,
    gfx_dep,
]

runtime_includes = [
    include_directories('.')
]

executable('platformer.runtime', runtime_sources + runtime_headers, dependencies: runtime_deps, include_directories: runtime_includes)
