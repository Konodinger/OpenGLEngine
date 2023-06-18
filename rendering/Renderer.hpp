#ifndef ___RENDERER___
#define ___RENDERER___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <list>
#include "Camera.hpp"
#include "Mesh.hpp"

class Renderer {
    public:
        explicit Renderer(GLFWwindow *window, Camera &cam, Shader &shader) :
            _window(window), _cam(cam), _shader(shader) {};
        inline Camera &getCamera() {return _cam; }
        inline void setCamera(const Camera cam) { _cam = cam; }
        inline Shader &getShader() {return _shader; }
        inline void setShader(const Shader shader) {_shader = shader; }
        inline Mesh *getMesh(int i) { auto m = _meshSet.begin(); advance(m, i); return *m; }
        inline void setMesh(int i, Mesh * newMesh) { auto m = _meshSet.begin(); advance(m, i); *m = newMesh; }
        inline void addMesh(Mesh * newMesh) { _meshSet.push_back(newMesh); }

        inline void initCamera(const vec3 &initialPos = vec3(0.0f, 0.0f, 5.0f)) {
            int width, height;
            glfwGetWindowSize(_window, &width, &height);
            _cam.setAspectRatio(static_cast<float>(width)/static_cast<float>(height));

            _cam.setPosition(initialPos);
            _cam.setNear(0.1);
            _cam.setFar(80.1);
        }

        void init() {
            initCamera();
            for (auto &mesh : _meshSet) {
                mesh->init();
            }
        }
        void render() {
            _cam.setPosition(vec3(sin(glfwGetTime()), 0.0f, 5.0f));
            _shader.setVec3("camPos", _cam.getPosition());
            _shader.setMat4("viewMat", _cam.computeViewMatrix());
            _shader.setMat4("projMat", _cam.computeProjectionMatrix());
            for (auto &mesh : _meshSet) {
                mesh->render(_shader);
                mesh->setTransformation(Transformation(vec3(0.f, sin(glfwGetTime()), cos(glfwGetTime())), quat(vec3(glfwGetTime(), 0.f, 0.f))));
                _shader.setMat4("modelMat", mesh->getTransformation().modelMatrix());
            }

        }

    private:
        Camera _cam;
        Shader _shader;
        list<Mesh *> _meshSet;
        GLFWwindow *_window;
};

#endif /* ___RENDERER___ */
