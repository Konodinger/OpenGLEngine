#include "KeyboardInputWindow.hpp"

void keyCallbackWindow(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (action == GLFW_PRESS) {
    if(key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) {
      // closes the application if the escape or 'Q' key is pressed
      glfwSetWindowShouldClose(window, true);
    } else if(key == GLFW_KEY_F1) {
        WWindow::WINDOW.switchWireframeMode();
    }
  }
}