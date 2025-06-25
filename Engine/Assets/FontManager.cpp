#include "FontManager.h"
#include <iostream>

TTF_Font* FontManager::GetFont(const string& path, int pt) {
	FontKey k{ path ,pt };
	if (auto it = m_Fonts.find(k); it != m_Fonts.end()) return it->second;

	TTF_Font* f = TTF_OpenFont(path.c_str(), pt);
	if (!f) { cerr << "TTF_OpenFont : " << TTF_GetError() << endl; return nullptr; }
	m_Fonts[k] = f;
	return f;
}

SDL_Texture* FontManager::GetTextTexture(const string& txt, const string& fontPath, int pt, SDL_Color col) {
	const string cacheKey = txt + "|" + fontPath + "|" + to_string(pt);
	if (auto it = m_TextCache.find(cacheKey); it != m_TextCache.end())
		return it->second;

	TTF_Font* font = GetFont(fontPath, pt);
	if (!font) return nullptr;

	SDL_Surface* surf = TTF_RenderUTF8_Blended(font, txt.c_str(), col);
	
	SDL_Texture* tex = SDL_CreateTextureFromSurface(m_Renderer, surf);
	SDL_FreeSurface(surf);

	m_TextCache[cacheKey] = tex;
	return tex;
}

void FontManager::Shutdown() {
	for (auto& kv : m_TextCache) SDL_DestroyTexture(kv.second);
	for (auto& kv : m_Fonts) TTF_CloseFont(kv.second);

	m_TextCache.clear();
	m_Fonts.clear();
	TTF_Quit();
}