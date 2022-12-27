#!/usr/bin/env bash
# ----------------------------------------------------------------
# Script for installing and compiling all the necessary packages for the project
# ----------------------------------------------------------------

COMPILE_GLFW=false

if [ ${COMPILE_GLFW} ]; then
    # GLFW compilation
    ## for x11
    sudo apt install xorg-dev
    ## for wayland
    sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules
    wget https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.zip
    unzip glfw-3.3.8.zip
    # TODO: compile
else
    # GLFW apt installation
    sudo apt-get install libglfw3
    sudo apt-get install libglfw3-dev
fi

# GLAD is already in the repo so moving on
