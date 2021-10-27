#include "Game.h"
#include "raylib.h"

Game::Game()
{

}

bool Game::Initialise()
{
    SetTargetFPS(60);
    InitWindow(800, 600, "My First Program");
}

void Game::RunLoop()
{
    while (!WindowShouldClose())
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    CloseWindow();
}

void Game::ProcessInput()
{
    _mousePosition = GetMousePosition();
}

void Game::UpdateGame()
{
    _ballPosition = _mousePosition;
}

void Game::GenerateOutput()
{
    BeginDrawing();

    // clears the screen
    ClearBackground(BLACK);

    DrawCircleV(_ballPosition, 20.0f, BLUE);

    EndDrawing();
}