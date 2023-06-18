#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

#include "KeyboardInput.hpp"
#include "Shader.hpp"
#include "Square.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

Renderer *renderer;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    renderer->getCamera().setAspectRatio(static_cast<float>(width)/static_cast<float>(height));
};

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Engine OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl"); 

    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    //Geometry part

    Mesh cube = Mesh();
    cube.setColor(vec4(1.f, 0.5f, 0.5f, 1.f));
    cube.becomesCube();
    //Square squareMesh(vec2(-0.5f, -0.5f), vec2(0.5f, 0.5f), vec4(1.f, 0.5f, 0.5f, 1.f));

    //Scene part
    Camera cam;

    renderer = new Renderer(window, cam, shader);
    renderer->addMesh(&cube);

    renderer->initCamera();
    renderer->init();


    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    while(!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT);

        renderer->render();
        //cube.render(shader);
        //squareMesh.render(shaderProgram);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
  
    glfwTerminate();
    return 0;
}