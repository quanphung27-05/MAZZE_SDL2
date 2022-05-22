#pragma once
#include "BaseObject.h"
#include "CommonFunc.h"

class EndTime
{
    BaseObject time;
    BaseObject loadtime;
    BaseObject round;

public:
    EndTime();

    ~EndTime();

    void Load(SDL_Renderer*& renderer);

    void Render(SDL_Renderer*& renderer, const double& ratio);
};
