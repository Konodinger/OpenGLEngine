#include "Mesh.hpp"
#include "MeshCustomize.hpp"
#include "MeshCube.hpp"
#include <iostream>

Mesh::~Mesh() {
    clear();
}

void Mesh::clear() {
    if (_VAO) {
        glDeleteVertexArrays(1, &_VAO);
        _VAO = 0;
    }
    if (_VBO) {
        glDeleteBuffers(1, &_VBO);
        _VBO = 0;
    }if (_EBO) {
        glDeleteBuffers(1, &_EBO);
        _EBO = 0;
    }
}

void Mesh::init() {
    

    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);

    glGenBuffers(1, &_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*3*_vertices.size(), _vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*3*_indices.size(), _indices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);
};

void Mesh::render(const Shader &shaderProgram) {

    shaderProgram.use();
    shaderProgram.setVec4("meshColor", _color);

    glBindVertexArray(_VAO);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    
}