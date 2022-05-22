#pragma once

#include "CommonFunc.h"
#include <SDL_mixer.h>
#include <string>

class Music
{
	
	Mix_Music* mus;
	std::string path;
public:
	Music() {

	};
	~Music() {

	};
	void set_music_path(const std::string& s);
	void load_music();
	void play_music(int loops);
	void pause_music();
};

