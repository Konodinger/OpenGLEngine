#include "Square.hpp"

using namespace glm;

Square::Square(const vec2 &pointA, const vec2 &pointB, const vec4 &color) :
            _pointA(pointA), _pointB(pointB), _color(color) {

                
                _vertices.push_back(vec3(pointA, 0.f));
                _vertices.push_back(vec3(pointA.x, pointB.y, 0.f));
                _vertices.push_back(vec3(pointB, 0.f));
                _vertices.push_back(vec3(pointB.x, pointA.y, 0.f));
                

                

                glGenVertexArrays(1, &_VAO);
                glBindVertexArray(_VAO);

                glGenBuffers(1, &_VBO);
                glBindBuffer(GL_ARRAY_BUFFER, _VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*12, _vertices.data(), GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);

                glGenBuffers(1, &_EBO);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_STATIC_DRAW);

                glBindVertexArray(0);
            };

void Square::render(const Shader &shaderProgram) {

    shaderProgram.use();
    shaderProgram.setVec4("meshColor", _color);

    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    
}