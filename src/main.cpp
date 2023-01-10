#include <glad/glad.h>
// put GLFW after glad
#include <GLFW/glfw3.h>
#include <math.h>

#include <iostream>

#include "mesh.h"
#include "shader.h"
#include "texture.h"

const char *g_vertex_shader_path   = "./shaders/shader.vs";
const char *g_fragment_shader_path = "./shaders/shader.fs";

const char *g_image_path = "maptest.jpg";

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

void initOpenGL()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *initWindow(const char *window_name, int width, int height, GLFWframebuffersizefun window_resize_callback)
{
    GLFWwindow *window = glfwCreateWindow(width, height, window_name, NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "ERROR: Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, window_resize_callback);
    return window;
}

int main()
{
    initOpenGL();
    GLFWwindow *window = initWindow("test name", SCR_WIDTH, SCR_HEIGHT, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "ERROR: Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader shader{g_vertex_shader_path, g_fragment_shader_path};

    float vertices[] = {
        // positions        // colors         // texture coords
        0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // top right
        -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,  // top left
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom left
        0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    };
    const uint8_t vertex_block_size = 8;

    unsigned int indices[] = {
        0, 1, 2,  // first triangle
        0, 2, 3,  // second triangle
    };

    Mesh mesh{vertices, sizeof(vertices), vertex_block_size, indices, sizeof(indices)};

    Texture texture{g_image_path};

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        // background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // create transformations
        shader.resetTransform();
        float x_pos = sin(glfwGetTime());
        float y_pos = cos(glfwGetTime());
        shader.translate(glm::vec3(x_pos, y_pos, 0.0f));
        shader.rotate((float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        shader.scale(glm::vec3(x_pos, y_pos, 1.0f));

        // foreground
        shader.use();
        texture.bind();
        mesh.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    mesh.deallocate();

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height);
}