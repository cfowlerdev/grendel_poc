#include <iostream>
#include "window.h"

Window::Window(const std::string &p_title, const int &p_width, const int &p_height)
    : _title(p_title), _width(p_width), _height(p_height)
{
    windowId = glfwCreateWindow(p_width, p_height, p_title.c_str(), NULL, NULL);

    if(!windowId)
    {
        std::cout << "ERROR : Unable to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(windowId);

    glfwSetWindowSizeCallback(windowId, resizeCallback);

    glClearColor(1.0, 0.0, 0.0, 1.0);
}

Window::~Window()
{
    glfwDestroyWindow(windowId);
}

std::string Window::title() const
{
    return this->_title;
}

void Window::setTitle(const std::string &p_title)
{
    this->_title = p_title;
}

int Window::width() const
{
    return this->_width;
}

void Window::setWidth(const int &p_width)
{
    this->_width = p_width;
}

int Window::height() const
{
    return this->_height;
}

void Window::setHeight(const int &p_height)
{
    this->_height = p_height;
}

void Window::resizeCallback(GLFWwindow* window, int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);  
}
