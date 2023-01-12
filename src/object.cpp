#include "object.h"

Object::Object(const Shader& shader, const Texture& texture, const Mesh& mesh) : _shader(shader), _texture(texture), _mesh(mesh) { resetTransform(); }

void Object::applyTransform() { _shader.setMat4("transform", _transform); }

void Object::resetTransform()
{
    _transform = glm::mat4(1.0f);  // initialize matrix to identity matrix
}

void Object::rotate(const float angle, const glm::vec3& rotation_vector)
{
    _transform = glm::rotate(_transform, angle, rotation_vector);
    applyTransform();
}

void Object::translate(const glm::vec3& translation_vector)
{
    _transform = glm::translate(_transform, translation_vector);
    applyTransform();
}

void Object::scale(const glm::vec3& scale_vector)
{
    _transform = glm::scale(_transform, scale_vector);
    applyTransform();
}

void Object::draw()
{
    _shader.use();
    _texture.bind();
    _mesh.draw();
}
void Object::deallocate() { _mesh.deallocate(); }
