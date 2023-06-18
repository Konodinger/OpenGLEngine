#ifndef ___SQUARE___
#define ___SQUARE___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <vector>
#include "Shader.hpp"

using namespace glm;

class Square {
    public:
        explicit Square(const vec2 &pointA, const vec2 &pointB, const vec4 &color = vec4(1.f, 0.5f, 0.5f, 1.f));
        
        
        void render(const Shader &shaderProgram);

    private:
        std::vector<vec3> _vertices;
        const GLuint _indices[6] = {
                    0, 1, 3,
                    1, 2, 3
                };
        GLuint _VBO, _EBO, _VAO;
        vec2 _pointA, _pointB;
        vec4 _color;

        const GLuint _posVBO = 0;
};

#endif /* ___SQUARE___ */
