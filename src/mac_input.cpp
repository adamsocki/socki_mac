

bool keyPressed[1024];

// Mouse button callback
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {


    if (action == GLFW_PRESS)
    {
        InputEvent event = {};

        event.device = Game->keyboard;
        event.discreteValue = true;

        PushBack(&Game->inputManager.events, event);
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {

    }
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        InputEvent event = {};

        event.device = Game->keyboard;
        event.discreteValue = true;

        PushBack(&Game->inputManager.events, event);
        Game->inputManager.keyPressed[key] = true;
    }
    else if (action == GLFW_RELEASE)
    {
        Game->inputManager.keyPressed[key] = false;
    }
}



void MacGetInput(InputManager *input, GLFWwindow *window)
{
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);




    if (Game->inputManager.keyPressed[46])
    {
        std::cout << ". key pressed." << std::endl;
    }
}