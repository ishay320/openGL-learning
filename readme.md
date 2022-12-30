# openGL learning repository

## intro

openGL is library for graphics, so we will need widow library to put the openGL _"context"_ inside, i choose GLFW that is tailored for openGL, but openGL is dynamically linked at runtime, so i took GLAD to make it simpler to work with.

## libraries

- openGL
- [GLFW](#GLFW)
- [GLAD](#GLAD)
- [stbImage](stbImage)

## [GLFW](https://github.com/glfw/glfw)

GLFW is windowing library, it means that it open new window that can hold openGL context

### GLFW compile options

`lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl`

## [GLAD](https://github.com/Dav1dde/glad)

GLAD is like a compatibility layer: it takes all the openGL dynamic linked functions and generate h file for them.

### download

1. go to [this](https://glad.dav1d.de/#profile=core&language=c&specification=gl&loader=on&api=gl%3D3.3) website, make sure c++, openGL 3.3+, core and generate loader are checked.
1. download the zip file.
1. add the content (src, include) to the project.

## [stbImage](https://raw.githubusercontent.com/nothings/stb/master/stb_image.h)

library for loading images - implemented in single h file.

## links

[openGL wiki](https://www.khronos.org/opengl/wiki/)

[openGL tutorial](https://learnopengl.com/)
