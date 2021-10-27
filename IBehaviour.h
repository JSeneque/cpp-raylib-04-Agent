#pragma once

#include "raylib.h"

class Agent;

class IBehaviour {
public:
    // empty constructor and destructor for the base class
    IBehaviour() {}
    ~IBehaviour() {}

    // pure virtual function for executing the behaviour
    virtual void Update(Agent* agent, float deltaTime) = 0;

};