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
    # TODO: download GLFW git
    # TODO: compile
else
    # GLFW apt installation
    sudo apt-get install libglfw3
    sudo apt-get install libglfw3-dev
fi
