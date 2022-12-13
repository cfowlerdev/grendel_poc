#pragma once
#include <string>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(const std::string &p_title, const int &p_width, const int &p_height);
    ~Window();

    std::string title() const;
    void setTitle(const std::string &p_title);

    int width() const;
    void setWidth(const int &p_width);

    int height() const;
    void setHeight(const int &p_height);

    GLFWwindow *windowId;

private:
    std::string _title;
    int _width;
    int _height;

    static void resizeCallback(GLFWwindow *window, int newWidth, int newHeight);
};
