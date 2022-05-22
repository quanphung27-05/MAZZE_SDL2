#pragma once

#include "CommonFunc.h"
#include "BaseObject.h"
#include "GameMap.h"

#define SPEED 5
#define DEFAULT_PLAYER_HEIGHT 30
#define DEFAULT_PLAYER_WIDTH 25

class MainObject : public BaseObject
{
    int xpos;
    int ypos;
    BaseObject player_texture;
    //xpos, ypos là địa chỉ player trên mê cung

    SDL_Rect frame_clip[4][4];
    int frame;
    int status;

    enum DIRECTION
    {
        DOWN = 0,
        LEFT = 1,
        RIGHT = 2,
        UP = 3
    };

public:
    MainObject(SDL_Renderer*& renderer);
    ~MainObject();

    void RenderPlayer(SDL_Renderer*& renderer, GameMap& map);
    void HandleInputAction(GameMap& map, SDL_Event& e);
    void SetClips();
    void CheckMap(GameMap& map);
    double GetX() { return xpos; };
    void Reset();
};