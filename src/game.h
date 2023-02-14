//
// Created by socki on 2/13/23.
//


#include "input.h"
#ifndef UNTITLED1_GAME_H
#define UNTITLED1_GAME_H

#endif //UNTITLED1_GAME_H



struct GameMemory
{
    bool running;

    real32 systemTime;
    real32 time;
    real32 deltaTime;
    real32 startTime;

    MemoryArena permanentArena;

    InputManager inputManager;

    InputDevice *keyboard;
    InputDevice *mouse;
};

real32 Time = 0;
real32 DeltaTime = 0;


GameMemory *Game = NULL;


InputDevice *Keyboard = NULL;
InputDevice *Mouse = NULL;