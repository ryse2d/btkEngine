#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>
#include <string>


using namespace std;

class Game
{
public:
	Game();
	~Game();
	bool Init(const string& title, int width, int height); //baslangic
	void Run(); //game loop
	void Shutdown(); // bitis

	//funcs.
private:
	void ProcessInput();
	void Update(float deltaTime);
	void Render();

	//vars.
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	SDL_Texture* LoadTexture(const string& path);

	//vectors
	struct Vec2 { float x{ 0.f }, y{ 0.f }; };
	SDL_Texture* m_BrickTex = nullptr;
	SDL_Rect m_BrickDst{ 0,0,0,0 };
	Vec2 m_BrickPos{ 100.f,100.f };
	Vec2 m_BrickVel{ 180.f,90.f };

	//Movement / Haraket
	float m_PlayerSpeed = 250.f;
	Vec2 m_InputDir{ 0.f,0.f }; // -1,1 aralık vektörü

	bool m_isRunning = false;
	int m_WindowWidth = 800;
	int m_WindowHeight = 600;

	//F11 ile tam ekran
	bool m_isFullScreen = false;
};