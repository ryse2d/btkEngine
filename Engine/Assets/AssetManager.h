#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <unordered_map>
#include <string>

using namespace std;
class AssetManager {
public:
	void Init(SDL_Renderer* r);
	void Shutdown();

	SDL_Texture* GetTexture(const string& key, const string& path="");
	Mix_Chunk* GetSound(const string& logicalName);

	void LoadManifest(const string& jsonPath);

private:
	SDL_Renderer* m_Renderer = nullptr;
	unordered_map<string, SDL_Texture*> m_Tex;
	unordered_map<string, Mix_Chunk*> m_Snd;

};

//Varlık Yönetim Sistemi ve Oyun Sistemlerini Kavrama