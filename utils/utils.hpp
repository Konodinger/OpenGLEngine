#ifndef ___UTILS___
#define ___UTILS___

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

inline int getOpenGLErrorNoAssert(const char * where) {
  int error = glGetError();
  if(error != GL_NO_ERROR) {
    std::cout << "GL Error detected : " << where << " : " << error << std::endl;
  }
  return error;
}

#endif /* ___UTILS___ */
