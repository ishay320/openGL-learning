#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
// put GLFW after glad
#include <GLFW/glfw3.h>

#include <sstream>

class Shader
{
   private:
    int _ID;

   public:
    Shader(const std::string &vertex_shader_path, const std::string &fragment_shader_path);

    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif  // SHADER_H