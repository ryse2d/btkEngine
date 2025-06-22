#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Sprite {
	SDL_Texture* tex = nullptr;
	SDL_Rect dst{ 0,0,0,0 };
	SDL_Rect src{ 0,0,0,0 };
	int zIndex{ 0 };
};

class RenderQueue {
public:
	void Add(const Sprite& s) { m_Sprites.emplace_back(s); }
	void Clear() { m_Sprites.clear(); }
	void Flush(SDL_Renderer* r) {
		sort(m_Sprites.begin(), m_Sprites.end(),
			[](const Sprite& a, const Sprite& b)
		{
			return a.zIndex < b.zIndex;
		});

		for (const auto& s : m_Sprites)
			SDL_RenderCopy(r, s.tex, (s.src.w ? &s.src : nullptr),
				&s.dst);
		m_Sprites.clear(); //kare bitti
	}
private:
	vector<Sprite> m_Sprites;
};