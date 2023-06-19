#ifndef ___WORLDWINDOW___
#define ___WORLDWINDOW___

class WWindow;
#include "utils.hpp"

#include "KeyboardInputWindow.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

class WWindow {
    public:
        explicit WWindow() {};
        inline Renderer *getRenderer() { return _renderer; }
        inline GLFWwindow *getWindow() { return _window; }

        int init();
        int loop();
        int close();

        void switchWireframeMode();



    static WWindow WINDOW;

    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        Renderer *_renderer = nullptr;
        GLFWwindow *_window = nullptr;
        bool wireFrameMode = false;
};

#endif /* ___WORLDWINDOW___ */
