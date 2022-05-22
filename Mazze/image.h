#pragma once
#include "CommonFunc.h"
#include "BaseObject.h"
#include "EndTime.h"
static BaseObject RuleText;
static SDL_Rect RuleTextRect = { 0,0,900,600 };

static BaseObject ExtraBackground;
static SDL_Rect extraBgRect = { 0, 0, 300, 600 };

static BaseObject MainBackGround;
static SDL_Rect mainBgRect = { 300, 0, 600, 600 };

static BaseObject StartBackGround;
static SDL_Rect startBgRect = { 0,0,900,600 };

static BaseObject Start[2];
static SDL_Rect StartRect1 = { 650,273,210,91 };
static SDL_Rect StartRect2 = { 610,256,290,126 };

static BaseObject WinTexture;
static SDL_Rect  WinTextureRect = { 0,0,900,600 };

static BaseObject Next;
static SDL_Rect NextRect = { 465,500,166,70 };

static BaseObject Previous;
static SDL_Rect PreviousRect = { 254,499,166,65 };

static BaseObject Setting[2];
static SDL_Rect SetRect = { 10,10,40,41 };
static SDL_Rect SetRect2 = { 5,5,50,51 };

static BaseObject Opti;
static SDL_Rect ObtiRect = { 300, 0, 600, 600 };

static BaseObject Yes1[2];
static SDL_Rect Yes1Rect = { 320,100,120,118 };
static SDL_Rect Yes2Rect = { 313,88,144,142 };

static BaseObject No1[2];
static SDL_Rect No1Rect = { 500,70,180,183 };
static SDL_Rect No2Rect = { 482,52,216,220 };

static BaseObject MusicButton[2];
static SDL_Rect MusicRect = { 750,100,120,124 };
static SDL_Rect MusicRect2 = { 738,88,144,149 };

static BaseObject Area;
static SDL_Rect AreaRect = { 0,0,900,600 };

static BaseObject Area1[2];
static SDL_Rect Area1Rect = { 100,250,300,81 };
static SDL_Rect Area1Rect2 = { 70,242,360,97 };

static BaseObject Area2[2];
static SDL_Rect Area2Rect = { 500,250,300,81 };
static SDL_Rect Area2Rect2 = { 470,242,360,97 };

static BaseObject Loose;
static SDL_Rect LooseRect = { 0,0,900,600 };

static BaseObject Back[2];
static SDL_Rect BackRect = { 368,425,133,136};

static BaseObject wingame;
static SDL_Rect wingameRect = { 0,47,900,504 };

static BaseObject Round;
static SDL_Rect Roundrect = { 50,200,200,80 };

static EndTime timebox;
