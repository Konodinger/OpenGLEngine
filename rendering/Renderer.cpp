#include "Renderer.hpp"

void Renderer::initCamera(const vec3 &initialPos) {
    int width, height;
    glfwGetWindowSize(_window, &width, &height);
    _cam.setAspectRatio(static_cast<float>(width)/static_cast<float>(height));

    _cam.setPosition(initialPos);
    _cam.setNear(0.1);
    _cam.setFar(80.1);
}

void Renderer::init() {
    initCamera();
    for (auto &mesh : _meshSet) {
        mesh->init();
    }
}

void Renderer::render() {
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