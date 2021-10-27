#include "raylib.h"
#include "Game.h"
int main()
{
    Game game;

    game.Initialise();
    game.RunLoop();
    game.Shutdown();
    
    return 0;
}