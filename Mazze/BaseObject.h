#pragma once

#include "CommonFunc.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();

    void setRect(const int& x, const int& y) { rect.x = x; rect.y = y; }
    SDL_Rect getRect() { return rect; }
    SDL_Texture* getTexture() { return object; }

    void loadImage(const std::string& path, SDL_Renderer*& renderer,const SDL_Color* CORLOR_KEY = nullptr);
    int getWidth() { return rect.w; }
    int getHeight() { return rect.h; }
    void render(SDL_Renderer* renderer, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
    void free();
   
    void loadText(std::string text, int size, SDL_Color color, std::string path, SDL_Renderer*& renderer);
protected:
    TTF_Font* font;
    SDL_Texture* object;
    SDL_Rect rect{};
};