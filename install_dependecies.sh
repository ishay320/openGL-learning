#!/usr/bin/env bash
# ----------------------------------------------------------------
# Script for installing and compiling all the necessary packages for the project
# ----------------------------------------------------------------

COMPILE_GLFW=false

if [ ${COMPILE_GLFW} ]; then
    # GLFW compilation
    ## for x11
    sudo apt install -y xorg-dev
    ## for wayland
    sudo apt install -y libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules
    wget https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.zip
    unzip glfw-3.3.8.zip
    # TODO: compile
else
    # GLFW apt installation
    sudo apt-get install libglfw3 -y
    sudo apt-get install libglfw3-dev -y
fi

# GLAD is already in the repo so moving on

# install glm (OpenGL Mathematics)
sudo apt install libglm-dev -y
