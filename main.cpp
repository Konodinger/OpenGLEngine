#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

#include "WorldWindow.hpp"

int main()
{
    int windowStatus = WWindow::WINDOW.init(); 

    if (windowStatus != 0) {
        cout << "ERROR::WINDOW::INITIALIZATION\n";
        return -1;
    }

    cout << "Endloop\n";
    windowStatus = WWindow::WINDOW.loop();
    if (windowStatus != 0) {
        cout << "ERROR::WINDOW::LOOP\n";
        return -1;
    }

    windowStatus = WWindow::WINDOW.close();
    if (windowStatus != 0) {
        cout << "ERROR::WINDOW::CLOSE\n";
        return -1;
    }

    return 0;
}