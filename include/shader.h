#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
   private:
   public:
    int _ID;
    Shader() = default;
    Shader(const std::string &vertex_shader_path, const std::string &fragment_shader_path);

    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif  // SHADER_H