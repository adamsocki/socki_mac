#include "my_game.cpp"



void GameInit()
{

    MyGameInit();

}


void GameLoop()
{

    MyGameLogicUpdate_Logic();

    MyGameUpdate_Render();

}
