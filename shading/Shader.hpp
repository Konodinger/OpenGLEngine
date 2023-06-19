#ifndef ___SHADER___
#define ___SHADER___

class Shader;
#include "utils.hpp"

#include <fstream>
#include <sstream>

using namespace std;
using namespace glm;

class Shader {
    public:
        explicit Shader(const char *vertexShaderSource, const char *fragmentShaderSource);

        void use() const;
        void setBool(const char *name, bool value) const;  
        void setInt(const char *name, int value) const;   
        void setFloat(const char *name, float value) const;
        void setVec2(const char *name, vec2 value) const;
        void setVec3(const char *name, vec3 value) const;
        void setVec4(const char *name, vec4 value) const;
        void setMat2(const char *name, mat2 value) const;
        void setMat3(const char *name, mat3 value) const;
        void setMat4(const char *name, mat4 value) const;

        GLuint ID;

    private:
        int success;
        char infoLog[1024];
};

#endif /* ___SHADER___ */
