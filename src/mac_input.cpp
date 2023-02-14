

bool keyPressed[1024];

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods, InputManager *input )
{
    if (action == GLFW_PRESS) {
        Game->inputManager.keyPressed[key] = true;
    } else if (action == GLFW_RELEASE) {
        Game->inputManager.keyPressed[key] = false;
    }
}



void MacGetInput(InputManager *input, GLFWwindow *window)
{
    glfwSetKeyCallback(window, reinterpret_cast<GLFWkeyfun>(key_callback));

    if (Game->inputManager.keyPressed[46])
    {
        std::cout << ". key pressed." << std::endl;
    }
}