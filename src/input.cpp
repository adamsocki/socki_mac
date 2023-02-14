




void AllocateInputManager(InputManager *input, MemoryArena *arena, int32 capacity, int32 deviceCapacity) {
    input->events = MakeDynamicArray<InputEvent>(arena, capacity);

    input->deviceCount = deviceCapacity;
    input->devices = (InputDevice *)malloc(sizeof(InputDevice) * deviceCapacity);

    memset(input->devices, 0, input->deviceCount * sizeof(InputDevice));

    input->charSize = 32;
    input->charCount = 0;
    input->inputChars = (char *)malloc(input->charSize);
}

void AllocateInputDevice(InputDevice *device, InputDeviceType type, int32 discreteCount, int32 analogueCount) {
    device->type = type;
    device->discreteCount = discreteCount;

    device->framesHeld = (int32 *)malloc(sizeof(int32) * discreteCount);
    device->released = (bool *)malloc(sizeof(bool) * discreteCount);
    device->pressed = (bool *)malloc(sizeof(bool) * discreteCount);
    device->timePressed = (real32 *)malloc(sizeof(real32) * discreteCount);

    device->analogueCount = analogueCount;
    device->prevAnalogue = (real32 *)malloc(sizeof(real32) * analogueCount);
    device->analogue = (real32 *)malloc(sizeof(real32) * analogueCount);

    memset(device->framesHeld, -1, sizeof(int32) * discreteCount);
    memset(device->pressed, 0, sizeof(bool) * discreteCount);
    memset(device->released, 0, sizeof(bool) * discreteCount);
    memset(device->timePressed, 0, sizeof(real32) * discreteCount);

    memset(device->analogue, 0, sizeof(real32) * analogueCount);
    memset(device->prevAnalogue, 0, sizeof(real32) * analogueCount);
}

// User functions

bool InputPressed(InputDevice *device, int32 inputID) {
    return device->pressed[inputID] && device->framesHeld[inputID] == 0;
}

bool InputReleased(InputDevice *device, int32 inputID) {
    return device->released[inputID];
}

bool InputHeld(InputDevice *device, int32 inputID) {
    return device->framesHeld[inputID] > 0;
}







void UpdateInput(InputManager *input)
{

    if (input->keyPressed[48])
    {
        std::cout << "Escape key pressed." << std::endl;
    }
    for (int d = 0; d < input->deviceCount; d++) {
        InputDevice *device = &input->devices[d];

        if (device->type == InputDeviceType_Invalid) { continue; }

        for (int i = 0; i < device->discreteCount; i++) {
            device->released[i] = false;

            // @NOTE: until we get a release event we consider a key to be pressed
            if (device->framesHeld[i] >= 0) {
                device->framesHeld[i]++;
                device->pressed[i] = false;
            }
        }
    }
}

void ClearInputManager(InputManager *input) {
    DynamicArrayClear(&input->events);

    input->charCount = 0;
    memset(input->inputChars, 0, input->charSize);
}



