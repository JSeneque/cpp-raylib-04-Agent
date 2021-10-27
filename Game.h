#include "raylib.h"

class Game
{
public:
    Game();
    // initialise the game
    bool Initialise();
    // run the game loop
    void RunLoop();
    // shutdown the game properly
    void Shutdown();

private:
    // helper functions for run the game loop
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    Vector2 _ballPosition = { 0.0f, 0.0f };
    Vector2 _mousePosition = { 0.0f, 0.0f };
};