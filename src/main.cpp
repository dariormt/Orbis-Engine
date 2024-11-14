//
// Created by Missing Textures on 14/11/2024.
//

#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader/shaderClass.h"
#include "Shader/VAO.h"
#include "Shader/VBO.h"
#include "Shader/EBO.h"

// Define vertices for a triangle
GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
     0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
     0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
    -0.5f / 2,  0.5f * float(sqrt(3)) / 6, 0.0f,
    0.5f / 2,  0.5f * float(sqrt(3)) / 6, 0.0f,
    0.0f,  -0.5f * float(sqrt(3)) / 3, 0.0f
};

// Define indices for the triangle
GLuint indices[] {
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
};

/**
 * \brief Main function to initialize and run an OpenGL application using GLFW and GLAD.
 *
 * This function initializes the GLFW library, sets up an OpenGL context, creates a window,
 * and enters the main event loop. It also sets the clear color and clears the window once.
 *
 * \return int Returns 0 on successful execution, -1 on failure.
 */
int main(void)
{
    // Initialize the GLFW library
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set the GLFW window context version to 4.6 and profile to core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window with a size of 800x800 and title "OpenGLEngine"
    GLFWwindow* window = glfwCreateWindow(800, 800, "Orbis Engine", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL functions using GLAD
    gladLoadGL();

    // Set the viewport size to match the window size
    glViewport(0, 0, 800, 800);

    // Create and activate the shader program
    Shader shaderProgram("res/Shaders/default.vert", "res/Shaders/default.frag");

    // Generate and bind a Vertex Array Object (VAO)
    VAO VAO1;
    VAO1.Bind();

    // Generate and bind a Vertex Buffer Object (VBO) and upload the vertex data
    VBO VBO1(vertices, sizeof(vertices));

    // Generate and bind an Element Buffer Object (EBO) and upload the index data
    EBO EBO1(indices, sizeof(indices));

    // Link the VBO to the VAO
    VAO1.LinkVBO(VBO1, 0);

    // Unbind the VAO, VBO, and EBO
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // Main event loop
    while (!glfwWindowShouldClose(window))
    {
        // Set the clear color and clear the color buffer
        glClearColor(.06f, .13f, .17f, .0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program and bind the VAO
        shaderProgram.Activate();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Delete the VAO, VBO, EBO, and shader program
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    // Clean up and terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}