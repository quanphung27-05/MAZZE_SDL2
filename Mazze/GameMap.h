#pragma once
#include "CommonFunc.h"
#include "BaseObject.h"

class Tile : public BaseObject
{
public:
    Tile();
    ~Tile();
    void loadTile(SDL_Renderer*& renderer, const std::string& tilePath);
    void renderTile(SDL_Renderer*& renderer, SDL_Rect* dstRect);
private:
    std::string tilePath;
};


class GameMap
{

    SDL_Texture* fullMap;

    int map_basic_size;



    Tile tileMat[1000];
    int MAX_TILE_TYPES;

public:
    int basicMap[50][50];

    GameMap();
    ~GameMap();

    void freeMap();
    void loadMap(SDL_Renderer*& renderer, const std::string& mapPath, BaseObject& MapBackground,std::string path);
    void renderMap(SDL_Renderer*& renderer);
    void updateMap(SDL_Renderer*& renderer, Tile replacingTile, const int& x, const int& y);

    int getMapSize() { return map_basic_size * TILE_SIZE; }
};