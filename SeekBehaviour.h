#pragma once

#include "raylib.h"
#include "IBehaviour.h"
class Agent;

class SeekBehaviour : public IBehaviour
{
public:
    SeekBehaviour(Agent* target);
    ~SeekBehaviour();

    virtual void Update(Agent* agent, float deltaTime);

private:
    Agent* _target;

};