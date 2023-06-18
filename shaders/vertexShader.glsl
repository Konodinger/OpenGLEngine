#version 330 core

layout (location = 0) in vec3 aPos;
uniform mat4 viewMat, projMat, modelMat;

void main() {
    gl_Position = projMat * viewMat * modelMat * vec4(aPos, 1.0);
}