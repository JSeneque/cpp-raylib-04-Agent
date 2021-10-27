#include "raylib.h"
#include "Agent.h"
#include "FollowMouseBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"

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
    void UpdateGame(float deltaTime);
    void GenerateOutput();

    Vector2 _mousePosition = { 0.0f, 0.0f };
    Agent* player;
    FollowMouseBehaviour* followMouseBehaviour;

    Agent* redEnemy;
    SeekBehaviour* seekBehaviour;

    Agent* shyEnemy;
    FleeBehaviour* fleeBehaviour;
};