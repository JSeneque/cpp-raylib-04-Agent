#include "Agent.h"
#include "raymath.h"
#include "IBehaviour.h"

Agent::Agent()
{
    _position = Vector2{0,0};
}

Agent::Agent(Vector2 pos, float radius, Color colour) : 
    _position {pos},
    _radius {radius},
    _colour {colour}
{

}

void Agent::SetPosition(Vector2 pos)
{
    _position = pos;
}

Vector2 Agent::GetPosition()
{
    return _position;
}

void Agent::Update(float deltaTime)
{
    // for each behaviour in the behavious list
    for (auto it = _behaviours.begin(); it != _behaviours.end(); it++)
    {
        (*it)->Update(this, deltaTime);
    }

    _velocity.x += _acceleration.x;
    _velocity.y += _acceleration.y;

    // check if the magitude of the velocity
    if(Vector2Length(_velocity) > _maxSpeed)
    {
        _velocity = Vector2Scale(Vector2Normalize(_velocity), _maxSpeed);
    }

    _position.x += _velocity.x * deltaTime;
    _position.y += _velocity.y * deltaTime;
  
    _acceleration = {0.0f, 0.0f};
}

void Agent::Draw()
{
    // draw the ball of the agent with the position values
    DrawCircleV(_position, _radius, _colour);
}

void Agent::AddBehaviour(IBehaviour* behaviour)
{
    _behaviours.push_back(behaviour);
}



