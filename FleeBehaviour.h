#pragma once

#include "raylib.h"
#include "IBehaviour.h"
class Agent;

class FleeBehaviour : public IBehaviour
{
public:
    FleeBehaviour(Agent* target);
    ~FleeBehaviour();

    virtual void Update(Agent* agent, float deltaTime);

private:
    Agent* _target;

};