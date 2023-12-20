#include "window.hpp"
#include <iostream>

#include "temp_data.hpp"

Window::Window(std::string name = "Window") : Viewport(name) {
    position = ImVec2(0,0);
} 

Window::~Window() {

}

void Window::_process(float delta) {
    std::cout << "test\n";
    Begin("My Window",&active,flags);
    SetWindowSize(size);
    SetWindowPos(position);

    Text("Hello world");
    

    End();
}