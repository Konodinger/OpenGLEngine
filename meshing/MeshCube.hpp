#ifndef ___MESHCUBE___
#define ___MESHCUBE___

#include "Mesh.hpp"

void Mesh::becomesCube(const vec3 &pointA, const vec3 &pointB) {
    _vertices.clear();
    _indices.clear();
    _vertices.push_back(pointA);
    _vertices.push_back(vec3(pointA.x, pointA.y, pointB.z));
    _vertices.push_back(vec3(pointA.x, pointB.y, pointA.z));
    _vertices.push_back(vec3(pointA.x, pointB.y, pointB.z));
    _vertices.push_back(vec3(pointB.x, pointA.y, pointA.z));
    _vertices.push_back(vec3(pointB.x, pointA.y, pointB.z));
    _vertices.push_back(vec3(pointB.x, pointB.y, pointA.z));
    _vertices.push_back(pointB);

    _indices = {
        0, 1, 2,
        2, 1, 3,
        4, 6, 5,
        5, 6, 7,
        0, 4, 1,
        1, 4, 5,
        2, 3, 6,
        6, 3, 7,
        0, 2, 4,
        4, 2, 6,
        1, 5, 3,
        5, 3, 7
    };
}

#endif /* ___MESHCUBE___ */
