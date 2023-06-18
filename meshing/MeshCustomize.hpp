#ifndef ___MESHCUSTOMIZE___
#define ___MESHCUSTOMIZE___

#include "Mesh.hpp"

void Mesh::addVertices(const vector<vec3> &newVertices, bool allowDouble) {
    if (allowDouble) {
        for (vec3 ver : newVertices) {
            _vertices.push_back(ver);
        }
    } else {
        for (vec3 ver : newVertices) {
            if (find(_vertices.begin(), _vertices.end(), ver) == _vertices.end()) {
                _vertices.push_back(ver);
            }
        }
    }
}

vector<GLuint> Mesh::addVerticesWithIndex(const vector<vec3> &newVertices, bool allowDouble) {
    vector<GLuint> coord;
    GLuint posBack = _vertices.size();
    if (allowDouble) {
        for (vec3 ver : newVertices) {
            _vertices.push_back(ver);
            coord.push_back(++posBack);
        }
    } else {
        for (vec3 ver : newVertices) {
            vector<vec3>::iterator pos = find(_vertices.begin(), _vertices.end(), ver);
            if (pos == _vertices.end()) {
                _vertices.push_back(ver);
                coord.push_back(++posBack);
            } else {
                coord.push_back(std::distance(_vertices.begin(), pos));
            }
        }
    }
    return coord;
}

void Mesh::addIndices(const vector<GLuint> &newIndices) {
    for (GLuint ind : newIndices) {
        _indices.push_back(ind);
    }
}

void Mesh::addTriangle(const vector<vec3> &newVertices, bool allowDouble) {
    vector<GLuint> indices = addVerticesWithIndex(newVertices, allowDouble);
    addIndices(indices);
}

#endif /* ___MESHCUSTOMIZE___ */
