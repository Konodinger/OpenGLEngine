#ifndef ___MESHSPHERE___
#define ___MESHSPHERE___

#include "Mesh.hpp"
#include "utilsMaths.hpp"

void Mesh::becomesSphere(const vec3 &center, const GLfloat &radius, const GLuint detail) {
    _vertices.clear();
    _indices.clear();

    vector<vec3> sphereVertices;

    for (float theta = 0.; theta < detail; theta +=1.) {
        for (float phi = 0.; phi < detail; phi += 1.) {
            if (theta > 0.) {
                sphereVertices.push_back(center + convertSpherical(radius, (theta/detail*M_PI), (phi/detail*2*M_PI)));
                sphereVertices.push_back(center + convertSpherical(radius, ((theta+1)/detail*M_PI), (phi/detail*2*M_PI)));
                sphereVertices.push_back(center + convertSpherical(radius, (theta/detail*M_PI), ((phi+1)/detail*2*M_PI)));
                addTriangle(sphereVertices, false);
                sphereVertices.clear();
            }
            if (theta + 1 < detail) {
                sphereVertices.push_back(center + convertSpherical(radius, ((theta+1)/detail*M_PI), (phi/detail*2*M_PI)));
                sphereVertices.push_back(center + convertSpherical(radius, ((theta+1)/detail*M_PI), ((phi+1)/detail*2*M_PI)));
                sphereVertices.push_back(center + convertSpherical(radius, (theta/detail*M_PI), ((phi+1)/detail*2*M_PI)));
                addTriangle(sphereVertices, false);
                sphereVertices.clear();
            }
        }
    }

}


#endif /* ___MESHSPHERE___ */
