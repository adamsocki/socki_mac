
#include "input.cpp"

#include "my_game.cpp"



void GameInit()
{

    AllocateMemoryArena(&Game->permanentArena, Megabytes(16));
    MyGameInit();

}


void GameLoop(GameMemory *gameMem)
{
    UpdateInput(&Game->inputManager);
    InputManager *input = &gameMem->inputManager;


    MyGameLogicUpdate_Logic();

    MyGameUpdate_Render();




    ClearInputManager(input);

}



void CleanUp(GLFWwindow *window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
}