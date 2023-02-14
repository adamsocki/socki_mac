


#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <assert.h>
#define ASSERT(...) assert(__VA_ARGS__)

#include "types.h"
#include <iostream>

#include "MemoryManagement.h"
#include "dynamic_memory.h"
#include "ui.cpp"

#include "game.h"
#include "game.cpp"


#include "mac_input.cpp"



struct GamePlatform{
    bool running;

    GameMemory gameMem;
};

int main(int argc, char *argv[])
{
    GLFWwindow *window;

    GamePlatform platform = {};
    platform.running = true;

    GameMemory *gameMem = &platform.gameMem;
    memset(gameMem, 0, sizeof(GameMemory));

    Game = gameMem;

    gameMem->startTime = 0.0f;
    gameMem->running = true;

    if (!glfwInit())
    {   // Initialize GLFW
        // Handle error
    }

    window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);
    if (window == NULL)
    {   // Create the window
        // Handle error
        glfwTerminate();
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {   // Initialize GLEW
        // Handle error
    }

    GameInit();


    InputManager *inputManager = &gameMem->inputManager;
    AllocateInputManager(inputManager, &gameMem->permanentArena, 32, 4);
    gameMem->keyboard = &inputManager->devices[0];
    gameMem->mouse = &inputManager->devices[1];

    AllocateInputDevice(gameMem->keyboard, InputDeviceType_Keyboard, Input_KeyboardDiscreteCount, 0);
    AllocateInputDevice(gameMem->mouse, InputDeviceType_Mouse, Input_MouseDiscreteCount, Input_MouseAnalogueCount);

    Keyboard = gameMem->keyboard;
    Mouse = gameMem->mouse;


    while (!glfwWindowShouldClose(window))
    {   // Render loop
        // Poll for events

        glfwPollEvents();

        MacGetInput(inputManager,window);

        GameLoop(gameMem);



        //  Swap buffers
        glfwSwapBuffers(window);

        ClearInputManager(inputManager);
    }

    // Clean up
    CleanUp(window);

    return 0;
}

