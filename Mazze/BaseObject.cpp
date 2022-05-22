#include "BaseObject.h"

BaseObject::BaseObject() : object(nullptr)
{
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
}

BaseObject::~BaseObject()
{
    free();
}

void BaseObject::loadImage(const std::string& path, SDL_Renderer*& renderer,const SDL_Color* COLOR_KEY)
{
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if (load_surface == nullptr) logSDLError("IMG_LOAD(" + path + ")\n", true);
    if(COLOR_KEY!=nullptr)
    SDL_SetColorKey(load_surface, SDL_TRUE,
        SDL_MapRGB(load_surface->format, COLOR_KEY->r, COLOR_KEY->g, COLOR_KEY->b));

    object = SDL_CreateTextureFromSurface(renderer, load_surface);
    if (object == nullptr) logSDLError("SDL_CreateTextureFromSurface", false);

    rect.w = load_surface->w;
    rect.h = load_surface->h;

    SDL_FreeSurface(load_surface);
}

void BaseObject::render(SDL_Renderer* renderer, const SDL_Rect* srcrect, const SDL_Rect* dstrect)
{
    SDL_RenderCopy(renderer, object, srcrect, dstrect);
}

void BaseObject::free()
{
    if (object != nullptr)
    {
        SDL_DestroyTexture(object);
        rect.w = 0;
        rect.h = 0;
    }
}
void BaseObject:: loadText(std::string text,int size, SDL_Color color, std::string path, SDL_Renderer*& renderer) {
    if (font == nullptr) {
      
        font = TTF_OpenFont(path.c_str(), size);
        if (font == nullptr) logSDLError("TTF_OpenFont", true);
    }
    
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr)  logSDLError("TTF_RenderText_Solid", true);
    rect.h = surface->h;
    rect.w = surface->w;
    object = SDL_CreateTextureFromSurface(renderer, surface);
    if (object == nullptr)  logSDLError("SDL_CreateTextureFromSurface", true);
    SDL_FreeSurface(surface);
}