#ifndef ___KEYBOARDINPUT___
#define ___KEYBOARDINPUT___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

bool wireFrameMode = false;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (action == GLFW_PRESS) {
    if(key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) {
      // closes the application if the escape or 'Q' key is pressed
      glfwSetWindowShouldClose(window, true);
    } else if(key == GLFW_KEY_F1) {
      wireFrameMode = !wireFrameMode;
      if (wireFrameMode) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      }
    }
  }
}

#endif /* ___KEYBOARDINPUT___ */
