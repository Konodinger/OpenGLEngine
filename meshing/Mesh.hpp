#ifndef ___MESH___
#define ___MESH___

class Mesh;
#include "utils.hpp"

#include <vector>
#include <algorithm>
#include "Shader.hpp"
#include "Transformation.hpp"
#include "WorldWindow.hpp"

using namespace glm;
using namespace std;

class Mesh {
    public:
        explicit Mesh(Transformation &transformation) : _transformation(transformation) {};
        explicit Mesh(const vec3 &translation = vec3(0.f), const quat &rotation = quat(), const vec3 &scale = vec3(1.f)) : _transformation(translation, rotation, scale) {};
        virtual ~Mesh();
        void clear();
        inline Transformation getTransformation() const { return _transformation; }
        inline void setTransformation(const Transformation &transformation) { _transformation = transformation; }

        void addVertices(const vector<vec3> &newVertices, bool allowDouble = true); //Add new vertices.
        vector<GLuint> addVerticesWithIndex(const vector<vec3> &newVertices, bool allowDouble = true); //Add new vertices, and return their indices.
        void addIndices(const vector<GLuint> &newIndices); //Add new indices.
        void addTriangle(const vector<vec3> &newVertices, bool allowDouble = true);

        void setColor(const vec4 &newColor) {_color = newColor;}

        void init();
        void render(const Shader &shaderProgram);

        void becomesCube(const vec3 &pointA = vec3(-.5f, -.5f, -.5f), const vec3 &pointB = vec3(.5f, .5f, .5f));
        void becomesSphere(const vec3 &center = vec3(0.f), const GLfloat &radius = 0.5f, const GLuint detail = 16);

    private:
        vector<vec3> _vertices;
        vector<GLuint> _indices;
        GLuint _VBO, _EBO, _VAO;
        vec4 _color = vec4(1.f);
        Transformation _transformation;

        const GLuint _posVBO = 0;
};

#endif /* ___MESH___ */
