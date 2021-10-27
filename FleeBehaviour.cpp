#include "FleeBehaviour.h"
#include "Agent.h"
#include "raymath.h"


FleeBehaviour::FleeBehaviour(Agent* target) :
    _target (target)
{

}

FleeBehaviour::~FleeBehaviour()
{

}

void FleeBehaviour::Update(Agent* agent, float deltaTime)
{
    float distance = Vector2Distance(_target->GetPosition(), agent->GetPosition());

    // only flee when the target gets close
    if(distance < 125.0f)
    {
        Vector2 direction = Vector2Subtract(agent->GetPosition(), _target->GetPosition());
        agent->_acceleration = Vector2Scale(Vector2Normalize(direction), (agent->_maxSpeed* deltaTime));
    } 
    else 
    {
        // slow down the agent
        agent->_acceleration.x -= agent->_velocity.x * deltaTime;
        agent->_acceleration.y -= agent->_velocity.y * deltaTime;
    }
}