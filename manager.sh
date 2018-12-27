#!/bin/bash

cpu_num=$(grep -c ^processor /proc/cpuinfo)
green=`tput setaf 2`
cyan=`tput setaf 6`
yellow=`tput setaf 3`
red=`tput setaf 1`
reset=`tput sgr0`
compiler="clang"
build_type="release"

print_help() {
    echo ""
    echo "${yellow}Available commands:${reset}"
    echo "${cyan}clean${reset}: Cleans the build files"
    echo "${cyan}run [clang-release, ...]${reset}: Run the project. (On ${green}clang-release${reset} mode by default.)"
    echo "${cyan}compile [clang|gcc] [debug|release]${reset}: Compiles the project. (On ${green}clang-release${reset} mode by default.)"
    echo "${cyan}doc${reset}: Creates documentation of the code"

    exit 0
}


if [[ $1 = "" ]] || [[ $1 = "help" ]] || [[ $1 = "?" ]]; then
    echo ""
    echo "${green}-----// Development Console //-----${reset}"
    print_help

elif [[ $1 = "clean" ]]; then
    rm -rf 'build'
    echo "${green}Successfully cleaned the build folder.${reset}"

elif [[ $1 = "run" ]]; then
    export DISPLAY=:0
    echo "${yellow}Running the game...${reset}"

    run_type=$2
    if [[ -z $run_type ]]; then
        run_type="clang-release"
    fi
    ./build/${run_type}/meson-out/platformer.runtime

elif [[ $1 = "compile" ]]; then
    if [[ $2 = "gcc" ]] || [[ $3 = "gcc" ]]; then
        compiler="gcc"
    fi

    if [[ $2 = "clang" ]] || [[ $3 = "clang" ]]; then
        compiler="clang"
    fi

    if [[ $2 = "debug" ]] || [[ $3 = "debug" ]]; then
        build_type="debug"
    fi

    if [[ $2 = "release" ]] || [[ $3 = "release" ]]; then
        build_type="release"
    fi

    echo "${yellow}Meson is generating ninja files...${reset}"

    if [[ $compiler = "clang" ]]; then
        CC=clang CXX=clang++ meson "build/${compiler}-${build_type}" --buildtype ${build_type} --layout flat
    else
        CC=gcc CXX=g++ meson "build/${compiler}-${build_type}" --buildtype ${build_type} --layout flat
    fi
    cd "build/${compiler}-${build_type}"
    echo "${yellow}Number of CPU cores: ${reset}${green}${cpu_num}${reset}"
    ninja -j${cpu_num}
    cd ../..

elif [[ $1 = "doc" ]] || [[ $1 = "docs" ]]; then
    echo "${yellow}Running Doxygen...${reset}"
    rm -rf build/doc 2> /dev/null
    doxygen Doxyfile
    echo "${green}Successfully created the documentations${reset}"
    xdg-open build/doc/html/index.html
fi
