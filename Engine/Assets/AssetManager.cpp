#include "AssetManager.h"
#include <iostream>
#include <filesystem>
#include <string>

using namespace std;

void AssetManager::Init(SDL_Renderer* r) {
	m_Renderer = r;
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

void AssetManager::Shutdown() {
	for (auto& kv : m_Tex) SDL_DestroyTexture(kv.second);
	m_Tex.clear();
	IMG_Quit();
}

SDL_Texture* AssetManager::GetTexture(const string& key, const string& path) {
	// Ön bellek Kontrolü
	if (auto it = m_Tex.find(key); it != m_Tex.end())
		return it->second;

	const string file = path.empty() ? key : path;
	SDL_Surface* surf = IMG_Load(file.c_str());
	if (!surf) {
		cerr << "IMG_Load" << IMG_GetError() << endl;
		return nullptr;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(m_Renderer, surf);
	SDL_FreeSurface(surf);
	if (!tex) { cerr << "CreateTexture:" << SDL_GetError() << endl; return nullptr; }

	m_Tex[key] = tex;
	return tex;
	

}