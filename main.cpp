#include "utils.hpp"
#include "WorldWindow.hpp"

int main()
{
    int windowStatus = WWindow::WINDOW.init(); 

    if (windowStatus != 0) {
        cout << "ERROR::WINDOW::INITIALIZATION\n";
        return -1;
    }

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