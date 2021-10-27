#pragma once

#include "raylib.h"
#include "IBehaviour.h"

class Agent;

class FollowMouseBehaviour : public IBehaviour
{
public:
    FollowMouseBehaviour();
    ~FollowMouseBehaviour();

    virtual void Update(Agent* agent, float deltaTime);

private:
    Agent* _target;

};