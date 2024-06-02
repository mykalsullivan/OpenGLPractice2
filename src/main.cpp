//
// Created by msullivan on 5/31/24.
//

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Window dimensions
const unsigned int WIDTH = 800, HEIGHT = 600;

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW failed to initialize\n";

        // Unload GLFW memory
        glfwTerminate();
        return 1;
    }

    // Setup GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Core profile = no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

    // Create main window
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Main Window", nullptr, nullptr);

    // Return if the main GLFW window cannot be created
    if (mainWindow == nullptr)
    {
        std::cout << "Could not create main GLFW window\n";
        glfwTerminate();
        return 1;
    }

    // Get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = true;

    // Setup GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Could not initialize GLEW\n";
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // Main loop
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Get/handle user input
        glfwPollEvents();

        // Clear window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap display buffers
        glfwSwapBuffers(mainWindow);
    }

    // Delete main window
    glfwDestroyWindow(mainWindow);

    return 0;
}