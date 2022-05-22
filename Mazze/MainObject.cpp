#include "MainObject.h"
MainObject::MainObject(SDL_Renderer*& renderer)
{
    xpos = 0;
    ypos = 15;

    player_texture.loadImage("Assets/player/player.png", renderer, &WHITE_COLOR);
    object = player_texture.getTexture();
    frame = 0;
    status = RIGHT;
}

MainObject::~MainObject()
{
}

void MainObject::RenderPlayer(SDL_Renderer*& renderer, GameMap& map)
{
    SDL_Rect dst_rect = {
        xpos + 300 + (SCREEN_WIDTH - map.getMapSize() - 300) / 2, ypos + (SCREEN_HEIGHT - map.getMapSize()) / 2,
        DEFAULT_PLAYER_WIDTH, DEFAULT_PLAYER_HEIGHT
    };
    if (frame >= 4) frame = 0;
    render(renderer, &frame_clip[frame][status], &dst_rect);
}

void MainObject::HandleInputAction(GameMap& map, SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            ypos -= SPEED;
            status = UP;
            CheckMap(map);
            frame++;
            break;
        case SDLK_DOWN:
            ypos += SPEED;
            status = DOWN;
            CheckMap(map);
            frame++;
            break;
        case SDLK_LEFT:
            xpos -= SPEED;
            status = LEFT;
            CheckMap(map);
            frame++;
            break;
        case SDLK_RIGHT:
            xpos += SPEED;
            status = RIGHT;
            CheckMap(map);
            frame++;
            break;
        }
    }
    if (e.type == SDL_KEYUP)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            frame = 0;
            status = 3;
            break;
        case SDLK_DOWN:
            frame = 0;
            status = 0;
            break;
        case SDLK_LEFT:
            frame = 0;
            status = 1;
            break;
        case SDLK_RIGHT:
            frame = 0;
            status = 2;
            break;
        }
    }
}

void MainObject::CheckMap(GameMap& map)
{
    if (xpos < 0) xpos = 0;
    if (xpos + DEFAULT_PLAYER_WIDTH > map.getMapSize()) xpos = map.getMapSize() - DEFAULT_PLAYER_WIDTH;
    if (ypos < 0) ypos = 0;
    if (ypos + DEFAULT_PLAYER_HEIGHT > map.getMapSize()) ypos = map.getMapSize() - DEFAULT_PLAYER_HEIGHT;

    if (status == UP)
    {
        if (map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE] != BLANK_TILE ||
            map.basicMap[xpos / TILE_SIZE + 1][ypos / TILE_SIZE] != BLANK_TILE ||
            map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE] != BLANK_TILE)
            ypos = (ypos / TILE_SIZE + 1) * TILE_SIZE;
    }
    if (status == DOWN)
    {
        if (ypos % TILE_SIZE > 6)
        {
            if (map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 3] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 1][ypos / TILE_SIZE + 3] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 3] != BLANK_TILE)
                ypos = (ypos / TILE_SIZE + 3) * TILE_SIZE - 30;
        }
        else
        {
            if (map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 2] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 1][ypos / TILE_SIZE + 2] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 2] != BLANK_TILE)
                ypos = (ypos / TILE_SIZE + 1) * TILE_SIZE;
        }
    }

    if (status == LEFT)
    {
        if (ypos % TILE_SIZE > 6)
        {
            if (map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 1] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 2] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 3] != BLANK_TILE)
                xpos = (xpos / TILE_SIZE + 1) * TILE_SIZE + 1;
        }
        else
        {
            if (map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 1] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE][ypos / TILE_SIZE + 2] != BLANK_TILE)
                xpos = (xpos / TILE_SIZE + 1) * TILE_SIZE + 1;
        }
    }

    if (status == RIGHT)
    {
        if (ypos % TILE_SIZE > 6)
        {
            if (map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 1] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 2] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 3] != BLANK_TILE)
                xpos = (xpos / TILE_SIZE) * TILE_SIZE - 1;
        }
        else
        {
            if (map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 1] != BLANK_TILE ||
                map.basicMap[xpos / TILE_SIZE + 2][ypos / TILE_SIZE + 2] != BLANK_TILE)
                xpos = (xpos / TILE_SIZE) * TILE_SIZE - 1;
        }
    }
}

void MainObject::SetClips()
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            frame_clip[i][j].x = player_texture.getWidth() / 4 * i;
            frame_clip[i][j].y = player_texture.getHeight() / 4 * j;
            frame_clip[i][j].w = player_texture.getWidth() / 4;
            frame_clip[i][j].h = player_texture.getHeight() / 4;
        }
    }
}
void MainObject::Reset() {
    xpos = 0;
    ypos = 15;
}
