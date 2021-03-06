#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include <SDL.h>
#include <SDL_image.h>
#include "InputHandler.h"

class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void InitialiseCommands();
	void LoadContent();
	void UnloadContent();
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();
private:
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
	SDL_Surface* m_p_Surface;
	InputHandler _inputHandler;
};
#endif