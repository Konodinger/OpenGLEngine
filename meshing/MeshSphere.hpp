#ifndef ___MESHSPHERE___
#define ___MESHSPHERE___

#include "Mesh.hpp"
#include "utilsMaths.hpp"

void Mesh::becomesSphere(const vec3 &center, const GLfloat &radius, const GLuint detail) {
    float angleStep = M_PI/float(detail);
    _vertices.clear();
    _indices.clear();

    vector<vec3> sphereVertices;

    //Careful, this code crashs with a detail of 8 or 9 (only) on my computer.
    _vertices.push_back(center + vec3(0.f, 0.f, radius));
    for (int phi = 0; phi < detail; ++phi) {
        _vertices.push_back(center + convertSpherical(radius, angleStep, (2*angleStep*phi)));
        _indices.push_back(0);
        _indices.push_back(phi + 1);
        _indices.push_back((phi + 1)%detail + 1);
    }

    for (int theta = 1; theta < detail - 1; ++theta) {
        for (int phi = 0; phi < detail; ++phi) {
            _vertices.push_back(center + convertSpherical(radius, angleStep*(theta+1), 2*angleStep*phi));
            _indices.push_back(1 + (theta - 1)*detail + (phi+1)%detail);
            _indices.push_back(1 + (theta - 1)*detail + phi);
            _indices.push_back(1 + theta*detail + phi);
            _indices.push_back(1 + (theta - 1)*detail + (phi+1)%detail);
            _indices.push_back(1 + theta*detail + phi);
            _indices.push_back(1 + theta*detail + (phi+1)%detail);
        }
    }
    _vertices.push_back(center + vec3(0.f, 0.f, -radius));
    for (int phi = 0; phi < detail; ++phi) {
        _indices.push_back((detail-1)*(detail-1) + (phi+1)%detail);
        _indices.push_back((detail-1)*(detail-1) + phi);
        _indices.push_back(1 + (detail-1)*detail);
    }

    //Old code that generates exactly the same triangles, but a bit slower. It is crash-proof, though.
    /*for (float theta = 0.; theta < detail; theta +=1.) {
        for (float phi = 0.; phi < detail; phi += 1.) {
            if (theta > 0.) {
                sphereVertices.push_back(center + convertSpherical(radius, (theta*angleStep), (phi*2*angleStep)));
                sphereVertices.push_back(center + convertSpherical(radius, ((theta+1)*angleStep), (phi*2*angleStep)));
                sphereVertices.push_back(center + convertSpherical(radius, (theta*angleStep), ((phi+1)*2*angleStep)));
                addTriangle(sphereVertices, false);
                sphereVertices.clear();
            }
            if (theta + 1 < detail) {
                sphereVertices.push_back(center + convertSpherical(radius, ((theta+1)*angleStep), (phi*2*angleStep)));
                sphereVertices.push_back(center + convertSpherical(radius, ((theta+1)*angleStep), ((phi+1)*2*angleStep)));
                sphereVertices.push_back(center + convertSpherical(radius, (theta*angleStep), ((phi+1)*2*angleStep)));
                addTriangle(sphereVertices, false);
                sphereVertices.clear();
            }
        }
    }*/

}


#endif /* ___MESHSPHERE___ */
