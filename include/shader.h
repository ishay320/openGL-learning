#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
// put GLFW after glad
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief read all the file to one string
 *
 * @param path to the file
 * @return std::string
 */
static std::string readFile(const std::string &path)
{
    std::ifstream file;
    file.open(path, std::ios_base::in);

    if (!file.is_open())
    {
        std::cerr << "ERROR: could not open file: \'" + path + '\'' << std::endl;
    }

    std::stringstream stream;
    stream << file.rdbuf();

    file.close();
    return stream.str();
}

class Shader
{
   private:
    int _ID;

   public:
    Shader(const std::string &vertex_shader_path, const std::string &fragment_shader_path)
    {
        const std::string vertex_code_s   = readFile(vertex_shader_path);
        const std::string fragment_code_s = readFile(fragment_shader_path);
        const char *vertex_code           = vertex_code_s.c_str();
        const char *fragment_code         = fragment_code_s.c_str();

        unsigned int vertex, fragment;
        int success;
        char infoLog[512];

        // vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertex_code, NULL);
        glCompileShader(vertex);
        // print compile errors if any
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cerr << "ERROR: vertex shader compilation failed. file: \'" + vertex_shader_path + "\'\n" << infoLog << std::endl;
        };

        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragment_code, NULL);
        glCompileShader(fragment);
        // print compile errors if any
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cerr << "ERROR: fragment shader compilation failed. file: \'" + fragment_shader_path + "\'\n" << infoLog << std::endl;
        };

        // program
        _ID = glCreateProgram();
        glAttachShader(_ID, vertex);
        glAttachShader(_ID, fragment);
        glLinkProgram(_ID);
        // print linking errors if any
        glGetProgramiv(_ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(_ID, 512, NULL, infoLog);
            std::cout << "ERROR: shader program linking failed\n" << infoLog << std::endl;
        }

        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void use() { glUseProgram(_ID); }

    void setBool(const std::string &name, bool value) const { glUniform1i(glGetUniformLocation(_ID, name.c_str()), (int)value); }
    void setInt(const std::string &name, int value) const { glUniform1i(glGetUniformLocation(_ID, name.c_str()), value); }
    void setFloat(const std::string &name, float value) const { glUniform1f(glGetUniformLocation(_ID, name.c_str()), value); }
};

#endif  // SHADER_H