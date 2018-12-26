project('platformer-cpp', 'cpp',
    version: '0.0.1',
    license: 'MIT')

cpp_args = [
    '-std=c++17',
    '-Wall'
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

sfml_dep = dependency('sfml-all')

subdir('src')
subdir('test')
# subdir('lib')
