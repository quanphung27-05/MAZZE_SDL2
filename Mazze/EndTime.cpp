#include "EndTime.h"


EndTime::EndTime()
{
    
}

EndTime::~EndTime()
{

}


void EndTime::Load(SDL_Renderer*& renderer)
{
    time.loadImage("Assets/img/time.png", renderer, &RED_COLOR);
    
    loadtime.loadImage("Assets/img/loadtime.png", renderer,&WHITE_COLOR);
}

void EndTime::Render(SDL_Renderer*& renderer, const double& ratio)
{
    SDL_Rect dst_rect = { 0, 282, time.getWidth(), time.getHeight() };
    time.render(renderer, nullptr, &dst_rect);
    SDL_Rect src_rect = { 0, 0, int(loadtime.getWidth() *ratio), loadtime.getHeight() };
    dst_rect = { 48, 315, src_rect.w, src_rect.h };
    loadtime.render(renderer, &src_rect, &dst_rect);
    
}