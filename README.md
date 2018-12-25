# Platformer C++

## Install:

### Ubuntu-based Linux
You need `meson`, `ninja-build`, `sfml` to get started. Run the following command to install the necessary dependencies:

`sudo apt install build-essential clang llvm lldb git meson libsfml-dev libcsfml-dev`

### Other Linux-based OS
Install `meson`, `sfml`, `csfml`, `clang`, `ninja-build` packages from your package manager. You can also get meson from pip3 by running `pip3 install meson` command.


## Compile & Run
Use the `manager.sh` file to compile the project automatically and run the final executable.

`./manager.sh compile` compiles the whole project, and puts it in the newly created `build` directory

`./manager.sh run` runs the final executable file.

`./manager.sh clean` cleans the compiled files.

Licensed under MIT. Created by Mohammadreza Hajianpour
