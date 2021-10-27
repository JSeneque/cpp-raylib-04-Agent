#pragma once

#include "raylib.h"
#include <list>

class IBehaviour;

class Agent{
public:
    float _maxSpeed{50.0f};
    Vector2 _acceleration;
    Vector2 _velocity;

    Agent();
    Agent(Vector2 pos, float radius, Color colour);

    virtual ~Agent() {};

    // update the agent and its behaviours
    virtual void Update(float deltaTime);
    // draw the agent
    virtual void Draw();
    // add a behaviour to the agent
    void AddBehaviour(IBehaviour* behaviour);

    void SetPosition(Vector2 pos);
    Vector2 GetPosition();

private:
    Vector2 _position {0.0f, 0.0f};
    float _radius {5.0f};
    Color _colour {BLUE};

    std::list<IBehaviour*> _behaviours;
};