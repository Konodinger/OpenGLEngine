#ifndef ___KEYBOARDINPUTCAMERA___
#define ___KEYBOARDINPUTCAMERA___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

void keyCallbackWindow(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (action == GLFW_PRESS) {
    if(key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) {
      // closes the application if the escape or 'Q' key is pressed
      glfwSetWindowShouldClose(window, true);
    }
  }
}

#endif /* ___KEYBOARDINPUTCAMERA___ */
