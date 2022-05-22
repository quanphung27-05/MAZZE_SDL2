#include "GameMap.h"

Tile::Tile()
{
    tilePath = "";
}

Tile::~Tile()
{
}

void Tile::loadTile(SDL_Renderer*& renderer, const std::string& tilePath)
{
    this->tilePath = tilePath;
    loadImage(tilePath, renderer, &WHITE_COLOR);
}

void Tile::renderTile(SDL_Renderer*& renderer, SDL_Rect* dstRect)
{
    render(renderer, nullptr, dstRect);
}

GameMap::GameMap()
{

}

GameMap::~GameMap()
{
    freeMap();
}

void GameMap::freeMap()
{
}

void GameMap::loadMap(SDL_Renderer*& renderer, const std::string& mapPath, BaseObject& MapBackground,std::string path)
{
    BaseObject wall;
	wall.loadImage("Assets/map_lv/" + path, renderer, &WHITE_COLOR);
	wall.render(renderer, nullptr, nullptr);

    std::ifstream readMap(mapPath);
    if (!readMap.is_open()) logSDLError("std::ifstream", true);

    readMap >> map_basic_size;


    fullMap = SDL_CreateTexture(renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_TARGET,
        map_basic_size * TILE_SIZE, map_basic_size * TILE_SIZE);

    //Combine all tile mats into fullMap texture.

    SDL_SetRenderTarget(renderer, fullMap);
    SDL_SetRenderDrawColor(renderer, WHITE_COLOR.r, WHITE_COLOR.g, WHITE_COLOR.b, 255);
    SDL_RenderClear(renderer);

    MapBackground.render(renderer, nullptr, nullptr);

    for (int j = 0; j < map_basic_size; j++)
    {
        for (int i = 0; i < map_basic_size; i++)
        {
            readMap >> basicMap[i][j];
            if (basicMap[i][j] > 0)
            {
                SDL_Rect dstRect = { i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                if (basicMap[i][j] == 1) SDL_RenderCopy(renderer, wall.getTexture(), nullptr, &dstRect);

            }
        }
    }

    SDL_SetRenderTarget(renderer, nullptr);
}

void GameMap::renderMap(SDL_Renderer*& renderer)
{
    SDL_Rect dstRect = { 300 + (SCREEN_WIDTH - map_basic_size * TILE_SIZE - 300) / 2, (SCREEN_HEIGHT - map_basic_size * TILE_SIZE) / 2, TILE_SIZE * map_basic_size, TILE_SIZE * map_basic_size };
    SDL_RenderCopy(renderer, fullMap, nullptr, &dstRect);
}