#include "Game.h"
#include "raylib.h"

Game::Game()
{

}

bool Game::Initialise()
{
    SetTargetFPS(60);
    InitWindow(800, 600, "Agent Demo");

    player = new Agent({150, 150}, 20.0f, BLUE);

    followMouseBehaviour = new FollowMouseBehaviour();
	player->AddBehaviour(followMouseBehaviour);
	player->_maxSpeed= 100.0f;

    redEnemy = new Agent({760, 20}, 20.0f, RED);
	seekBehaviour = new SeekBehaviour(player);
	redEnemy->AddBehaviour(seekBehaviour);

	shyEnemy = new Agent({400,300}, 20.0f, YELLOW);
	fleeBehaviour = new FleeBehaviour(player);
	shyEnemy->AddBehaviour(fleeBehaviour);
}

void Game::RunLoop()
{
    while (!WindowShouldClose())
    {
        ProcessInput();
        UpdateGame(GetFrameTime());
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    CloseWindow();
}

void Game::ProcessInput()
{
    //_mousePosition = GetMousePosition();
}

void Game::UpdateGame(float deltaTime)
{
    player->Update(deltaTime);
    redEnemy->Update(deltaTime);
    shyEnemy->Update(deltaTime);
}

void Game::GenerateOutput()
{
    BeginDrawing();

    // clears the screen
    ClearBackground(BLACK);

    player->Draw();
    redEnemy->Draw();
    shyEnemy->Draw();

    EndDrawing();
}