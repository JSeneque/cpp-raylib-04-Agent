#include "SeekBehaviour.h"
#include "Agent.h"
#include "raymath.h"

SeekBehaviour::SeekBehaviour(Agent* target) :
    _target (target)
{

}

SeekBehaviour::~SeekBehaviour()
{

}

void SeekBehaviour::Update(Agent* agent, float deltaTime)
{
    Vector2 direction = Vector2Subtract(_target->GetPosition(),agent->GetPosition());
    agent->_acceleration = Vector2Scale(Vector2Normalize(direction), (agent->_maxSpeed* deltaTime));
}