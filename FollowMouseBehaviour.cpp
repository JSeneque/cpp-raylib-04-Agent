#include "FollowMouseBehaviour.h"
#include "Agent.h"
#include "raymath.h"

FollowMouseBehaviour::FollowMouseBehaviour()
{

}

FollowMouseBehaviour::~FollowMouseBehaviour()
{

}

void FollowMouseBehaviour::Update(Agent* agent, float deltaTime)
{
    Vector2 mousePosition = GetMousePosition();

    Vector2 direction = Vector2Subtract(mousePosition,agent->GetPosition());
    agent->_acceleration = Vector2Scale(Vector2Normalize(direction), (agent->_maxSpeed* deltaTime));
}