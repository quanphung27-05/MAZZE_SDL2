#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

enum game_status_
{
    PLAYING,
    PAUSE,
    QUIT,
    GET_START_REQUEST,
    AREA,
    LOSE,
    WIN,
};
const SDL_Color CYAN_COLOR = { 0, 255, 255 };
const SDL_Color BLUE_COLOR = { 174, 238, 238 };
const SDL_Color ORANGE_COLOR = { 255, 165, 0 };
const SDL_Color YELLOW_COLOR = { 255, 255, 0 };
const SDL_Color LIME_COLOR = { 0, 255, 0 };
const SDL_Color PURPLE_COLOR = { 128, 0, 128 };
const SDL_Color RED_COLOR = { 255, 0, 0 };
const SDL_Color WHITE_COLOR = { 255, 255, 255 };
const SDL_Color BLACK_COLOR = { 0, 0, 0 };
const SDL_Color GREEN_COLOR = { 0, 128, 0 };
const SDL_Color DEFAULT_COLOR = BLACK_COLOR;

//const SDL_Color COLOR_KEY = WHITE_COLOR;

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;

const std::string WINDOW_TITLE = "MAZE PASSING";
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 900;

const int TILE_SIZE = 12;

#define BLANK_TILE 0

inline void logSDLError(std::string error, bool fatal)
{
    std::cout << error << "\nError: " << SDL_GetError();
    if (fatal)
    {
        SDL_Quit();
        exit(1);
    }
}

inline void init_SDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) logSDLError("SDL_INIT", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError("SDL_CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) logSDLError("SDL_CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "Adventure");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (IMG_Init(IMG_INIT_PNG) == 0) logSDLError("IMG_Init", true);

    SDL_Surface* icon = IMG_Load("Assets/img/icon.jpg");
    if (icon == nullptr) logSDLError("IMG_LOAD", false);
    SDL_SetWindowIcon(window, icon);
    if (TTF_Init() != 0) logSDLError("TTF_Init", true);
}
