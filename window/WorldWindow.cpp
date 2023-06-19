#include "WorldWindow.hpp"

WWindow WWindow::WINDOW = WWindow();

int WWindow::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(800, 600, "Engine OpenGL", NULL, NULL);
    if (_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);
    glfwSetKeyCallback(_window, keyCallbackWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader *shader = new Shader("shaders/vertexShader.glsl", "shaders/fragmentShader.glsl"); 

    glViewport(0, 0, 800, 600);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    wireFrameMode = false;

    //Geometry part

    Mesh *cube = new Mesh();
    cube->setColor(vec4(1.f, 0.5f, 0.5f, 1.f));
    cube->becomesCube();
    Mesh *sphere = new Mesh();
    sphere->setColor(vec4(0.5f, 0.4, 0.f, 1.f));
    sphere->becomesSphere(vec3(1.f, 1.f, 1.f), 0.5f, 8);
    //Square squareMesh(vec2(-0.5f, -0.5f), vec2(0.5f, 0.5f), vec4(1.f, 0.5f, 0.5f, 1.f));

    //Scene part
    Camera *cam = new Camera();
    
    _renderer = new Renderer(_window, *cam, *shader);
    _renderer->addMesh(cube);
    _renderer->addMesh(sphere);

    _renderer->initCamera();
    _renderer->init();


    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback); 



    return 0;
}

int WWindow::loop() {
    while(!glfwWindowShouldClose(_window))
    {

        glClear(GL_COLOR_BUFFER_BIT);

        _renderer->render();
        //cube.render(shader);
        //squareMesh.render(shaderProgram);

        glfwPollEvents();
        glfwSwapBuffers(_window);
    }

    return 0;
}

int WWindow::close() {
    glfwTerminate();
    _renderer = nullptr;
    _window = nullptr;
    return 0;
}

void WWindow::switchWireframeMode() {
    wireFrameMode = !wireFrameMode;
    if (wireFrameMode) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

void WWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    WWindow::WINDOW.getRenderer()->getCamera().setAspectRatio(static_cast<float>(width)/static_cast<float>(height));
};