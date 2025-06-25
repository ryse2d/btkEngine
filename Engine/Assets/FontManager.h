#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <unordered_map>
#include <string>

using namespace std;

struct FontKey { string path; int size; };
inline bool operator == (const FontKey& a, const FontKey& b) {
	return a.path == b.path && a.size == b.size;
}

struct FontKeyHash {
	size_t operator() (const FontKey& k) const noexcept {
		return hash<string>{}(k.path) ^ (k.size << 1);
	}
};

class FontManager {
public:
	void Init(SDL_Renderer* r) { m_Renderer = r; TTF_Init(); }
	void Shutdown();
	TTF_Font* GetFont(const string& path, int ptSize);
	SDL_Texture* GetTextTexture(const string& txt,
		const string& fontPath, int ptSize, SDL_Color color = { 255,255,255,255 });

private:
	SDL_Renderer* m_Renderer = nullptr;
	unordered_map<FontKey, TTF_Font*, FontKeyHash> m_Fonts;
	unordered_map <string, SDL_Texture*> m_TextCache;
};