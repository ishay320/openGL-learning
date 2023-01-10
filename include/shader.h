#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

class Shader
{
   public:
    Shader() = default;
    Shader(const std::string &vertex_shader_path, const std::string &fragment_shader_path);

    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    
    void setMat4(const std::string &name, const glm::mat4 &value) const;

    /**
     * @brief reset the current transformation
     *
     */
    void resetTransform();

    /**
     * @brief rotate the vertices by the specify angle in x, y, z axis
     * WARNING: additive transform - the transformation have memory (resetTransform)
     *
     * @param angle
     * @param rotation_vector
     */
    void rotate(float angle, const glm::vec3 &rotation_vector);

    /**
     * @brief translate the vertices in x, y, z axis
     * WARNING: additive transform - the transformation have memory (resetTransform)
     *
     * @param translation_vector
     */
    void translate(const glm::vec3 &translation_vector);

   private:
    /**
     * @brief apply the transformation to the shader
     *
     */
    void applyTransform();

    int _ID;
    glm::mat4 _transform;
};

#endif  // SHADER_H