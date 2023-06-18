#ifndef ___RENDERER___
#define ___RENDERER___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <list>
#include "Camera.hpp"
#include "Mesh.hpp"

inline int getOpenGLErrorNoAssert(const char * where) {
  int error = glGetError();
  if(error != GL_NO_ERROR) {
    std::cout << "GL Error detected : " << where << " : " << error << std::endl;
  }
  return error;
}

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

        void initCamera(const vec3 &initialPos = vec3(0.0f, 0.0f, 5.0f));

        void init();

        void render();

    private:
        Camera _cam;
        Shader _shader;
        list<Mesh *> _meshSet;
        GLFWwindow *_window;
};

#endif /* ___RENDERER___ */
