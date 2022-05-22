#include "Music.h"

void Music::set_music_path(const std::string& s)
{
	path = s;
}
void Music::load_music()
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024) != 0)
		logSDLError( "opening audio",true);
	mus = Mix_LoadMUS(path.c_str());
	if (mus == nullptr)
		logSDLError( "loading music at " + path,true);
}
void Music::play_music(int loops)
{
	Mix_PlayMusic(mus, loops);
}
void Music::pause_music()
{
	Mix_PauseMusic();
}
