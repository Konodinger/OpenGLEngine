#ifndef ___TRANSFORMATION___
#define ___TRANSFORMATION___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

using namespace glm;

class Transformation {
    public:
        explicit Transformation(const vec3 &translation = vec3(0.f), const quat &rotation = quat(), const vec3 &scale = vec3(1.f)) :
            _translation(translation), _rotation(rotation), _scale(scale) { normalizeRot();};
        inline vec3 getTranslation() const {return _translation; }
        inline void setTranslation(const vec3 translation) { _translation = translation; }
        inline quat getRotation() const { return _rotation; }
        inline void setRotation(const quat rotation) { _rotation = rotation; normalizeRot(); }
        inline vec3 getScale() const {return _scale; }
        inline void setScale(const vec3 scale) { _scale = scale; } 
    
        mat4 modelMatrix() {
            mat4 transMat = translate(mat4(1.0), _translation);
            mat4 rotMat = mat4_cast(_rotation);
            mat4 scaleMat = scale(mat4(1.0), _scale);
            return transMat * rotMat * scaleMat;
        }
    private:
        void normalizeRot() {
            if (length(_rotation) == 0.f) {
                _rotation = quat();
            } else {
                normalize(_rotation);
            }
        }
        vec3 _scale, _translation;
        quat _rotation;
};

#endif /* ___TRANSFORMATION___ */
