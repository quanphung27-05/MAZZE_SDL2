#include "CommonFunc.h"
#include "GameMap.h"
#include "MainObject.h"
#include "ImpTimer.h"
#include "image.h"
#include "music.h"
#include "ImpTimer.h"

const double timeGame = 50000.0;
double ratio = 1;
const int nums_level = 4;
bool checkInside(int x, int y, SDL_Rect r) {
	if (x < r.x || x > r.x + r.w || y < r.y || y > r.y + r.h) return false;
	return true;
}

int main(int argc, char* argv[]) {
	int level = 0;
	ImpTimer fps_imp;
	init_SDL();

	Music sound;
	sound.set_music_path("Assets/sound/2.mp3");
	sound.load_music();

	timebox.Load(renderer);

	StartBackGround.loadImage("Assets/img/start.png", renderer, &WHITE_COLOR);
	Start[0].loadImage("Assets/img/start2.png", renderer);
	Start[1].loadImage("Assets/img/start1.png", renderer);
	WinTexture.loadImage("Assets/img/win.png", renderer, &WHITE_COLOR);
	ExtraBackground.loadImage("Assets/img/ExtraBackground.png", renderer, &WHITE_COLOR);
	Setting[0].loadImage("Assets/img/setting.png", renderer, &WHITE_COLOR);
	Setting[1].loadImage("Assets/img/setting.png", renderer, &WHITE_COLOR);
	Opti.loadImage("Assets/img/opti.png", renderer, &WHITE_COLOR);
	Yes1[0].loadImage("Assets/img/home.png", renderer, &WHITE_COLOR);
	Yes1[1].loadImage("Assets/img/home2.png", renderer, &WHITE_COLOR);
	No1[0].loadImage("Assets/img/continue.png", renderer, &WHITE_COLOR);
	No1[1].loadImage("Assets/img/continue2.png", renderer, &WHITE_COLOR);
	MusicButton[0].loadImage("Assets/img/music.png", renderer, &WHITE_COLOR);
	MusicButton[1].loadImage("Assets/img/music2.png", renderer, &WHITE_COLOR);
	Area.loadImage("Assets/img/area.png", renderer, &WHITE_COLOR);
	Area1[0].loadImage("Assets/img/area1.jpg", renderer, &BLACK_COLOR);
	Area2[0].loadImage("Assets/img/area2.jpeg", renderer, &BLACK_COLOR);
	Area1[1].loadImage("Assets/img/area1.jpg", renderer, &BLACK_COLOR);
	Area2[1].loadImage("Assets/img/area2.jpeg", renderer, &BLACK_COLOR);
	Loose.loadImage("Assets/img/loose.png", renderer, &WHITE_COLOR);
	Back[0].loadImage("Assets/img/back.png", renderer, &WHITE_COLOR);
	Back[1].loadImage("Assets/img/back.png", renderer, &WHITE_COLOR);
	wingame.loadImage("Assets/img/wingame.png", renderer, &WHITE_COLOR);
	MainBackGround.loadImage("Assets/img/map2.jpg", renderer, &WHITE_COLOR);

	ImpTimer playingTimer;
	GameMap map[nums_level];
	MainObject player(renderer);
	player.SetClips();
	SDL_Event e;
	int GAME_STATUS = GET_START_REQUEST;
	bool ingame = true, win = false;
	int frame = 0, framehome = 0, frameplay = 0, framemusic = 0, framearea1 = 0, framearea2 = 0, frameset = 0;
	bool Inside = true;
	int x, y;
	int check = 2, prev_check = 2;
	sound.play_music(10000);


	while (GAME_STATUS != QUIT) {
		while (GAME_STATUS == GET_START_REQUEST) {
			SDL_RenderClear(renderer);
			StartBackGround.render(renderer, nullptr, nullptr);

			if (frame > 1) frame = 0;
			if (frame == 0) Start[frame].render(renderer, nullptr, &StartRect1);
			else if (frame == 1) Start[frame].render(renderer, nullptr, &StartRect2);
			SDL_GetMouseState(&x, &y);

			if (checkInside(x, y, StartRect1) && Inside) {
				if (frame == 0) frame = 1;
				Inside = false;
			}

			if (!checkInside(x, y, StartRect1)) {
				if (frame == 1) frame = 0;
				Inside = true;
			}

			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					GAME_STATUS = QUIT;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&x, &y);
					if (checkInside(x, y, StartRect1)) {
						GAME_STATUS = AREA;

					}
				}
			}
			SDL_RenderPresent(renderer);
		}

		while (GAME_STATUS == AREA) {
			SDL_RenderClear(renderer);
			Area.render(renderer, nullptr, &AreaRect);
			SDL_GetMouseState(&x, &y);

			if (checkInside(x, y, Area1Rect) && Inside) {
				if (framearea1 == 0) framearea1 = 1;
				Inside = false;
			}

			if (!checkInside(x, y, Area1Rect2)) {
				if (framearea1 == 1) framearea1 = 0;
				Inside = true;
			}

			if (framearea1 == 0) Area1[0].render(renderer, nullptr, &Area1Rect);
			if (framearea1 == 1) Area1[1].render(renderer, nullptr, &Area1Rect2);

			if (checkInside(x, y, Area2Rect) && Inside) {
				if (framearea2 == 0) framearea2 = 1;
				Inside = false;
			}

			if (!checkInside(x, y, Area2Rect)) {
				if (framearea2 == 1) framearea2 = 0;
				Inside = true;
			}

			if (framearea2 == 0) Area2[0].render(renderer, nullptr, &Area2Rect);
			if (framearea2 == 1) Area2[1].render(renderer, nullptr, &Area2Rect2);



			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					GAME_STATUS = QUIT;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&x, &y);
					if (checkInside(x, y, Area1Rect)) {
						GAME_STATUS = PLAYING;
						for (int i = 0; i < nums_level; i++) map[i].loadMap(renderer, "Assets/map_lv/" + std::to_string(i + 1) + ".txt", MainBackGround, "wall1.png");
						playingTimer.Start();
						break;
					}
					else if (checkInside(x, y, Area2Rect)) {
						GAME_STATUS = PLAYING;
						MainBackGround.loadImage("Assets/img/background.jpeg", renderer, &WHITE_COLOR);
						for (int i = 0; i < nums_level; i++) map[i].loadMap(renderer, "Assets/map_lv/" + std::to_string(i + 1) + ".txt", MainBackGround, "wall.png");
						playingTimer.Start();
						break;
					}
					
				}
			}
			SDL_RenderPresent(renderer);
		}

		while (GAME_STATUS == PLAYING) {
			
			SDL_RenderClear(renderer);
			playingTimer.Unpaused();

			if (check == 1 && prev_check == 2) {
				sound.pause_music();
				prev_check = 1;
			}
			if (check == 2 && prev_check == 1) {
				sound.play_music(2);
				prev_check == 2;
			}

			SDL_SetRenderDrawColor(renderer, WHITE_COLOR.r, WHITE_COLOR.g, WHITE_COLOR.b, 0);
			ExtraBackground.render(renderer, nullptr, &extraBgRect);
			MainBackGround.render(renderer, nullptr, &mainBgRect);

			Round.loadText("Level: " + std::to_string(level + 1), 150, WHITE_COLOR, "Assets/ttf/VIPRoman-Regular.ttf", renderer);
			Round.render(renderer, nullptr, &Roundrect);
			Round.free();

			SDL_GetMouseState(&x, &y);

			if (checkInside(x, y, SetRect) && Inside) {
				if (frameset == 0) frameset = 1;
				Inside = false;
			}

			if (!checkInside(x, y, SetRect2)) {
				if (frameset == 1) frameset = 0;
				Inside = true;
			}

			if (frameset == 0) Setting[0].render(renderer, nullptr, &SetRect);
			if (frameset == 1) Setting[1].render(renderer, nullptr, &SetRect2);



			map[level].renderMap(renderer);
			timebox.Render(renderer, ratio);
			player.RenderPlayer(renderer, map[level]);

			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					GAME_STATUS = QUIT;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&x, &y);
					if (checkInside(x, y, SetRect)) {
						playingTimer.Paused();
						GAME_STATUS = PAUSE;
						break;
					}
				}
				player.HandleInputAction(map[level], e);

			}

			if (player.GetX() > map[level].getMapSize() - 3 * TILE_SIZE + 4) {
				win = true;
			}

			if (win) {
				GAME_STATUS = WIN;
			}

			win = false;
			ratio = 1 - double(playingTimer.GetTime()) / timeGame;
			if (ratio < 0) {
				GAME_STATUS = LOSE;
			}
			SDL_RenderPresent(renderer);
		}

		while (GAME_STATUS == PAUSE) {

			if (check == 1 && prev_check == 2) {
				sound.pause_music();
				prev_check = 1;
			}
			if (check == 2 && prev_check == 1) {
				sound.play_music(2);
				prev_check == 2;
			}

			Opti.render(renderer, nullptr, &ObtiRect);
			SDL_GetMouseState(&x, &y);

			if (checkInside(x, y, Yes1Rect) && Inside) {
				if (framehome == 0) framehome = 1;
				Inside = false;
			}

			if (!checkInside(x, y, Yes2Rect)) {
				if (framehome == 1) framehome = 0;
				Inside = true;
			}

			if (framehome == 0) Yes1[0].render(renderer, nullptr, &Yes1Rect);
			if (framehome == 1) Yes1[1].render(renderer, nullptr, &Yes2Rect);

			if (checkInside(x, y, No1Rect) && Inside) {
				if (frameplay == 0) frameplay = 1;
				Inside = false;
			}

			if (!checkInside(x, y, No2Rect)) {
				if (frameplay == 1) frameplay = 0;
				Inside = true;
			}

			if (frameplay == 0) No1[0].render(renderer, nullptr, &No1Rect);
			if (frameplay == 1) No1[1].render(renderer, nullptr, &No2Rect);

			if (checkInside(x, y, MusicRect) && Inside) {
				if (framemusic == 0) framemusic = 1;
				Inside = false;
			}

			if (!checkInside(x, y, MusicRect2)) {
				if (framemusic == 1) framemusic = 0;
				Inside = true;
			}

			if (framemusic == 0)  MusicButton[0].render(renderer, nullptr, &MusicRect);
			if (framemusic == 1)  MusicButton[1].render(renderer, nullptr, &MusicRect2);


			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					GAME_STATUS = QUIT;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&x, &y);
					if (checkInside(x, y, Yes1Rect)) {
						GAME_STATUS = GET_START_REQUEST;
						playingTimer.Stop();

					}
					if (checkInside(x, y, No1Rect)) {
						GAME_STATUS = PLAYING;
						break;
						playingTimer.Stop();
					}
					if (checkInside(x, y, MusicRect) && check == 2) {
						check = 1;
					}
					else if (checkInside(x, y, MusicRect) && check == 1) {
						check = 2;
					}
				}
			}
			SDL_RenderPresent(renderer);
		}

		while (GAME_STATUS == LOSE) {
			SDL_RenderClear(renderer);
			Loose.render(renderer, nullptr, &LooseRect);
			Back[0].render(renderer, nullptr, &BackRect);
			while (SDL_PollEvent(&e) != 0) {
				
				if (e.type == SDL_QUIT) {
					GAME_STATUS = QUIT;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&x, &y);
					if (checkInside(x, y, BackRect)) {
						GAME_STATUS = GET_START_REQUEST;
						level = 0;
						player.Reset();
						playingTimer.Stop();
						break;
					}
				}
			}
			SDL_RenderPresent(renderer);
		}
		while (GAME_STATUS == WIN) {
		
			SDL_RenderClear(renderer);
			
			WinTexture.render(renderer, nullptr, &WinTextureRect);

			
			
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					GAME_STATUS = QUIT;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN) {
					SDL_GetMouseState(&x, &y);
					if (checkInside(x, y, NextRect)) {
						level++;

						if (level < nums_level) {
							GAME_STATUS = PLAYING;
							player.Reset();
							break;
						}
					}
					if (checkInside(x, y, PreviousRect)&&level>0) {
						GAME_STATUS = PLAYING;
						level--;
						player.Reset();
					}

				}
				
			
			}
			if (level >= nums_level && GAME_STATUS != PLAYING) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderClear(renderer);
				wingame.render(renderer, nullptr, &wingameRect);
				SDL_RenderPresent(renderer);

				while (SDL_PollEvent(&e) != 0) {
					if (e.type == SDL_QUIT) {
						GAME_STATUS = QUIT;
					}
					break;
				}
			}
		

			playingTimer.Stop();
			playingTimer.Start();
			SDL_RenderPresent(renderer);
		}
		if (GAME_STATUS == QUIT) {
			SDL_Quit();
		}
	}

	return 0;
}




















