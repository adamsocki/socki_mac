


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "types.h"
#include <iostream>

#include "game.h"
#include "game_data.h"
#include "game.cpp"
#include "input.h"


struct GamePlatform {
    bool running;
    //WinAudioOutput audio;

    GameMemory gameMem;
};

int main(int argc, char *argv[]) {
    GLFWwindow *window;

    GamePlatform platform = {};
    platform.running = true;

    GameMemory *gameMem = &platform.gameMem;
    memset(gameMem, 0, sizeof(GameMemory));

    Game = gameMem;



    gameMem->startTime = 0.0f;
    gameMem->running = true;

    // Initialize GLFW
    if (!glfwInit())
    {
        // Handle error
    }
    // Create the window
    window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);
    if (window == NULL)
    {
        // Handle error
        glfwTerminate();
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        // Handle error
    }

    GameInit();

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll for events
        glfwPollEvents();

        GameLoop();

        //  Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

