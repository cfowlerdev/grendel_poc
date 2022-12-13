#include <iostream>
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "program.h"
#include "shader.h"

// GLFWwindow* window;
Window *window;
unsigned int VBO, VAO, EBO;
Program* defaultShaderProgram;

// Triangle
float triangle_vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

// Rectangle
float vertices[] = {
    0.5f,  0.5f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

// ===========================================
// EMSCRIPTEN MAIN LOOP
// ===========================================
void main_loop()
{

    // ========================
    // RENDER
    // ========================
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);   

    // draw triangle
    defaultShaderProgram->bind();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    

    // Last: swap buffers
    glfwSwapBuffers(window->windowId);
    glfwPollEvents();
}

int main(int argc, char **argv)
{
    std::cout << "Grendel POC" << std::endl;

    // ================================================
    // INIT
    // ================================================
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);   
    glfwWindowHint(GLFW_SAMPLES, 16);    

    // ================================================
    // WINDOW
    // ================================================
    window = new Window("Grendel POC", 800, 600);
    if(window->windowId == NULL)
    {
        std::cout << "ERROR : unable to create window" << std::endl;
        return -1;
    }
    glViewport(0, 0, 800, 600);

    // ================================================
    // SHADERS
    // ================================================
    std::cout << "- Shaders" << std::endl;
    Shader *vertexShader = new Shader("/assets/shaders/vertex.glsl", GL_VERTEX_SHADER);
    Shader *fragmentShader = new Shader("/assets/shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    std::vector<Shader *> defaultShaders;
    defaultShaders.push_back(vertexShader);
    defaultShaders.push_back(fragmentShader);
    defaultShaderProgram = new Program(defaultShaders);

    // ================================================
    // VERTEX DATA
    // ================================================
    std::cout << "- Vertex data" << std::endl;
    
    // Create vertex array and vertex buffer
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    // Bind vertex array object
    glBindVertexArray(VAO);

    // Bind and set vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Index array
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Define how vertex data should be interpreted
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    // ================================================
    // VERTEX ATTRIBUTES
    // ================================================
    std::cout << "- Vertex attributes" << std::endl;

    // Tell OpenGL how to interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);     
    
    // ================================================
    // ENTER RENDER LOOP
    // ================================================
    std::cout << "Entering main loop" << std::endl;
    emscripten_set_main_loop(&main_loop, 0, true);

    glfwTerminate();
    return 0;
}
