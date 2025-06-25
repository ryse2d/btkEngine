#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <unordered_set>

using namespace std;

struct AnimationClip {
	SDL_Texture* tex{};
	vector <SDL_Rect> frames;
	float fps{ 12.f };
};

class AnimatedSprite {
public:
	void SetClip(const AnimationClip* c) { clip = c; frameIdx = 0; time = 0; }
	void Play() { playing = true; }
	void Pause() { playing = false; }
	void Update(float dt);
	void Draw(class RenderQueue& rq, int z);

	float x = 0, y = 0;
private:
	const AnimationClip* clip = nullptr;
	int frameIdx = 0;
	float time = 0;
	bool playing = true;
};

class AnimationSystem {
public:
	void Add(AnimatedSprite* s) { list.insert(s); }
	void Remove(AnimatedSprite* s) { list.erase(s); }
	void Update(float dt) {
		for (auto* s : list) s->Update(dt);
	}
private:
	unordered_set<AnimatedSprite*> list;
};