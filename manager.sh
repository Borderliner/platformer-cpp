#!/bin/bash

cpu_num=$(grep -c ^processor /proc/cpuinfo)
green=`tput setaf 2`
cyan=`tput setaf 6`
yellow=`tput setaf 3`
red=`tput setaf 1`
reset=`tput sgr0`
build_type="Release"

print_help() {
    echo ""
    echo "${yellow}Available commands:${reset}"
    echo "${cyan}clean${reset}: Cleans the build files"
    echo "${cyan}run${reset}: Run the game"
    echo "${cyan}compile [debug|release]${reset}: Compiles the project. (On ${green}release${reset} mode by default.)"

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
    echo "${yellow}Running the game...${reset}"
    ./build/src/platformer-cpp

elif [[ $1 = "compile" ]]; then
    echo "${yellow}Meson is generating ninja files...${reset}"
    meson 'build' && cd 'build'
    echo "${yellow}Number of CPU cores: ${reset}${green}${cpu_num}${reset}"
    ninja -j${cpu_num}
fi
